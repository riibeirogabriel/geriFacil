#include "adicionarcidade.h"
#include "ui_adicionarcidade.h"

adicionarCidade::adicionarCidade(QWidget *parent) : QWidget(parent),
                                                    ui(new Ui::adicionarCidade)
{
    ui->setupUi(this);
}

adicionarCidade::~adicionarCidade()
{
    delete ui;
}

void adicionarCidade::abre_janela()
{
    ui->in_cidade->clear();
    showMaximized();
}

void adicionarCidade::on_b_voltar_clicked()
{
    hide();
    emit transita_administracao_de_cidades();
}

void adicionarCidade::on_b_salvar_clicked()
{
    DataBase db;
    QString cidade = ui->in_cidade->text();
    ui->in_cidade->setText(cidade);

    QMessageBox msgBox;

    if (cidade == "")
        msgBox.setText("Por favor, digite o nome de uma cidade!");
    else if (db.criaCidade(cidade))
        msgBox.setText("\"" + cidade + "\" foi adicionada a lista de cidades.");
    else
        msgBox.setText("\"" + cidade + "\" já está cadastrada!");

    ui->in_cidade->clear();

    msgBox.exec();
}
