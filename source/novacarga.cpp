#include "novacarga.h"
#include "ui_novacarga.h"
#include "database.h"
#include "qdebug.h"

novaCarga::novaCarga(QWidget *parent) : QWidget(parent),
                                        ui(new Ui::novaCarga)
{
    ui->setupUi(this);
}

novaCarga::~novaCarga()
{
    delete ui;
}

void novaCarga::abre_janela_1()
{
    ui->in_nome_carga->clear();
    showMaximized();
}

void novaCarga::on_b_voltar_clicked()
{
    hide();
    emit transita_clientes_da_carga();
}

void novaCarga::on_b_criar_nova_carga_clicked()
{
    QString nome = ui->in_nome_carga->text();
    DataBase db;
    QMessageBox msg;

    if (nome == "" || nome == " ")
    {
        msg.setText("Por favor, adicione um nome á carga.");
        msg.exec();
        return;
    }
    else if (db.verificaCargaExiste(nome))
    {
        msg.setText("Já existe uma carga com este nome!");
        msg.exec();
        return;
    }
    else if (db.criaCarga(nome))
    {
        msg.setText("Carga adicionada!");
    }
    else
    {
        msg.setText("Erro ao inserir a carga.");
    }
    msg.exec();
    ui->in_nome_carga->clear();
}
