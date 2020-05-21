#include "relatoriocarga.h"
#include "ui_relatoriocarga.h"
#include "database.h"
#include "qsqlquery.h"
#include "qsqlrecord.h"
#include "qdebug.h"
#include "QtPrintSupport/QPrinter"
#include "QtPrintSupport/QPrintDialog"
#include <QPrinter>
#include <QtWidgets>
#include <vector>
using namespace std;

struct produto
{
    int COD;
    QString produto;
    QString unidade;
    int quantidade;
    double custo;
    double venda;
    double total;
    double margem_lucro;

} typedef somaProduto;

vector<QString> relatorioCarga::cidades;
vector<QString> relatorioCarga::clientes;

int relatorioCarga::condicao;

relatorioCarga::relatorioCarga(QWidget *parent) : QWidget(parent),
                                                  ui(new Ui::relatorioCarga)
{
    ui->setupUi(this);
}

relatorioCarga::~relatorioCarga()
{
    for (int i = 0; i < ui->tabela->rowCount(); i++)
        for (int j = 0; j < ui->tabela->columnCount(); j++)
        {
            delete ui->tabela->item(i, j);
        }
    delete ui;
}

QString relatorioCarga::id_carga;

void relatorioCarga::abre_janela()
{
    ui->tabela->horizontalHeader()->setDefaultSectionSize(75);
    ui->tabela->horizontalHeader()->setStretchLastSection(true);
    ui->tabela->setColumnCount(8);
    ui->tabela->setColumnWidth(1, 390);
    ui->tabela->clearContents();
    ui->tabela->setRowCount(0);
    DataBase db;
    double total_tabela_venda = 0;
    double total_tabela_custo = 0;
    ui->in_nome_carga->setText(id_carga);
    QSqlQuery *query = db.coletaLinhasdaTabelaDaCarga(id_carga);

    if (query->next())
    {

        int i;
        int indCOD = query->record().indexOf("COD");
        int indPrecoVenda = query->record().indexOf("preco_venda");
        int indFator = query->record().indexOf("fator");
        int indQuantidade = query->record().indexOf("quantidade");
        int indPagamento = query->record().indexOf("pagamento");
        int indSituacao = query->record().indexOf("situacao");
        int indDescricao = query->record().indexOf("descricao");
        int indPrecoCusto = query->record().indexOf("preco_custo");
        int indCidade = query->record().indexOf("cidade");
        int indCliente = query->record().indexOf("nome_cliente");
        vector<somaProduto *> produtosDacarga;
        int count = 0;
        int situacao = 0, pagamento = 0;

        while (query->next())
        {

            int cod = query->value(indCOD).toInt();
            QString produto = query->value(indDescricao).toString();
            QString unidade = query->value(indQuantidade).toString();
            QString cliente = query->value(indCliente).toString();
            int quantidade = query->value(indFator).toInt();
            double custo = query->value(indPrecoCusto).toDouble();
            double venda = query->value(indPrecoVenda).toDouble();
            double total = custo * quantidade;
            double margem_lucro = venda * quantidade - (custo * quantidade);
            situacao = query->value(indSituacao).toInt();
            pagamento = query->value(indPagamento).toInt();
            QString cidade = query->value(indCidade).toString();
            int cond1, cond2;
            cond1 = cond2 = 0;

            for (auto cidadeSelecionada : cidades)
            {
                if (cidadeSelecionada == cidade)
                    cond1 = 1;
            }

            for (auto clienteSelecionado : clientes)
            {
                if (clienteSelecionado == cliente)
                    cond2 = 1;
            }

            if (!cond2 && !cond1)
                continue;

            total_tabela_venda += venda * quantidade;
            total_tabela_custo += custo * quantidade;
            somaProduto *linha = new somaProduto;
            linha->COD = cod;
            linha->custo = custo;
            linha->venda = venda;
            linha->quantidade = quantidade;
            linha->unidade = unidade;
            linha->produto = produto;
            linha->margem_lucro = margem_lucro;
            linha->total = total;
            int cond = 1;

            for (auto i : produtosDacarga)
            {
                if (i->COD == linha->COD && i->unidade == linha->unidade)
                {
                    cond = 0;
                    i->quantidade += linha->quantidade;
                    i->total += linha->custo * linha->quantidade;
                    i->margem_lucro += (linha->venda * linha->quantidade) - (linha->custo * linha->quantidade);
                    break;
                }
            }
            if (cond)
            {
                produtosDacarga.push_back(linha);
            }
        }

        int l = 0;

        for (auto i : produtosDacarga)
        {
            if (i->quantidade == 0)
                continue;
            l++;
        }

        ui->tabela->setRowCount(l);

        if (produtosDacarga.size() == 0)
            ui->tabela->setRowCount(0);

        i = 0;

        for (auto j : produtosDacarga)
        {
            if (j->quantidade == 0)
                continue;

            count++;
            QTableWidgetItem *newItem = new QTableWidgetItem(QString::number(j->COD));
            ui->tabela->setItem(i, 0, newItem);

            QTableWidgetItem *newItem2 = new QTableWidgetItem(j->produto);
            ui->tabela->setItem(i, 1, newItem2);

            QTableWidgetItem *newItem3 = new QTableWidgetItem(j->unidade);
            ui->tabela->setItem(i, 2, newItem3);

            QTableWidgetItem *newItem4 = new QTableWidgetItem(QString::number(j->quantidade));
            ui->tabela->setItem(i, 3, newItem4);

            QTableWidgetItem *newItem5 = new QTableWidgetItem(QString::number(j->custo));
            ui->tabela->setItem(i, 4, newItem5);

            QTableWidgetItem *newItem6 = new QTableWidgetItem(QString::number(j->venda));
            ui->tabela->setItem(i, 5, newItem6);

            QTableWidgetItem *newItem7 = new QTableWidgetItem(QString::number(j->total));
            ui->tabela->setItem(i, 6, newItem7);

            QTableWidgetItem *newItem8 = new QTableWidgetItem(QString::number(j->margem_lucro));
            ui->tabela->setItem(i++, 7, newItem8);
        }

        ui->in_total->setText(QString::number(total_tabela_venda));
        ui->in_total_custo->setText(QString::number(total_tabela_custo));
        ui->in_margem_luco_rs->setText(QString::number(total_tabela_venda - total_tabela_custo));

        if (total_tabela_custo > 0)
            ui->in_marge_lucro->setText(QString::number(100 / total_tabela_custo * total_tabela_venda - 100));
        else
            ui->in_marge_lucro->setText("0");

        valor_venda = total_tabela_custo;

        if (count)
        {

            int linhaTotal = ui->tabela->rowCount();
            ui->tabela->insertRow(linhaTotal);

            QTableWidgetItem *newItem = new QTableWidgetItem("Total");
            ui->tabela->setItem(linhaTotal, 1, newItem);

            QTableWidgetItem *newItem2 = new QTableWidgetItem(ui->in_total->text());
            ui->tabela->setItem(linhaTotal, 5, newItem2);

            QTableWidgetItem *newItem3 = new QTableWidgetItem(ui->in_margem_luco_rs->text());
            ui->tabela->setItem(linhaTotal, 7, newItem3);

            QTableWidgetItem *newItem4 = new QTableWidgetItem(ui->in_total_custo->text());
            ui->tabela->setItem(linhaTotal, 4, newItem4);
        }
    }
    delete query;
    showMaximized();
}

void relatorioCarga::on_b_voltar_clicked()
{
    clientes.clear();
    cidades.clear();
    hide();
    emit transita_cargas();
}

void relatorioCarga::on_b_definir_cidades_clicked()
{
    condicao = 0;
    hide();
    emit transita_definir_cidades();
}

void relatorioCarga::on_b_imprimir_clicked()
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
        QDate date = QDate::currentDate();
        QString data = date.toString("dd.MM.yy");
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 10));
        painter.drawText(rect(), Qt::AlignLeft, "       \n      Carga : " + id_carga + "\n");
        painter.drawText(rect(), Qt::AlignLeft, "       \n      \n      Data : " + data + " \n");
        painter.begin(printer);
        double xscale = printer->pageRect().width() / double(ui->tabela->width());
        double yscale = printer->pageRect().height() / double(ui->tabela->height());
        double scale = qMin(xscale, yscale);
        painter.translate(printer->paperRect().x() + printer->pageRect().width() / 1.45,
                          printer->paperRect().y() + printer->pageRect().height() / 3.15);
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

    ui->tabela->setFixedSize(originalWidht, originalHeight);
    ui->tabela->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->tabela->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    delete printer;
    delete printDialog;
}

void relatorioCarga::on_pushButton_clicked()
{
    condicao = 1;
    hide();
    emit transita_definir_cidades();
}
