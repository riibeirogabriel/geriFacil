#include "clientesdacarga.h"
#include "ui_clientesdacarga.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QVariant>
#include <QSqlError>
#include <QDebug>
#include "qsqlrecord.h"
#include "database.h"
#include "visualizarpedido.h"
#include <list>
#include "adicionarcliente.h"

using namespace std;

bool contemCliente(list<QString> container, QString x)
{
    for (list<QString>::iterator it = container.begin(); it != container.end(); ++it)
    {
        if (*it == x)
            return true;
    }
    return false;
}

clientesDaCarga::clientesDaCarga(QWidget *parent) : QWidget(parent),
                                                    ui(new Ui::clientesDaCarga)
{
    ui->setupUi(this);
}

clientesDaCarga::~clientesDaCarga()
{
    delete ui;
}

void clientesDaCarga::abre_janela(int var)
{
    ui->in_nome_cliente->clear();
    ui->in_nome_carga->setText(carga);

    if (var != -1)
        janela_que_ativou = var;

    DataBase db;

    if (var == 0)
    {
        cargagRecente = db.maiorNumCarga() - 1;
    }
    else
    {
        cargagRecente = db.coletaIdcarga(carga);
    }

    QSqlQuery *query = db.coletaClientesDaCargaNaTabela(cargagRecente);
    ui->listWidget->clear();
    int fieldNo1 = query->record().indexOf("nome_cliente");
    QString texto;
    list<QString> pool;

    while (query->next())
    {

        texto = query->value(fieldNo1).toString();

        if (!contemCliente(pool, texto))
        {
            pool.push_back(texto);

            ui->listWidget->addItem(texto);
        }
    }
    delete query;
    showMaximized();
}

void clientesDaCarga::on_b_voltar_clicked()
{
    hide();
    if (janela_que_ativou == 0)
        emit transita_fazer_venda();
    else if (janela_que_ativou == 1)
        emit transita_cargas();
}

void clientesDaCarga::on_b_visualizar_pedido_clicked()
{
    if (ui->listWidget->selectedItems().size() == 1)
    {
        DataBase db;
        hide();
        visualizarPedido::cliente = ui->listWidget->currentItem()->text();
        visualizarPedido::id_carga = db.coletaIdcarga(carga);
        emit transita_visualizar_pedido(0);
    }
    else
    {
        QMessageBox msg;
        msg.setText("Por favor,selecione um cliente.");
        msg.exec();
    }
}

void clientesDaCarga::on_b_adicionar_cliente_clicked()
{
    DataBase db;
    hide();
    adicionarCliente::id_carga = db.coletaIdcarga(carga);
    emit transita_adicionar_cliente();
}

QString clientesDaCarga::carga;

void clientesDaCarga::on_b_remover_produto_clicked()
{
    if (ui->listWidget->selectedItems().size() == 1)
    {
        DataBase db;
        QListWidgetItem *item = ui->listWidget->currentItem();
        QString cliente = item->text();

        if (db.removeClienteNaCarga(cliente, cargagRecente))
            abre_janela();
        else
        {
            QMessageBox msg;
            msg.setText("Ocorreu um erro ao remover o cliente.");
            msg.exec();
        }
    }
    else
    {
        QMessageBox msg;
        msg.setText("Por favor,selecione um cliente.");
        msg.exec();
    }
}

void clientesDaCarga::on_in_nome_cliente_textEdited(const QString &arg1)
{
    QString pesquisar = arg1;
    ui->in_nome_cliente->setText(pesquisar);

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
