#include "pagamentopendente.h"
#include "ui_pagamentopendente.h"
#include "database.h"
#include "qsqlquery.h"
#include "qsqlrecord.h"
#include "qdebug.h"
#include "QtPrintSupport/QPrinter"
#include "QtPrintSupport/QPrintDialog"
#include <QPrinter>
#include <QtWidgets>
#include <list>
#include "visualizardebito.h"
using namespace std;

bool contemString(list<QString> container, QString x)
{
    for (list<QString>::iterator it = container.begin(); it != container.end(); ++it)
    {
        if (*it == x)
            return true;
    }
    return false;
}

pagamentoPendente::pagamentoPendente(QWidget *parent) : QWidget(parent),
                                                        ui(new Ui::pagamentoPendente)
{
    ui->setupUi(this);
}

pagamentoPendente::~pagamentoPendente()
{
    delete ui;
}

void pagamentoPendente::abre_janela()
{
    ui->tabela->horizontalHeader()->setDefaultSectionSize(200);
    ui->tabela->horizontalHeader()->setStretchLastSection(true);
    ui->tabela->setColumnCount(2);
    ui->tabela->clearContents();
    ui->tabela->setRowCount(0);
    DataBase db;
    QSqlQuery *iniciarTabela = db.coletaCargasDeClientesPendentes();
    list<QString> sizeTable;
    QString texto;
    int count = 1;

    while (iniciarTabela->next())
    {
        texto = iniciarTabela->value("nome_cliente").toString();

        if (contemString(sizeTable, texto))
            continue;

        sizeTable.push_back(texto);
        ui->tabela->setRowCount(count++);
    }

    ui->in_cliente->clear();
    QSqlQuery *query = db.coletaCargasDeClientesPendentes();
    int fieldNo1 = query->record().indexOf("nome_cliente");
    int fieldNo2 = query->record().indexOf("cidade");
    list<QString> pool;
    int contador = 0;
    QTableWidgetItem *newItem;
    QString nome, cidade;

    while (query->next())
    {
        texto = query->value("nome_cliente").toString();

        if (contemString(pool, texto))
            continue;

        pool.push_back(texto);
        nome = query->value(fieldNo1).toString();
        newItem = new QTableWidgetItem(nome);
        ui->tabela->setItem(contador, 0, newItem);
        cidade = query->value(fieldNo2).toString();
        newItem = new QTableWidgetItem(cidade);
        ui->tabela->setItem(contador++, 1, newItem);
    }
    showMaximized();
}

void pagamentoPendente::on_b_visualizarDebito_clicked()
{

    if (ui->tabela->selectedItems().size() == 1)
    {
        visualizarDebito::nome_cliente = ui->tabela->currentItem()->text();
        hide();
        emit transita_visualizar_debito();
    }
    else
    {
        QMessageBox msg;
        msg.setText("Por favor,Selecione um cliente.");
        msg.exec();
    }
}

void pagamentoPendente::on_b_voltar_clicked()
{
    hide();
    emit voltar_estatisticas();
}

void pagamentoPendente::on_in_cliente_textEdited(const QString &arg1)
{
    QString nomeProcura = arg1;
    DataBase db;

    if (nomeProcura == "")
        abre_janela();

    QSqlQuery *query = db.coletaCargasDeClientesPendentes();
    int fieldNo1 = query->record().indexOf("nome_cliente");
    int fieldNo2 = query->record().indexOf("cidade");
    int i = 0;
    list<QString> pool;

    while (query->next())
    {
        QString cod = query->value(fieldNo1).toString();
        QString descricao = query->value(fieldNo2).toString();

        if (contemString(pool, cod))
            continue;

        pool.push_back(cod);

        if (cod.contains(nomeProcura))
        {
            QTableWidgetItem *newItem = new QTableWidgetItem(cod);
            ui->tabela->setItem(i, 0, newItem);

            QTableWidgetItem *newItem2 = new QTableWidgetItem(descricao);
            ui->tabela->setItem(i++, 1, newItem2);
        }
    }

    ui->tabela->setRowCount(i);
    showMaximized();
}
