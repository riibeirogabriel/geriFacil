#include "fazervenda.h"
#include "ui_fazervenda.h"
#include "database.h"
#include "clientesdacarga.h"

fazerVenda::fazerVenda(QWidget *parent) : QWidget(parent),
                                          ui(new Ui::fazerVenda)
{
    ui->setupUi(this);
}

fazerVenda::~fazerVenda()
{
    delete ui;
}

void fazerVenda::abre_janela()
{
    showMaximized();
}

void fazerVenda::on_b_voltar_clicked()
{
    hide();
    emit transita_tela_principal();
}

void fazerVenda::on_b_venda_na_carga_clicked()
{
    DataBase db;
    QMessageBox msg;

    if (db.maiorNumCarga() == 1)
    {
        msg.setText("Não há cargas cadastradas,por favor,crie uma!");
        msg.exec();
    }
    else
    {
        hide();
        clientesDaCarga::carga = db.coletaNomecarga(db.maiorNumCarga() - 1);
        emit transita_clientes_da_carga(0);
    }
}

void fazerVenda::on_b_venda_fora_da_carga_clicked()
{
    hide();
    emit transita_clientes_fora_da_carga();
}
