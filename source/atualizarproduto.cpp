#include "atualizarproduto.h"
#include "ui_atualizarproduto.h"
#include "database.h"
#include "qsqlquery.h"
#include "qsqlrecord.h"
#include "qdebug.h"

atualizarProduto::atualizarProduto(QWidget *parent) : QWidget(parent),
                                                      ui(new Ui::atualizarProduto)
{
    ui->setupUi(this);
    ui->tabela->setColumnWidth(1, 450);
}

atualizarProduto::~atualizarProduto()
{
    for (int i = 0; i < ui->tabela->rowCount(); i++)
        for (int j = 0; j < ui->tabela->columnCount(); j++)
        {
            delete ui->tabela->item(i, j);
        }
    delete ui;
}

void atualizarProduto::on_b_voltar_clicked()
{
    hide();
    emit transita_administracao_de_produtos();
}

void atualizarProduto::abre_janela()
{

    ui->tabela->clearContents();
    ui->tabela->setRowCount(0);
    ui->in_nome->clear();
    DataBase db;
    QSqlQuery *iniciarTabela = db.coletaProdutos();

    for (int i = 1; iniciarTabela->next(); i++)
        ui->tabela->setRowCount(i);

    QSqlQuery *query = db.coletaProdutos();
    int fieldNo1 = query->record().indexOf("COD");
    int fieldNo2 = query->record().indexOf("descricao");
    int fieldNo3 = query->record().indexOf("quantidade");
    int fieldNo4 = query->record().indexOf("custo");
    int fieldNo5 = query->record().indexOf("venda");

    for (int i = 0; query->next(); i++)
    {
        QString codigo = query->value(fieldNo1).toString();
        QString descricao = query->value(fieldNo2).toString();
        QString quantidade = query->value(fieldNo3).toString();
        QString custo = query->value(fieldNo4).toString();
        QString venda = query->value(fieldNo5).toString();

        QTableWidgetItem *newItem;
        newItem = new QTableWidgetItem(codigo);
        ui->tabela->setItem(i, 0, newItem);

        newItem = new QTableWidgetItem(descricao);
        ui->tabela->setItem(i, 1, newItem);

        newItem = new QTableWidgetItem(quantidade);
        ui->tabela->setItem(i, 2, newItem);

        newItem = new QTableWidgetItem(custo);
        ui->tabela->setItem(i, 3, newItem);

        newItem = new QTableWidgetItem(venda);
        ui->tabela->setItem(i, 4, newItem);
    }

    showMaximized();
}

void atualizarProduto::on_b_salvar_clicked()
{
    QMessageBox msgBox;
    DataBase db;
    QSqlQuery *dadosOriginais = db.coletaProdutos();
    int fieldNo1 = dadosOriginais->record().indexOf("COD");
    int fieldNo3 = dadosOriginais->record().indexOf("quantidade");
    int fieldNo4 = dadosOriginais->record().indexOf("custo");
    int fieldNo5 = dadosOriginais->record().indexOf("venda");
    bool sucesso = true;

    for (int row = 0; row < ui->tabela->rowCount(); row++)
    {
        dadosOriginais->next();
        QString codigoOriginal = dadosOriginais->value(fieldNo1).toString();
        QString quantidadeOriginal = dadosOriginais->value(fieldNo3).toString();
        QString custoOriginal = dadosOriginais->value(fieldNo4).toString();
        QString vendaOriginal = dadosOriginais->value(fieldNo5).toString();
        QString codigo = ui->tabela->item(row, 0)->text();
        QString descricao = ui->tabela->item(row, 1)->text();
        QString quantidade = ui->tabela->item(row, 2)->text();
        QString custo = ui->tabela->item(row, 3)->text();
        QString venda = ui->tabela->item(row, 4)->text();

        if (!db.atualizaProduto(descricao, custo.toDouble(), venda.toDouble(), codigo.toInt(), quantidade))
            sucesso = false;

        if (codigo == codigoOriginal && quantidade == quantidadeOriginal && (custo != custoOriginal || venda != vendaOriginal))
        {
            db.criaHistoricoProduto(codigo.toInt(), "", quantidade, custoOriginal.toDouble(), vendaOriginal.toDouble());
        }
    }
    if (sucesso)
        msgBox.setText("A Lista de Produtos foi atualizada!");
    else
        msgBox.setText("Não foi possível atualizar a Lista de Produtos!");

    msgBox.exec();
    delete dadosOriginais;
    abre_janela();
}

void atualizarProduto::on_in_nome_textEdited(const QString &arg1)
{

    QString pesquisar = arg1;
    ui->in_nome->setText(pesquisar);

    if (pesquisar == "")
    {
        for (int i = 0; i < ui->tabela->rowCount(); i++)
        {
            ui->tabela->showRow(i);
        }
        return;
    }
    for (int i = 0; i < ui->tabela->rowCount(); i++)
    {
        QString codigo = ui->tabela->item(i, 0)->text();
        QString descricao = ui->tabela->item(i, 1)->text();

        if (!(codigo.contains(pesquisar) || descricao.contains(pesquisar)))
            ui->tabela->hideRow(i);
    }
}
