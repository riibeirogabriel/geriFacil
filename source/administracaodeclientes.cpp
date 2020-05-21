#include "administracaodeclientes.h"
#include "ui_administracaodeclientes.h"
#include "qsqlquery.h"
#include "database.h"
#include <cmath>
#include "qdebug.h"
#include "qsqlrecord.h"
#include <QPrinter>
#include "QPrintDialog"
#include "QPainter"

administracaoDeClientes::administracaoDeClientes(QWidget *parent) : QWidget(parent),
                                                                    ui(new Ui::administracaoDeClientes)
{
    ui->setupUi(this);
}

administracaoDeClientes::~administracaoDeClientes()
{
    for (int i = 0; i < ui->tabela->rowCount(); i++)
        for (int j = 0; j < ui->tabela->columnCount(); j++)
        {
            delete ui->tabela->item(i, j);
        }
    delete ui;
}

void administracaoDeClientes::abre_janela()
{
    ui->tabela->clearContents();
    ui->tabela->setRowCount(0);
    ui->in_cliente->clear();
    DataBase db;
    QSqlQuery *iniciarTabela = db.coletaClientes();

    for (int i = 1; iniciarTabela->next(); i++)
        ui->tabela->setRowCount(i);

    ui->in_cliente->clear();
    QSqlQuery *query = db.coletaClientes();
    int fieldNo1 = query->record().indexOf("nome");
    int fieldNo2 = query->record().indexOf("cidade");

    for (int i = 0; query->next(); i++)
    {
        QTableWidgetItem *newItem;
        QString nome = query->value(fieldNo1).toString();
        newItem = new QTableWidgetItem(nome);
        ui->tabela->setItem(i, 0, newItem);
        QString cidade = query->value(fieldNo2).toString();
        newItem = new QTableWidgetItem(cidade);
        ui->tabela->setItem(i, 1, newItem);
    }

    delete query;
    delete iniciarTabela;
    showMaximized();
}

void administracaoDeClientes::on_b_dadosCadastrais_clicked()
{
    QMessageBox msgBox;
    int quantidadeItensSelecionado = ui->tabela->selectedItems().size();

    if (quantidadeItensSelecionado == 1)
    {
        int row = ui->tabela->currentRow();
        QString cliente = ui->tabela->item(row, 0)->text();

        if (cliente == "")
        {
            msgBox.setText("Por favor, selecione um Cliente!");
            msgBox.exec();
        }
        else
        {
            hide();
            emit transita_dados_cadastrais(cliente);
        }
    }
    else
    {
        msgBox.setText("Por favor, selecione um Cliente!");
        msgBox.exec();
    }
}

void administracaoDeClientes::on_b_cadastrarCliente_clicked()
{
    QMessageBox msgBox;
    DataBase db;
    QSqlQuery *coleta = db.coletaCidades();
    bool acessou = false;

    while (coleta->next())
        acessou = true;

    if (acessou)
    {
        hide();
        emit transita_cadastrar_cliente();
    }
    else
    {
        msgBox.setText("Por favor, adicione uma Cidade!\n"
                       "Clique em \"Voltar\" e acesse \"Administração de Cidades\".");
        msgBox.exec();
    }
    delete coleta;
}

void administracaoDeClientes::on_b_voltar_clicked()
{
    hide();
    emit voltar_tela_principal();
}

void administracaoDeClientes::on_b_removerCliente_clicked()
{
    DataBase db;
    QMessageBox msgBox;
    int quantidadeItensSelecionado = ui->tabela->selectedItems().size();

    if (quantidadeItensSelecionado == 1)
    {
        int row = ui->tabela->currentRow();
        QString cliente = ui->tabela->item(row, 0)->text();

        if (cliente == "")
        {
            msgBox.setText("Por favor, selecione um Cliente!");
            msgBox.exec();
        }
        else
        {
            QMessageBox msgBox2;
            msgBox2.setText("Você deseja excluir o cliente \"" + cliente + "\"?");
            QPushButton *botaoSim = msgBox2.addButton(tr("Sim"), QMessageBox::ActionRole);
            QPushButton *botaoNao = msgBox2.addButton(tr("Não"), QMessageBox::ActionRole);
            msgBox2.setDefaultButton(botaoNao);

            msgBox2.exec();
            if (msgBox2.clickedButton() == botaoSim)
            {
                if (db.removeCliente(cliente))
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
        msgBox.setText("Por favor, selecione um Cliente!");
        msgBox.exec();
    }
}

void administracaoDeClientes::on_b_imprimirClientes_clicked()
{
    int originalWidht = ui->tabela->geometry().width();
    int originalHeight = ui->tabela->geometry().height();
    QPrinter *printer = new QPrinter;
    printer->setPageSize(printer->A4);
    printer->setFullPage(true);
    QPrintDialog *printDialog = new QPrintDialog(printer, ui->tabela);

    if (printDialog->exec() == QDialog::Accepted)
    {
        QPainter painter(printer);
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 12));
        painter.drawText(rect(), Qt::AlignLeft, "       \n      Clientes \n");
        painter.begin(printer);
        double xscale = printer->pageRect().width() / double(ui->tabela->width());
        double yscale = printer->pageRect().height() / double(ui->tabela->height());
        double scale = qMin(xscale, yscale);
        painter.translate(printer->paperRect().x() + printer->pageRect().width() / 1.25,
                          printer->paperRect().y() + printer->pageRect().height() / 3);
        painter.scale(scale * 0.7, scale * 0.7);
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

    delete printDialog;
    delete printer;
    ui->tabela->setFixedSize(originalWidht, originalHeight);
    ui->tabela->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->tabela->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
}

void administracaoDeClientes::on_in_cliente_textEdited(const QString &arg1)
{
    QString pesquisar = arg1;
    ui->in_cliente->setText(pesquisar);

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
        QString cliente = ui->tabela->item(i, 0)->text();
        QString cidade = ui->tabela->item(i, 1)->text();

        if (!(cliente.contains(pesquisar) || cidade.contains(pesquisar)))
            ui->tabela->hideRow(i);
    }
}
