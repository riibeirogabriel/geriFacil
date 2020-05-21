#include "dadoscadastrais.h"
#include "ui_dadoscadastrais.h"
#include "database.h"
#include "qsqlrecord.h"
#include "qsqlquery.h"
#include "qdebug.h"

dadosCadastrais::dadosCadastrais(QWidget *parent) : QWidget(parent),
                                                    ui(new Ui::dadosCadastrais)
{
    ui->setupUi(this);
}

dadosCadastrais::~dadosCadastrais()
{
    delete ui;
}

void dadosCadastrais::abre_janela(QString cliente)
{
    DataBase db;
    QSqlQuery *query = db.coletaCidades();
    ui->cb_cidade->clear();

    for (int i = 0; query->next(); i++)
    {
        QString cidade = query->value(0).toString();
        ui->cb_cidade->insertItem(i, cidade);
    }

    query = db.coletaCliente(cliente);
    int fieldNo1 = query->record().indexOf("nome");
    int fieldNo2 = query->record().indexOf("cidade");
    int fieldNo3 = query->record().indexOf("telefone");
    QString nome, telefone, cidade;

    if (query->next())
    {

        cidade = query->value(fieldNo2).toString();
        telefone = query->value(fieldNo3).toString();
        nome = query->value(fieldNo1).toString();
    }

    ui->in_nome->setText(nome);
    ui->in_nome->setReadOnly(1);
    ui->in_telefone->setText(telefone);
    ui->cb_cidade->setCurrentText(cidade);
    delete query;
    showMaximized();
}

void dadosCadastrais::on_b_voltar_clicked()
{
    hide();
    emit voltar_administracao_de_clientes();
}

void dadosCadastrais::on_b_salvar_clicked()
{
    QString nome = ui->in_nome->text();
    QString cidade = ui->cb_cidade->currentText();
    QString telefone = ui->in_telefone->text();
    ui->in_telefone->setText(telefone);
    DataBase db;
    QMessageBox msgBox;

    if (cidade == "")
        msgBox.setText("Por favor, selecione uma cidade!");
    else if (telefone == "")
        msgBox.setText("Por favor, digite o número de telefone do Cliente!");
    else
    {
        if (db.atualizaCliente(nome, telefone, cidade))
            msgBox.setText("\"" + nome + "\" foi atualizado!");
        else
            msgBox.setText("ERRO ao atualizar \"" + nome + "\"!");
    }

    msgBox.exec();
}
