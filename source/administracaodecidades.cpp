
#include "administracaodecidades.h"
#include "ui_administracaodecidades.h"
#include <QSqlQuery>
#include <QList>
#include <qdebug.h>

administracaoDeCidades::administracaoDeCidades(QWidget *parent) : QWidget(parent),
                                                                  ui(new Ui::administracaoDeCidades)
{
    ui->setupUi(this);
}

administracaoDeCidades::~administracaoDeCidades()
{
    delete ui;
}

void administracaoDeCidades::abre_janela()
{
    QString nome;
    showMaximized();
    ui->listWidget->clear();
    DataBase db;
    QSqlQuery *coleta = db.coletaCidades();

    while (coleta->next())
    {
        nome = coleta->value(0).toString();
        ui->listWidget->addItem(nome);
    }
    delete coleta;
}

void administracaoDeCidades::on_b_voltar_clicked()
{
    hide();
    emit transita_tela_principal();
}

void administracaoDeCidades::on_b_adicionar_cidade_clicked()
{
    hide();
    emit transita_adicionar_cidade();
}

void administracaoDeCidades::on_b_remover_cidade_clicked()
{
    DataBase db;
    QMessageBox msgBox;
    int quantidadeItensSelecionado = ui->listWidget->selectedItems().size();

    if (quantidadeItensSelecionado == 1)
    {
        QString nome;
        int row = ui->listWidget->currentRow();
        QString cidade = ui->listWidget->item(row)->text();
        QMessageBox msgBox2;
        msgBox2.setText("Você deseja excluir a cidade \"" + cidade + "\"?");
        QPushButton *botaoSim = msgBox2.addButton(tr("Sim"), QMessageBox::ActionRole);
        QPushButton *botaoNao = msgBox2.addButton(tr("Não"), QMessageBox::ActionRole);
        msgBox2.setDefaultButton(botaoNao);
        msgBox2.exec();

        if (msgBox2.clickedButton() == botaoSim)
        {
            if (db.removeCidade(cidade))
                abre_janela();
            else
            {
                msgBox.setText("ERRO!");
                msgBox.exec();
            }
        }
        else if (msgBox2.clickedButton() == botaoNao)
            return;
    }
    else
    {
        msgBox.setText("Por favor, selecione uma Cidade!");
        msgBox.exec();
    }
}
