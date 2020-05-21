#include "adicionarcliente.h"
#include "ui_adicionarcliente.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QVariant>
#include <QSqlError>
#include <QDebug>
#include "qsqlrecord.h"
#include "database.h"

adicionarCliente::adicionarCliente(QWidget *parent) : QWidget(parent),
                                                      ui(new Ui::adicionarCliente)
{
    ui->setupUi(this);
}

adicionarCliente::~adicionarCliente()
{
    for (int i = 0; i < ui->tabela->rowCount(); i++)
        for (int j = 0; j < ui->tabela->columnCount(); j++)
        {
            delete ui->tabela->item(i, j);
        }
    delete ui;
}

void adicionarCliente::abre_janela()
{
    ui->in_nome->clear();
    ui->tabela->horizontalHeader()->setStretchLastSection(true);
    ui->tabela->clearContents();
    ui->tabela->setRowCount(0);

    DataBase db;
    QSqlQuery *iniciartabela = db.coletaClientes();
    int count = 1;

    while (iniciartabela->next())
        ui->tabela->setRowCount(count++);

    QSqlQuery *query = db.coletaClientes();
    int i;
    int fieldNo1 = query->record().indexOf("nome");
    int fieldNo2 = query->record().indexOf("cidade");
    int fieldNo3 = query->record().indexOf("telefone");

    for (i = 0; query->next(); i++)
    {
        QString cidade = query->value(fieldNo2).toString();
        QString telefone = query->value(fieldNo3).toString();
        QString nome = query->value(fieldNo1).toString();
        QTableWidgetItem *newItem = new QTableWidgetItem(nome);
        ui->tabela->setItem(i, 0, newItem);
        QTableWidgetItem *newItem2 = new QTableWidgetItem(cidade);
        ui->tabela->setItem(i, 1, newItem2);
    }

    delete query;
    delete iniciartabela;
    showMaximized();
}

void adicionarCliente::on_b_voltar_clicked()
{
    hide();
    emit transita_clientes_da_carga();
}

int adicionarCliente::id_carga;

void adicionarCliente::on_b_adicionar_clicked()
{
    QMessageBox box;

    if (ui->tabela->selectedItems().size() == 0)
    {
        box.setText("Por Favor,selecione um cliente.");
        box.exec();
        return;
    }
    else if (ui->tabela->selectedItems().size() > 1)
    {
        box.setText("Você selecionou mais de um cliente,adicione um cliente por vez.");
        box.exec();
        return;
    }

    DataBase db;
    QTableWidgetItem *item = ui->tabela->currentItem();
    QString cliente = item->text();
    int linha = ui->tabela->currentRow();
    QTableWidgetItem *quant = ui->tabela->item(linha, 1);
    QString cidade = quant->text();
    int CargaAtual = db.maiorNumCarga() - 1;
    linha = db.maiorNumLinhaNaTabelaDoCliente(CargaAtual, cliente);

    if (!db.verificaLinhaClienteCargaNaTabela(id_carga, cliente))
    {

        if (db.criaLinhaNaTabela(linha, id_carga, cidade, cliente))
            box.setText("Cliente adicionado á carga!");
        else
            box.setText("Não foi possível adicionar o cliente na carga.");
        box.exec();
    }
    else
    {
        box.setText("Cliente já foi adicionado na carga atual!");
        box.exec();
    }
    on_in_nome_textEdited(ui->in_nome->text());
}

void adicionarCliente::on_in_nome_textEdited(const QString &arg1)
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
        QString cliente = ui->tabela->item(i, 0)->text();
        QString cidade = ui->tabela->item(i, 1)->text();

        if (!(cliente.contains(pesquisar) || cidade.contains(pesquisar)))
            ui->tabela->hideRow(i);
    }
}
