#include "adicionarproduto.h"
#include "ui_adicionarproduto.h"
#include "database.h"
#include "qsqlquery.h"
#include "qsqlrecord.h"
#include "qdebug.h"

adicionarProduto::adicionarProduto(QWidget *parent) : QWidget(parent),
                                                      ui(new Ui::adicionarProduto)
{
    ui->setupUi(this);
    ui->tabela->setColumnWidth(1, 435);
}

adicionarProduto::~adicionarProduto()
{
    for (int i = 0; i < ui->tabela->rowCount(); i++)
        for (int j = 0; j < ui->tabela->columnCount(); j++)
        {
            delete ui->tabela->item(i, j);
        }
    delete ui;
}

void adicionarProduto::abre_janela(int janela)
{
    ui->in_cod->clear();
    ui->tabela->hideColumn(3);
    ui->tabela->horizontalHeader()->setStretchLastSection(true);
    ui->tabela->setColumnCount(6);
    ui->tabela->setColumnWidth(1, 420);
    ui->tabela->clearContents();
    ui->tabela->setRowCount(0);

    //caso estoque abre será 0
    //caso visualizar_pedido abra será 1
    janela_que_abriu = janela;
    ui->in_cod->clear();
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
    int fieldNo6 = query->record().indexOf("fator");

    for (int i = 0; query->next(); i++)
    {
        QTableWidgetItem *newItem;
        QString codigo = query->value(fieldNo1).toString();
        newItem = new QTableWidgetItem(codigo);
        ui->tabela->setItem(i, 0, newItem);
        QString descricao = query->value(fieldNo2).toString();
        newItem = new QTableWidgetItem(descricao);
        ui->tabela->setItem(i, 1, newItem);
        QString quantidade = query->value(fieldNo3).toString();
        newItem = new QTableWidgetItem(quantidade);
        ui->tabela->setItem(i, 2, newItem);
        QString fator = query->value(fieldNo6).toString();
        newItem = new QTableWidgetItem(fator);
        ui->tabela->setItem(i, 3, newItem);
        QString custo = query->value(fieldNo4).toString();
        newItem = new QTableWidgetItem(custo);
        ui->tabela->setItem(i, 4, newItem);
        QString venda = query->value(fieldNo5).toString();
        newItem = new QTableWidgetItem(venda);
        ui->tabela->setItem(i, 5, newItem);
    }

    delete query;
    delete iniciarTabela;
    showMaximized();
}

void adicionarProduto::on_b_voltar_clicked()
{
    hide();
    if (janela_que_abriu == 1)
        emit transita_visualizar_pedido();
    else if (janela_que_abriu == 0)
        emit transita_estoque();
}

void adicionarProduto::on_b_adicionar_clicked()
{
    QMessageBox msgBox;
    DataBase db;

    if (ui->tabela->selectedItems().size() == 0)
    {
        msgBox.setText("Por Favor,selecione um produto.");
        msgBox.exec();
        return;
    }

    QList<QTableWidgetItem *> itens = ui->tabela->selectedItems();
    QSqlQuery *query;

    for (auto item : itens)
    {
        int maiorLinha = db.maiorNumLinhaNaTabelaDoCliente(id_carga, cliente);
        int linhaSelecionada = item->row();
        int cod = ui->tabela->item(linhaSelecionada, 0)->text().toInt();
        QString quantidade = ui->tabela->item(linhaSelecionada, 2)->text();
        QString cidade;
        query = db.coletaCliente(cliente);

        if (query->next())
        {
            int fieldNo1 = query->record().indexOf("cidade");
            cidade = query->value(fieldNo1).toString();
        }

        if (!db.existeProdutoNaTabela(id_carga, cliente, quantidade, cod))
            db.adicionaProdutoNaTabela(maiorLinha, id_carga, cidade, cliente, quantidade, cod, pagamento, situacao);

        delete query;
    }
}

QString adicionarProduto::cliente;
int adicionarProduto::id_carga;
int adicionarProduto::situacao;
int adicionarProduto::pagamento;

void adicionarProduto::on_in_cod_textEdited(const QString &arg1)
{
    QString pesquisar = arg1;
    ui->in_cod->setText(pesquisar);

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
