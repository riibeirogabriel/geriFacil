#include "visualizarcarga.h"
#include "ui_visualizarcarga.h"
#include "database.h"
#include "qsqlquery.h"
#include "qsqlrecord.h"
#include "qdebug.h"
#include "QtPrintSupport/QPrinter"
#include "QtPrintSupport/QPrintDialog"
#include <QPrinter>
#include <QtWidgets>
#include "visualizarcliente.h"

visualizarCarga::visualizarCarga(QWidget *parent) : QWidget(parent),
                                                    ui(new Ui::visualizarCarga)
{
    ui->setupUi(this);
}

visualizarCarga::~visualizarCarga()
{
    for (int i = 0; i < ui->tabela->rowCount(); i++)
        for (int j = 0; j < ui->tabela->columnCount(); j++)
        {
            delete ui->tabela->item(i, j);
        }
    delete ui;
}
void visualizarCarga::abre_janela()
{
    ui->tabela->horizontalHeader()->setStretchLastSection(true);
    ui->tabela->setColumnCount(8);
    ui->tabela->setColumnWidth(1, 370);
    ui->in_nome_carga->setText(visualizarCliente::nome_carga);
    ui->in_nome_cliente->setText(visualizarCliente::nome_cliente);
    ui->tabela->clearContents();
    ui->tabela->setRowCount(0);
    double total_tabela_venda = 0;
    double total_tabela_custo = 0;
    DataBase db;
    QSqlQuery *iniciarTabela = db.coletaLinhasDaTabelaDoCliente(visualizarCliente::nome_cliente, db.coletaIdcarga(visualizarCliente::nome_carga));

    if (iniciarTabela->next())
    {
        for (int i = 1; iniciarTabela->next(); i++)
            ui->tabela->setRowCount(i);
    }

    QSqlQuery *query = db.coletaLinhasDaTabelaDoCliente(visualizarCliente::nome_cliente, db.coletaIdcarga(visualizarCliente::nome_carga));

    if (query->next())
    {

        int i;
        int indCOD = query->record().indexOf("COD");
        int indPrecoVenda = query->record().indexOf("preco_venda");
        int indFator = query->record().indexOf("fator");
        int indQuantidade = query->record().indexOf("quantidade");
        int indPagamento = query->record().indexOf("pagamento");
        int indDescricao = query->record().indexOf("descricao");
        int indPrecoCusto = query->record().indexOf("preco_custo");
        int count = 0;
        int pagamento = 0;

        for (i = 0; query->next(); i++)
        {
            count++;
            int cod = query->value(indCOD).toInt();
            QString produto = query->value(indDescricao).toString();
            QString unidade = query->value(indQuantidade).toString();
            int quantidade = query->value(indFator).toInt();
            double custo = query->value(indPrecoCusto).toDouble();
            double venda = query->value(indPrecoVenda).toDouble();
            double total = venda * quantidade;
            double margem_lucro = total - (custo * quantidade);
            pagamento = query->value(indPagamento).toInt();
            total_tabela_venda += total;
            total_tabela_custo += custo * quantidade;

            QTableWidgetItem *newItem = new QTableWidgetItem(QString::number(cod));
            ui->tabela->setItem(i, 0, newItem);

            QTableWidgetItem *newItem2 = new QTableWidgetItem(produto);
            ui->tabela->setItem(i, 1, newItem2);

            QTableWidgetItem *newItem3 = new QTableWidgetItem(unidade);
            ui->tabela->setItem(i, 2, newItem3);

            QTableWidgetItem *newItem4 = new QTableWidgetItem(QString::number(quantidade));
            ui->tabela->setItem(i, 3, newItem4);

            QTableWidgetItem *newItem5 = new QTableWidgetItem(QString::number(custo));
            ui->tabela->setItem(i, 4, newItem5);

            QTableWidgetItem *newItem6 = new QTableWidgetItem(QString::number(venda));
            ui->tabela->setItem(i, 5, newItem6);

            QTableWidgetItem *newItem7 = new QTableWidgetItem(QString::number(total));
            ui->tabela->setItem(i, 6, newItem7);

            QTableWidgetItem *newItem8 = new QTableWidgetItem(QString::number(margem_lucro));
            ui->tabela->setItem(i, 7, newItem8);
        }

        ui->comboBox_pagamento->setCurrentIndex(pagamento);
        valor_venda = total_tabela_venda;
        ui->in_total->setText(QString::number(total_tabela_venda));
        ui->in_margem_luco_rs->setText(QString::number(total_tabela_venda - total_tabela_custo));
        ui->in_total_custo->setText(QString::number(total_tabela_custo));

        if (total_tabela_custo > 0)
            ui->in_marge_lucro->setText(QString::number(100 / total_tabela_custo * total_tabela_venda - 100));
        else
            ui->in_marge_lucro->setText("0");

        if (count)
        {
            int linhaTotal = ui->tabela->rowCount();
            ui->tabela->insertRow(linhaTotal);

            QTableWidgetItem *newItem = new QTableWidgetItem("Total");
            ui->tabela->setItem(linhaTotal, 1, newItem);

            QTableWidgetItem *newItem2 = new QTableWidgetItem(QString::number(valor_venda));
            ui->tabela->setItem(linhaTotal, 6, newItem2);
        }
    }

    delete iniciarTabela;
    delete query;
    showMaximized();
}

void visualizarCarga::on_b_voltar_clicked()
{
    hide();
    emit voltar_visualizar_cliente();
}

void visualizarCarga::on_b_imprimir_clicked()
{
    int originalWidht = ui->tabela->geometry().width();
    int originalHeight = ui->tabela->geometry().height();
    ui->tabela->hideColumn(4);
    ui->tabela->hideColumn(7);
    QPrinter *printer = new QPrinter;
    printer->setPageSize(printer->A4);
    printer->setFullPage(true);
    QPrintDialog *printDialog = new QPrintDialog(printer, ui->tabela);

    if (printDialog->exec() == QDialog::Accepted)
    {
        QPainter painter(printer);
        QDate date = QDate::currentDate();
        QString data = date.toString("dd.MM.yy");
        DataBase db;
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 10));
        painter.drawText(rect(), Qt::AlignLeft, "       \n      Carga : " + visualizarCliente::nome_carga + "\n");
        painter.drawText(rect(), Qt::AlignLeft, "       \n      \n      Cliente : " + visualizarCliente::nome_cliente + " \n");
        painter.drawText(rect(), Qt::AlignLeft, "       \n      \n      \n      Data : " + data + " \n");
        painter.drawText(rect(), Qt::AlignLeft, "       \n      \n      \n      \n      Pagamento : " + ui->comboBox_pagamento->currentText() + " \n");
        painter.begin(printer);
        double xscale = printer->pageRect().width() / double(ui->tabela->width());
        double yscale = printer->pageRect().height() / double(ui->tabela->height());
        double scale = qMin(xscale, yscale);
        painter.translate(printer->paperRect().x() + printer->pageRect().width() / 1.45,
                          printer->paperRect().y() + printer->pageRect().height() / 3.05);
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
    ui->tabela->showColumn(4);
    ui->tabela->showColumn(7);
    ui->tabela->setFixedSize(originalWidht, originalHeight);
    ui->tabela->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->tabela->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
}
