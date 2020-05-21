#include "cadastrarcliente.h"
#include "ui_cadastrarcliente.h"
#include "database.h"
#include <qsqlquery.h>
#include <qdebug.h>

cadastrarCliente::cadastrarCliente(QWidget *parent) : QWidget(parent),
                                                      ui(new Ui::cadastrarCliente)
{
    ui->setupUi(this);
}

cadastrarCliente::~cadastrarCliente()
{
    delete ui;
}

void cadastrarCliente::abre_janela()
{
    ui->in_nome->clear();
    ui->in_telefone->clear();
    DataBase db;
    QSqlQuery *query = db.coletaCidades();
    ui->cb_cidade->clear();
    ui->cb_cidade->insertItem(0, "");

    for (int i = 1; query->next(); i++)
    {
        QString cidade = query->value(0).toString();
        ui->cb_cidade->insertItem(i, cidade);
    }

    delete query;
    showMaximized();
}

void cadastrarCliente::on_b_voltar_clicked()
{
    hide();
    emit voltar_administracao_de_clientes();
}

void cadastrarCliente::on_b_cadastrar_clicked()
{
    QString nome = ui->in_nome->text();
    ui->in_nome->setText(nome);
    QString cidade = ui->cb_cidade->currentText();
    QString telefone = ui->in_telefone->text();
    ui->in_telefone->setText(telefone);
    DataBase db;
    QMessageBox msgBox;

    if (nome == "")
        msgBox.setText("Por favor, digite o nome do Cliente!");
    else if (cidade == "")
        msgBox.setText("Por favor, selecione uma cidade!");
    else if (telefone == "")
        msgBox.setText("Por favor, digite o número de telefone do Cliente!");
    else
    {
        if (db.criaCliente(cidade, telefone, nome))
        {
            msgBox.setText("\"" + nome + "\" foi adicionado a lista de Cliente!");
            ui->in_nome->clear();
            ui->cb_cidade->setCurrentIndex(0);
            ui->in_telefone->clear();
        }
        else
        {
            msgBox.setText("O Cliente \"" + nome + "\" já está cadastrado!");
            ui->in_nome->clear();
        }
    }

    msgBox.exec();
}

void cadastrarCliente::on_b_limpar_clicked()
{
    QMessageBox msgBox2;
    msgBox2.setText("Você deseja limpar todos os campos?");
    QPushButton *botaoSim = msgBox2.addButton(tr("Sim"), QMessageBox::ActionRole);
    QPushButton *botaoNao = msgBox2.addButton(tr("Não"), QMessageBox::ActionRole);
    msgBox2.setDefaultButton(botaoNao);
    msgBox2.exec();

    if (msgBox2.clickedButton() == botaoSim)
    {
        ui->in_nome->clear();
        ui->cb_cidade->setCurrentIndex(0);
        ui->in_telefone->clear();
    }
    else if (msgBox2.clickedButton() == botaoNao)
        return;
}
