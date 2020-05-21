#include "cargas.h"
#include "ui_cargas.h"
#include "database.h"
#include "qsqlquery.h"
#include "qsqlrecord.h"
#include "qdebug.h"
#include "clientesdacarga.h"
#include "relatoriocarga.h"

Cargas::Cargas(QWidget *parent) : QWidget(parent),
                                  ui(new Ui::Cargas)
{
    ui->setupUi(this);
}

Cargas::~Cargas()
{
    for (int i = 0; i < ui->listWidget->count(); i++)
        delete ui->listWidget->takeItem(i);

    delete ui;
}

void Cargas::on_b_voltar_clicked()
{
    hide();
    emit transita_tela_principal();
}

void Cargas::on_b_clientes_da_carga_clicked()
{

    if (ui->listWidget->selectedItems().size() == 1)
    {
        QListWidgetItem *item = ui->listWidget->currentItem();
        QString cliente = item->text();
        clientesDaCarga::carga = cliente;
        hide();
        emit transita_clientes_da_carga(1);
    }
    else
    {
        QMessageBox msg;
        msg.setText("Por favor,Selecione uma carga.");
        msg.exec();
    }
}

void Cargas::on_b_relatorio_carga_clicked()
{
    if (ui->listWidget->selectedItems().size() == 1)
    {
        DataBase db;
        QListWidgetItem *item = ui->listWidget->currentItem();
        QString cliente = item->text();
        relatorioCarga::id_carga = cliente;
        hide();
        emit transita_relatorio_carga();
    }
    else
    {
        QMessageBox msg;
        msg.setText("Por favor,Selecione uma carga.");
        msg.exec();
    }
}

void Cargas::on_b_nova_carga_clicked()
{
    hide();
    emit transita_nova_carga();
}
void Cargas::abre_janela()
{
    DataBase db;
    ui->listWidget->selectedItems().clear();
    ui->listWidget->clear();
    ui->listWidget->setSortingEnabled(1);
    ui->in_nome->clear();
    QSqlQuery *query = db.coletaCargas();
    int fieldNo4 = query->record().indexOf("nome");
    int fieldNo5 = query->record().indexOf("id");

    while (query->next())
    {
        QString nome = query->value(fieldNo4).toString();
        int id = query->value(fieldNo5).toInt();
        QListWidgetItem *newItem = new QListWidgetItem;
        newItem->setText(nome);
        ui->listWidget->insertItem(id, newItem);
    }

    delete query;
    Qt::SortOrder order;
    ui->listWidget->sortItems(order = Qt::AscendingOrder);
    showMaximized();
}

void Cargas::on_in_nome_textEdited(const QString &arg1)
{
    QString pesquisar = arg1;
    ui->in_nome->setText(pesquisar);

    if (pesquisar == "")
    {
        for (int i = 0; i < ui->listWidget->count(); i++)
        {
            ui->listWidget->item(i)->setHidden(false);
        }
        return;
    }
    for (int i = 0; i < ui->listWidget->count(); i++)
    {
        QString termo = ui->listWidget->item(i)->text();
        if (!(termo.contains(pesquisar)))
            ui->listWidget->item(i)->setHidden(true);
    }
}
