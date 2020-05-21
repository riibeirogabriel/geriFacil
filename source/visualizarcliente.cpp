#include "visualizarcliente.h"
#include "ui_visualizarcliente.h"
#include "database.h"
#include "qsqlquery.h"
#include "qsqlrecord.h"
#include "qdebug.h"
#include "QtPrintSupport/QPrinter"
#include "QtPrintSupport/QPrintDialog"
#include <QPrinter>
#include <QtWidgets>
#include <vector>
#include <list>
using namespace std;

visualizarCliente::visualizarCliente(QWidget *parent) : QWidget(parent),
                                                        ui(new Ui::visualizarCliente)
{
    ui->setupUi(this);
}

visualizarCliente::~visualizarCliente()
{
    delete ui;
}

void visualizarCliente::abre_janela()
{
    ui->in_nome_cliente->setText(nome_cliente);
    DataBase db;
    QSqlQuery *query = db.coletaCargasCliente(nome_cliente);
    ui->lista->clear();
    int fieldNo1 = query->record().indexOf("id_carga");
    int texto;
    list<int> pool;

    while (query->next())
    {
        int cond = 1;
        texto = query->value(fieldNo1).toInt();

        for (auto i : pool)
            if (texto == i)
                cond = 0;

        if (cond)
        {
            pool.push_back(texto);
            ui->lista->addItem(db.coletaNomecarga(texto));
        }
    }

    delete query;
    showMaximized();
}

QString visualizarCliente::nome_cliente;
QString visualizarCliente::nome_carga;

void visualizarCliente::on_b_visualizarCarga_clicked()
{
    if (ui->lista->selectedItems().size() == 1)
    {
        nome_carga = ui->lista->currentItem()->text();
        hide();
        emit transita_visualizar_carga();
    }
    else
    {
        QMessageBox msg;
        msg.setText("Por favor,selecione uma carga.");
        msg.exec();
    }
}

void visualizarCliente::on_b_voltar_clicked()
{
    hide();
    emit voltar_estatisticas();
}
