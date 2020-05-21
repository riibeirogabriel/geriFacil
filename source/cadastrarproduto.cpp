#include "cadastrarproduto.h"
#include "ui_cadastrarproduto.h"
#include "database.h"
#include "qsqlquery.h"
#include "qsqlrecord.h"
#include "qdebug.h"

cadastrarProduto::cadastrarProduto(QWidget *parent) : QWidget(parent),
                                                      ui(new Ui::cadastrarProduto)
{
    ui->setupUi(this);
}

cadastrarProduto::~cadastrarProduto()
{
    delete ui;
}

void cadastrarProduto::abre_janela()
{
    ui->in_COD->clear();
    ui->in_custo->clear();
    ui->in_venda->clear();
    ui->in_descricao->clear();
    showMaximized();
}

void cadastrarProduto::on_b_voltar_clicked()
{
    hide();
    emit transita_administracao_de_produtos();
}

void cadastrarProduto::on_b_adicionar_clicked()
{
    QMessageBox msgBox;
    DataBase db;
    QString codigo = ui->in_COD->text();
    ui->in_COD->setText(codigo);
    QString descricao = ui->in_descricao->text();
    QString quantidade = ui->cb_unidade->currentText();
    QString custo = ui->in_custo->text();
    custo.replace(QChar(','), QChar('.'));
    ui->in_custo->setText(custo);
    QString venda = ui->in_venda->text();
    venda.replace(QChar(','), QChar('.'));
    ui->in_venda->setText(venda);

    if (codigo == "")
        msgBox.setText("Por favor, digite o código do Produto!");
    else if (descricao == "")
        msgBox.setText("Por favor, digite uma descrição para o Produto!");
    else if (quantidade == "")
        msgBox.setText("Por favor, selecione uma quantidade!");
    else if (custo == "")
        msgBox.setText("Por favor, digite o custo do Produto!");
    else if (venda == "")
        msgBox.setText("Por favor, digite o valor de venda do Produto!");
    else if (custo.toDouble() > venda.toDouble() - 0.00001)
        msgBox.setText("O custo deve ser menor do que o valor de venda!");
    else
    {
        if (db.criaProduto(codigo.toInt(), descricao, quantidade, custo.toDouble(), venda.toDouble()))
        {
            msgBox.setText("O Produto \"" + descricao + "\" foi adicionado a lista de Produtos!");
            ui->in_COD->clear();
            ui->in_descricao->clear();
            ui->cb_unidade->setCurrentIndex(0);
            ui->in_custo->clear();
            ui->in_venda->clear();
        }
        else
        {
            msgBox.setText("Já há um produto com código \"" + codigo + "\" e quantidade \"" + quantidade + "\" cadastrado!");
            ui->in_COD->clear();
        }
    }

    msgBox.exec();
}

void cadastrarProduto::on_b_limpar_clicked()
{
    QMessageBox msgBox2;
    msgBox2.setText("Você deseja limpar todos os campos?");
    QPushButton *botaoSim = msgBox2.addButton(tr("Sim"), QMessageBox::ActionRole);
    QPushButton *botaoNao = msgBox2.addButton(tr("Não"), QMessageBox::ActionRole);
    msgBox2.setDefaultButton(botaoNao);
    msgBox2.exec();

    if (msgBox2.clickedButton() == botaoSim)
    {
        ui->in_COD->clear();
        ui->in_descricao->clear();
        ui->cb_unidade->setCurrentIndex(0);
        ui->in_custo->clear();
        ui->in_venda->clear();
    }
    else if (msgBox2.clickedButton() == botaoNao)
        return;
}
