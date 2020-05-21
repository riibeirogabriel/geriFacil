#include "definircidades.h"
#include "ui_definircidades.h"
#include "database.h"
#include "qsqlquery.h"
#include "qsqlrecord.h"
#include "qdebug.h"
#include "QtPrintSupport/QPrinter"
#include "QtPrintSupport/QPrintDialog"
#include <QPrinter>
#include <QtWidgets>
#include "relatoriocarga.h"

definirCidades::definirCidades(QWidget *parent) : QWidget(parent),
                                                  ui(new Ui::definirCidades)
{
    ui->setupUi(this);
}

bool contemCliente2(list<QString> container, QString x)
{
    for (list<QString>::iterator it = container.begin(); it != container.end(); ++it)
    {
        if (*it == x)
            return true;
    }
    return false;
}

definirCidades::~definirCidades()
{
    delete ui;
}

void definirCidades::abre_janela()
{
    ui->listWidget->setSelectionMode(QAbstractItemView::MultiSelection);
    ui->listWidget->clear();
    showMaximized();

    if (relatorioCarga::condicao == 0)
    {

        QString nomeCidade;
        DataBase db;
        QSqlQuery *coleta = db.coletaCidades();

        while (coleta->next())
        {
            nomeCidade = coleta->value(0).toString();
            ui->listWidget->addItem(nomeCidade);
        }
        delete coleta;
    }
    else
    {

        DataBase db;
        QSqlQuery *query = db.coletaClientesDaCargaNaTabela(db.coletaIdcarga(relatorioCarga::id_carga));
        ui->listWidget->clear();
        int fieldNo1 = query->record().indexOf("nome_cliente");
        QString texto;
        list<QString> pool;

        while (query->next())
        {
            texto = query->value(fieldNo1).toString();

            if (!contemCliente2(pool, texto))
            {
                pool.push_back(texto);
                ui->listWidget->addItem(texto);
            }
        }
    }
}

void definirCidades::on_b_voltar_clicked()
{
    hide();
    emit transita_relatorio_carga();
}

void definirCidades::on_b_selecionar_todas_as_cidades_clicked()
{
    for (int contador = 0; contador < ui->listWidget->count(); contador++)
    {
        ui->listWidget->setItemSelected(ui->listWidget->item(contador), true);
    }
}

void definirCidades::on_b_limpar_clicked()
{
    for (int contador = 0; contador < ui->listWidget->count(); contador++)
    {
        ui->listWidget->setItemSelected(ui->listWidget->item(contador), false);
    }
}

void definirCidades::on_b_salvae_clicked()
{
    if (relatorioCarga::condicao == 0)
    {
        relatorioCarga::cidades.clear();
        QList<QListWidgetItem *> itemsDaLista = ui->listWidget->selectedItems();

        for (auto item : itemsDaLista)
        {
            relatorioCarga::cidades.push_back(item->text());
        }
    }
    else
    {
        relatorioCarga::clientes.clear();
        QList<QListWidgetItem *> itemsDaLista = ui->listWidget->selectedItems();

        for (auto item : itemsDaLista)
        {
            relatorioCarga::clientes.push_back(item->text());
        }
    }
}
