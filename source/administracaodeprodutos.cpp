#include "administracaodeprodutos.h"
#include "ui_administracaodeprodutos.h"
#include "database.h"
#include "qsqlquery.h"
#include "qsqlrecord.h"
#include "qdebug.h"
#include "QtPrintSupport/QPrinter"
#include "QtPrintSupport/QPrintDialog"
#include <QPrinter>
#include <QtWidgets>

administracaoDeProdutos::administracaoDeProdutos(QWidget *parent) : QWidget(parent),
                                                                    ui(new Ui::administracaoDeProdutos)
{
    ui->setupUi(this);
    ui->tabela->setColumnWidth(1, 450);
}

administracaoDeProdutos::~administracaoDeProdutos()
{
    for (int i = 0; i < ui->tabela->rowCount(); i++)
        for (int j = 0; j < ui->tabela->columnCount(); j++)
        {
            delete ui->tabela->item(i, j);
        }
    delete ui;
}

void administracaoDeProdutos::abre_janela()
{
    ui->tabela->horizontalHeader()->setStretchLastSection(true);
    ui->tabela->setColumnCount(5);
    ui->tabela->setColumnWidth(1, 430);
    ui->tabela->clearContents();
    ui->tabela->setRowCount(0);
    DataBase db;
    QSqlQuery *iniciarTabela = db.coletaProdutos();

    for (int i = 1; iniciarTabela->next(); i++)
        ui->tabela->setRowCount(i);

    QSqlQuery *query = db.coletaProdutos();
    int i;
    int fieldNo1 = query->record().indexOf("COD");
    int fieldNo2 = query->record().indexOf("descricao");
    int fieldNo3 = query->record().indexOf("quantidade");
    int fieldNo4 = query->record().indexOf("custo");
    int fieldNo5 = query->record().indexOf("venda");
    int count = 0;

    for (i = 0; query->next(); i++)
    {
        count++;
        QString cod = query->value(fieldNo1).toString();
        QString descricao = query->value(fieldNo2).toString();
        QString quantidade = query->value(fieldNo3).toString();
        QString custo = query->value(fieldNo4).toString();
        QString venda = query->value(fieldNo5).toString();

        QTableWidgetItem *newItem = new QTableWidgetItem(cod);
        ui->tabela->setItem(i, 0, newItem);

        QTableWidgetItem *newItem2 = new QTableWidgetItem(descricao);
        ui->tabela->setItem(i, 1, newItem2);

        QTableWidgetItem *newItem3 = new QTableWidgetItem(quantidade);
        ui->tabela->setItem(i, 2, newItem3);

        QTableWidgetItem *newItem4 = new QTableWidgetItem(custo);
        ui->tabela->setItem(i, 3, newItem4);

        QTableWidgetItem *newItem5 = new QTableWidgetItem(venda);
        ui->tabela->setItem(i, 4, newItem5);
    }

    delete query;
    delete iniciarTabela;
    showMaximized();
}

void administracaoDeProdutos::on_b_voltar_clicked()
{
    hide();
    emit transita_tela_principal();
}

void administracaoDeProdutos::on_b_cadastrar_produto_clicked()
{
    hide();
    emit transita_cadastrar_produto();
}

void administracaoDeProdutos::on_b_atualizar_produto_clicked()
{
    QMessageBox msgBox;
    DataBase db;
    QSqlQuery *query = db.coletaProdutos();
    int acessou = false;

    for (int i = 0; query->next(); i++)
        acessou = true;

    if (acessou)
    {
        hide();
        emit transita_atualizar_produto();
    }
    else
    {
        msgBox.setText("Não existe Produtos cadastrados!");
        msgBox.exec();
    }
    delete query;
}

void administracaoDeProdutos::on_b_remover_produto_clicked()
{
    DataBase db;
    QMessageBox msgBox;
    int quantidadeItensSelecionado = ui->tabela->selectedItems().size();

    if (quantidadeItensSelecionado == 1)
    {
        int row = ui->tabela->currentRow();
        QString codigo = ui->tabela->item(row, 0)->text();
        QString quantidade = ui->tabela->item(row, 2)->text();
        QString nome = ui->tabela->item(row, 1)->text();
        if (codigo == "" && quantidade == "")
        {
            msgBox.setText("Por favor, selecione um Produto!");
            msgBox.exec();
        }
        else
        {
            QMessageBox msgBox2;
            msgBox2.setText("Você deseja excluir o produto \"" + nome + "\"?");
            QPushButton *botaoSim = msgBox2.addButton(tr("Sim"), QMessageBox::ActionRole);
            QPushButton *botaoNao = msgBox2.addButton(tr("Não"), QMessageBox::ActionRole);
            msgBox2.setDefaultButton(botaoNao);

            msgBox2.exec();
            if (msgBox2.clickedButton() == botaoSim)
            {
                if (db.removeProduto(quantidade, codigo.toInt()))
                    abre_janela();
                else
                {
                    msgBox.setText("ERRO!");
                    msgBox.exec();
                }
            }
            else if (msgBox2.clickedButton() == botaoNao)
                return;
        }
    }
    else
    {
        msgBox.setText("Por favor, selecione um Produto!");
        msgBox.exec();
    }
}

void administracaoDeProdutos::on_b_imprimir_clicked()
{
    int originalWidht = ui->tabela->geometry().width();
    int originalHeight = ui->tabela->geometry().height();
    ui->tabela->hideColumn(3);
    QPrinter *printer = new QPrinter;
    printer->setPageSize(printer->A4);
    printer->setFullPage(true);
    QPrintDialog *printDialog = new QPrintDialog(printer, ui->tabela);

    if (printDialog->exec() == QDialog::Accepted)
    {
        QPainter painter(printer);
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 10));
        painter.drawText(rect(), Qt::AlignLeft, "       \n      Produtos \n");
        painter.begin(printer);
        double xscale = printer->pageRect().width() / double(ui->tabela->width());
        double yscale = printer->pageRect().height() / double(ui->tabela->height());
        double scale = qMin(xscale, yscale);
        painter.translate(printer->paperRect().x() + printer->pageRect().width() / 1.45,
                          printer->paperRect().y() + printer->pageRect().height() / 3.3);
        painter.scale(scale * 0.85, scale * 0.85);
        painter.translate(-width() / 2, -height() / 2);
        int width = 20;
        int columns = ui->tabela->columnCount();

        for (int i = 0; i < columns; ++i)
        {
            width += ui->tabela->columnWidth(i);
        }

        int height = ui->tabela->rowHeight(0) * (ui->tabela->rowCount() + 1);
        ui->tabela->setFixedSize(width, height);
        ui->tabela->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->tabela->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        QPixmap pm = QPixmap::grabWidget(ui->tabela);
        int offset = pm.height();

        while (offset >= 1350)
        {
            painter.drawPixmap(0, 0, pm.copy(0, pm.rect().bottom() - offset, pm.width(), 1350));
            printer->newPage();
            offset -= 1350;
        }

        pm = pm.copy(0, pm.rect().bottom() - offset, pm.width(), offset);
        painter.drawPixmap(0, 0, pm);
    }

    delete printer;
    delete printDialog;
    ui->tabela->showColumn(3);
    ui->tabela->setFixedSize(originalWidht, originalHeight);
    ui->tabela->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->tabela->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
}

void administracaoDeProdutos::on_in_nome_textEdited(const QString &arg1)
{
    QString pesquisar = arg1;
    ui->in_nome->setText(pesquisar);

    if (pesquisar == "")
    {
        for (int i = 0; i < ui->tabela->rowCount(); i++)
        {
            ui->tabela->showRow(i);
        }
        return;
    }
    for (int i = 0; i < ui->tabela->rowCount(); i++)
    {
        QString codigo = ui->tabela->item(i, 0)->text();
        QString descricao = ui->tabela->item(i, 1)->text();

        if (!(codigo.contains(pesquisar) || descricao.contains(pesquisar)))
            ui->tabela->hideRow(i);
    }
}

void administracaoDeProdutos::on_pushButton_clicked()
{
    QMessageBox msg;
    if (ui->tabela->selectedItems().size() != 1)
    {
        msg.setText("Por favor,selecione um produto");
        msg.exec();
        return;
    }

    int row = ui->tabela->currentRow();
    QString codigo = ui->tabela->item(row, 0)->text();
    QString quantidade = ui->tabela->item(row, 2)->text();
    DataBase db;
    QSqlQuery *historico = db.coletaHistoricoProduto(quantidade, codigo.toInt());
    QString txt = "";
    int fieldNo4 = historico->record().indexOf("custo");
    int fieldNo5 = historico->record().indexOf("venda");
    int cond = 0;

    while (historico->next())
    {
        cond = 1;
        QString custo = historico->value(fieldNo4).toString();
        QString venda = historico->value(fieldNo5).toString();
        txt += "Custo : " + custo + " | Venda: " + venda + "\n";
    }

    delete historico;

    if (!cond)
    {
        msg.setText("Não existe histórico de preços para o produto selecionado");
        msg.exec();
        return;
    }
    else
    {
        msg.setText(txt);
        msg.exec();
    }
}
