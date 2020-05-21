#include "estatisticas.h"
#include "ui_estatisticas.h"
#include "database.h"
#include "qsqlquery.h"
#include "qsqlrecord.h"
#include "qdebug.h"
#include "QtPrintSupport/QPrinter"
#include "QtPrintSupport/QPrintDialog"
#include <QPrinter>
#include <QtWidgets>
#include "relatoriocarga.h"
#include "visualizarcliente.h"

estatisticas::estatisticas(QWidget *parent) : QWidget(parent),
                                              ui(new Ui::estatisticas)
{
    ui->setupUi(this);
}

estatisticas::~estatisticas()
{
    for (int i = 0; i < ui->tabela->rowCount(); i++)
        for (int j = 0; j < ui->tabela->columnCount(); j++)
        {
            delete ui->tabela->item(i, j);
        }
    delete ui;
}

void estatisticas::abre_janela()
{
    ui->in_cliente->clear();
    ui->tabela->clearContents();
    ui->tabela->setRowCount(0);
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

void estatisticas::on_b_visualizarCliente_clicked()
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
            visualizarCliente::nome_cliente = cliente;
            emit transita_visualizar_cliente();
        }
    }
    else
    {
        msgBox.setText("Por favor, selecione um Cliente!");
        msgBox.exec();
    }
}

void estatisticas::on_b_voltar_clicked()
{
    hide();
    emit voltar_tela_principal();
}

void estatisticas::on_b_pagamentosPendete_clicked()
{
    hide();
    emit transita_pagamento_pendente();
}

void estatisticas::on_in_cliente_textEdited(const QString &arg1)
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
