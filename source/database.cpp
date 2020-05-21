#include "database.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QVariant>
#include <QSqlError>
#include <QDebug>
#include "qsqlrecord.h"

DataBase::DataBase()
{
}

DataBase::DataBase(const DataBase &rhs)
{
    sqlDatabase = rhs.sqlDatabase;
}

DataBase &DataBase::operator=(const DataBase &rhs)
{
    if (&rhs == this)
    {
        return *this;
    }
    sqlDatabase = rhs.sqlDatabase;
    return *this;
}

DataBase::~DataBase() {}

void DataBase::closeDatabase()
{
    QSqlDatabase sqlDatabase;
    sqlDatabase.close();
}

void DataBase::setupDatabase()
{
    QSqlDatabase sqlDatabase;
    sqlDatabase = QSqlDatabase::addDatabase("QSQLITE");
    sqlDatabase.setDatabaseName("transtuff.sqlite");
    sqlDatabase.open();
    QSqlQuery query;

    query.exec("CREATE TABLE IF NOT EXISTS tabela ("
               "COD         INT,"
               "descricao   VARCHAR(100),"
               "preco_custo DOUBLE,"
               "preco_venda DOUBLE,"
               "quantidade  VARCHAR(5),"
               "fator INT,"
               "linha   INT,"
               "pagamento   INT,"
               "situacao    INT,"
               "id_carga       INT,"
               "nome_cliente    VARCHAR(50),"
               "cidade      VARCHAR(50))");

    query.exec("CREATE TABLE IF NOT EXISTS  cidade ("
               "nome    VARCHAR(50))");

    query.exec("CREATE TABLE IF NOT EXISTS clientes ("
               "cidade  VARCHAR(50),"
               "telefone VARCHAR(15),"
               "nome    VARCHAR(50))");

    query.exec("CREATE TABLE IF NOT EXISTS produtos ("
               "COD INT,"
               "descricao VARCHAR(100),"
               "quantidade VARCHAR(5),"
               "custo   DOUBLE,"
               "venda   DOUBLE,"
               "fator   INT)");

    query.exec("CREATE TABLE IF NOT EXISTS historico_precos ("
               "COD INT,"
               "descricao VARCHAR(100),"
               "quantidade VARCHAR(5),"
               "custo   DOUBLE,"
               "venda   DOUBLE,"
               "fator   INT)");

    query.exec("CREATE TABLE IF NOT EXISTS  cargas ("
               "nome    VARCHAR(50),"
               "id      INT)");

    query.finish();
}

QSqlQuery *DataBase::coletaCargas()
{
    QSqlQuery *query = new QSqlQuery("SELECT * FROM cargas");
    return query;
}

QSqlQuery *DataBase::coletaLinhasDaTabelaDoCliente(QString cliente, int id_carga)
{
    QSqlQuery *query = new QSqlQuery;
    query->prepare("SELECT * FROM tabela WHERE id_carga = :name AND nome_cliente = :cliente ");
    query->bindValue(":name", id_carga);
    query->bindValue(":cliente", cliente);

    if (query->exec())
        return query;
    else
        return NULL;
}

int DataBase::coletaIdcarga(QString id)
{
    QSqlQuery *query = new QSqlQuery;
    query->prepare("SELECT id FROM cargas WHERE nome = :name ");
    query->bindValue(":name", id);
    query->exec();

    if (query->next())
    {
        return query->value(0).toInt();
    }
    else
    {
        return -1;
    }
}

QSqlQuery *DataBase::coletaCargasCliente(QString nome_cliente)
{
    QSqlQuery *query = new QSqlQuery;
    query->prepare("SELECT id_carga FROM tabela WHERE nome_cliente = :nome");
    query->bindValue(":nome", nome_cliente);

    if (query->exec())
        return query;
    else
    {
        return NULL;
    }
}

QSqlQuery *DataBase::coletaLinhasdaTabelaDaCarga(QString carga)
{
    QSqlQuery *query = new QSqlQuery;
    query->prepare("SELECT * FROM tabela WHERE id_carga = :name");
    query->bindValue(":name", coletaIdcarga(carga));

    if (query->exec())
        return query;
    else
    {
        return NULL;
    }
}

QSqlQuery *DataBase::coletaCargasDeClientesPendentes()
{
    QSqlQuery *query = new QSqlQuery;
    query->prepare("SELECT * FROM tabela WHERE situacao = :situ ");
    query->bindValue(":situ", 1);

    if (query->exec())
    {
        return query;
    }
    else
    {
        return NULL;
    }
}

QSqlQuery *DataBase::coletaClientesDaCargaNaTabela(int carga)
{
    QSqlQuery *query = new QSqlQuery;
    query->prepare("SELECT * FROM tabela WHERE id_carga = :name ");
    query->bindValue(":name", carga);

    if (query->exec())
    {
        return query;
    }
    else
    {
        return NULL;
    }
}

QString DataBase::coletaNomecarga(int id)
{
    QSqlQuery *query = new QSqlQuery;
    query->prepare("SELECT nome FROM cargas WHERE id = :id ");
    query->bindValue(":id", id);
    query->exec();

    if (query->next())
    {
        return query->value(0).toString();
    }
    else
    {
        return "";
    }
}

int DataBase::maiorNumCarga()
{
    QSqlQuery *query = new QSqlQuery("SELECT * FROM cargas");
    int maior = 0;
    int fieldNo1 = query->record().indexOf("id");
    int res = 0;

    while (query->next())
    {
        maior = query->value(fieldNo1).toInt();
        if (maior > res)
            res = maior;
    }
    return res + 1;
}

int DataBase::maiorNumLinhaNaTabelaDoCliente(int idCarga, QString nomeCliente)
{
    QSqlQuery *query = new QSqlQuery;
    query->prepare("SELECT * FROM tabela WHERE id_carga = :carga AND nome_cliente = :cliente");
    query->bindValue(":carga", idCarga);
    query->bindValue(":cliente", nomeCliente);
    query->exec();
    int maior = 0;
    int fieldNo1 = query->record().indexOf("linha");
    int res = 0;

    while (query->next())
    {

        maior = query->value(fieldNo1).toInt();

        if (maior > res)
            res = maior;
    }
    return res + 1;
}

bool DataBase::verificaCargaExiste(QString carga)
{

    QSqlQuery query;
    query.prepare("SELECT nome FROM cargas WHERE nome = :name");
    query.bindValue(":name", carga);

    if (query.exec())
        if (query.next())
            return true;
    query.finish();

    return false;
}

bool DataBase::criaCarga(QString carga)
{
    QSqlQuery insert;
    insert.prepare("INSERT INTO cargas (nome,id) VALUES (?,?)");
    insert.addBindValue(carga);
    insert.addBindValue(maiorNumCarga());
    bool b = insert.exec();
    insert.finish();
    return b;
}

bool DataBase::verificaCidadeExiste(QString cidade)
{
    QSqlQuery query;
    query.prepare("SELECT nome FROM cidade WHERE nome = :name");
    query.bindValue(":name", cidade);

    if (query.exec())
        if (query.next())
            return true;

    query.finish();
    return false;
}

bool DataBase::verificaClienteExiste(QString cliente)
{
    QSqlQuery query;
    query.prepare("SELECT nome FROM clientes WHERE nome = :name");
    query.bindValue(":name", cliente);

    if (query.exec())
        if (query.next())
            return true;

    query.finish();
    return false;
}

bool DataBase::verificaProdutoExiste(QString cod)
{
    QSqlQuery query;
    query.prepare("SELECT cod FROM produtos WHERE cod = :name");
    query.bindValue(":name", cod);

    if (query.exec())
        if (query.next())
            return true;

    query.finish();
    return false;
}

bool DataBase::verificaLinhaClienteCargaNaTabela(int id_carga, QString cliente)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM tabela WHERE id_carga = :carga AND nome_cliente = :cliente");
    query.bindValue(":carga", id_carga);
    query.bindValue(":cliente", cliente);
    query.exec();
    return query.next();
}

bool DataBase::criaLinhaNaTabela(int linha, int carga, QString cidade, QString id_cliente)
{

    QSqlQuery insert;
    insert.prepare("INSERT INTO tabela (COD,descricao,preco_venda,linha,pagamento,situacao,id_carga,nome_cliente,cidade,fator,quantidade,preco_custo) "
                   "VALUES (?,?,?,?,?,?,?,?,?,?,?,?)");

    insert.addBindValue(0);
    insert.addBindValue("");
    insert.addBindValue(0);
    insert.addBindValue(linha);
    insert.addBindValue(0);
    insert.addBindValue(0);
    insert.addBindValue(carga);
    insert.addBindValue(id_cliente);
    insert.addBindValue(cidade);
    insert.addBindValue(0);
    insert.addBindValue("");
    insert.addBindValue(0);

    bool b = insert.exec();
    insert.finish();
    return b;
}

bool DataBase::adicionaProdutoNaTabela(int linha, int carga, QString cidade, QString id_cliente, QString quantidade, int codProduto, int pagamento, int situacao)
{

    QSqlQuery *prod = coletaProduto(quantidade, codProduto);
    QString descricao;
    double custo, venda;

    if (prod->next())
    {
        int fieldNo2 = prod->record().indexOf("descricao");
        int fieldNo4 = prod->record().indexOf("custo");
        int fieldNo5 = prod->record().indexOf("venda");
        descricao = prod->value(fieldNo2).toString();
        custo = prod->value(fieldNo4).toDouble();
        venda = prod->value(fieldNo5).toDouble();
    }
    else
    {
        return false;
    }

    QSqlQuery insert;
    insert.prepare("INSERT INTO tabela (COD,descricao,preco_venda,linha,pagamento,situacao,id_carga,nome_cliente,cidade,fator,quantidade,preco_custo) "
                   "VALUES (?,?,?,?,?,?,?,?,?,?,?,?)");

    insert.addBindValue(codProduto);
    insert.addBindValue(descricao);
    insert.addBindValue(venda);
    insert.addBindValue(linha);
    insert.addBindValue(pagamento);
    insert.addBindValue(situacao);
    insert.addBindValue(carga);
    insert.addBindValue(id_cliente);
    insert.addBindValue(cidade);
    insert.addBindValue(0);
    insert.addBindValue(quantidade);
    insert.addBindValue(custo);

    bool b = insert.exec();
    insert.finish();
    return b;
}

bool DataBase::atualizaProdutoNaTabela(int carga, QString id_cliente, QString quantidade, int codProduto, double venda, int pagamento, int situacao, int fator)
{

    QSqlQuery insert;
    insert.prepare("UPDATE tabela SET preco_venda = ? ,pagamento = ? ,situacao = ? ,fator = ? WHERE id_carga = ? AND nome_cliente = ? AND COD = ? AND quantidade = ?");
    insert.addBindValue(venda);
    insert.addBindValue(pagamento);
    insert.addBindValue(situacao);
    insert.addBindValue(fator);
    insert.addBindValue(carga);
    insert.addBindValue(id_cliente);
    insert.addBindValue(codProduto);
    insert.addBindValue(quantidade);

    bool b = insert.exec();
    insert.finish();
    return b;
}

bool DataBase::criaCidade(QString cidade)
{
    if (coletaCidade(cidade)->next())
        return false;

    QSqlQuery insert;
    insert.prepare("INSERT INTO cidade (nome) "
                   "VALUES (:nome)");
    insert.bindValue(":nome", cidade);
    bool b = insert.exec();
    insert.finish();
    return b;
}

bool DataBase::criaCliente(QString cidade, QString telefone, QString nome)
{
    if (coletaCliente(nome)->next())
        return false;

    QSqlQuery insert;
    insert.prepare("INSERT INTO clientes (nome,telefone,cidade) "
                   "VALUES (:nome,:tel,:city)");
    insert.bindValue(":nome", nome);
    insert.bindValue(":tel", telefone);
    insert.bindValue(":city", cidade);
    bool b = insert.exec();
    insert.finish();
    return b;
}

bool DataBase::criaProduto(int cod, QString nome, QString quantidade, double custo, double venda)
{
    if (DataBase::existeProdutoNaTabelaProduto(cod, quantidade))
        return false;

    QSqlQuery insert;
    insert.prepare("INSERT INTO produtos (COD,descricao,quantidade,custo,venda,fator) "
                   "VALUES (?,?,?,?,?,?)");
    insert.addBindValue(cod);
    insert.addBindValue(nome);
    insert.addBindValue(quantidade);
    insert.addBindValue(custo);
    insert.addBindValue(venda);
    insert.addBindValue(0);
    bool b = insert.exec();
    insert.finish();
    return b;
}

bool DataBase::criaHistoricoProduto(int cod, QString nome, QString quantidade, double custo, double venda)
{
    QSqlQuery insert;
    insert.prepare("INSERT INTO historico_precos (COD,descricao,quantidade,custo,venda,fator) "
                   "VALUES (?,?,?,?,?,?)");
    insert.addBindValue(cod);
    insert.addBindValue(nome);
    insert.addBindValue(quantidade);
    insert.addBindValue(custo);
    insert.addBindValue(venda);
    insert.addBindValue(0);
    bool b = insert.exec();
    insert.finish();
    return b;
}

QSqlQuery *DataBase::coletaHistoricoProduto(QString quant, int cod)
{
    QSqlQuery *query = new QSqlQuery;
    query->prepare("SELECT * FROM historico_precos WHERE COD = :cod AND quantidade = :quant");
    query->bindValue(":cod", cod);
    query->bindValue(":quant", quant);

    if (query->exec())
    {
        return query;
    }
    else
    {

        return NULL;
    }
}

QSqlQuery *DataBase::coletaCidades()
{

    QSqlQuery *query = new QSqlQuery("SELECT * FROM cidade");
    return query;
}

QSqlQuery *DataBase::coletaClientes()
{
    QSqlQuery *query = new QSqlQuery("SELECT * FROM clientes");
    return query;
}

QSqlQuery *DataBase::coletaProdutos()
{
    QSqlQuery *query = new QSqlQuery("SELECT * FROM produtos");
    return query;
}

QSqlQuery *DataBase::coletaProduto(QString quant, int cod)
{
    QSqlQuery *query = new QSqlQuery;
    query->prepare("SELECT * FROM produtos WHERE COD = :cod AND quantidade = :quant");
    query->bindValue(":cod", cod);
    query->bindValue(":quant", quant);

    if (query->exec())
        return query;
    else
        return NULL;
}

QSqlQuery *DataBase::coletaLinhaDaTabela(int linha, int id_cliente)
{
    QSqlQuery *coleta = new QSqlQuery;
    coleta->prepare("SELECT * FROM tabela WHERE linha = (:linha) AND id_cliente = (:id)");
    coleta->bindValue(":linha", linha);
    coleta->bindValue(":id", id_cliente);

    if (!coleta->exec())
    {
        delete coleta;
        return NULL;
    }

    coleta->next();
    return coleta;
}

QSqlQuery *DataBase::coletaCidade(QString nome)
{
    QSqlQuery *coleta = new QSqlQuery;
    coleta->prepare("SELECT * FROM cidade WHERE nome = (:linha)");
    coleta->bindValue(":linha", nome);

    if (!coleta->exec())
    {
        delete coleta;
        return NULL;
    }

    return coleta;
}

QSqlQuery *DataBase::coletaCliente(QString nome)
{
    QSqlQuery *coleta = new QSqlQuery;
    coleta->prepare("SELECT * FROM clientes WHERE nome = (:linha)");
    coleta->bindValue(":linha", nome);
    coleta->exec();
    return coleta;
}

QSqlQuery *DataBase::coletaCidade(int cod)
{
    QSqlQuery *coleta = new QSqlQuery;
    coleta->prepare("SELECT * FROM produtos WHERE cod = (:linha)");
    coleta->bindValue(":linha", cod);

    if (!coleta->exec())
    {
        delete coleta;
        return NULL;
    }

    coleta->next();
    return coleta;
}

bool DataBase::atualizaLinhaNaTabela(int linha, QString carga, QString cidade, int id_cliente, int COD, QString nome, QString unidade, QString quantidade, double preco_custo, double preco_venda, QString pagamento, QString situacao)
{
    QSqlQuery insert;
    insert.prepare("INSERT INTO tabela (linha, carga, cidade, id_cliente,COD,nome,unidade,quantidade,preco_custo,preco_venda,pagamento,situacao) "
                   "VALUES (:linha, :carga, :city, :id, :COD, :nome, :unidade, :quantidade, :preco_custo, :preco_venda, :pagamento, :situacao)");
    insert.bindValue(":linha", linha);
    insert.bindValue(":carga", carga);
    insert.bindValue(":city", cidade);
    insert.bindValue(":id", id_cliente);
    insert.bindValue(":COD", COD);
    insert.bindValue(":nome", nome);
    insert.bindValue(":unidade", unidade);
    insert.bindValue(":quantidade", quantidade);
    insert.bindValue(":preco_custo", preco_custo);
    insert.bindValue(":preco_venda", preco_venda);
    insert.bindValue(":pagamento", pagamento);
    insert.bindValue(":situacao", situacao);
    bool b = insert.exec();
    insert.finish();
    return b;
}

bool DataBase::atualizaCliente(QString nome, QString telefone, QString cidade)
{
    QSqlQuery insert;
    insert.prepare("UPDATE clientes SET telefone = (:telefone),cidade = (:cidade) WHERE nome = (:name)");
    insert.bindValue(":telefone", telefone);
    insert.bindValue(":cidade", cidade);
    insert.bindValue(":name", nome);
    bool b = insert.exec();
    insert.finish();
    return b;
}

bool DataBase::atualizaProduto(QString nome, double custo, double venda, int cod, QString quantidade)
{
    QSqlQuery insert;
    insert.prepare("UPDATE produtos SET descricao = (:descricao),custo = (:custo),venda = (:venda) WHERE COD = (:cod) AND quantidade = (:quantidade)");
    insert.bindValue(":descricao", nome);
    insert.bindValue(":custo", custo);
    insert.bindValue(":venda", venda);
    insert.bindValue(":cod", cod);
    insert.bindValue(":quantidade", quantidade);
    bool b = insert.exec();
    insert.finish();
    return b;
}

bool DataBase::atualizaProduto(int fator, int cod, QString quantidade)
{
    QSqlQuery insert;
    insert.prepare("UPDATE produtos SET fator = (:fator) WHERE cod = (:cod) AND quantidade = (:quantidade)");
    insert.bindValue(":fator", fator);
    insert.bindValue(":cod", cod);
    insert.bindValue(":quantidade", quantidade);
    bool b = insert.exec();
    insert.finish();
    return b;
}

bool DataBase::removeCidade(QString cidade)
{
    QSqlQuery insert;
    insert.prepare("DELETE FROM cidade WHERE nome = (:name)");
    insert.bindValue(":name", cidade);
    bool b = insert.exec();
    insert.finish();
    return b;
}

bool DataBase::removeCliente(QString nome)
{
    QSqlQuery insert;
    insert.prepare("DELETE FROM clientes WHERE nome  = ?");
    insert.addBindValue(nome);
    bool b = insert.exec();
    insert.finish();
    return b;
}

bool DataBase::removeLinhaNaTabelaDoCliente(QString quantidade, int COD, int id_carga, QString cliente)
{
    QSqlQuery insert;
    insert.prepare("DELETE FROM tabela WHERE COD  = ? AND quantidade = ? AND id_carga = ? AND nome_cliente = ?");
    insert.addBindValue(COD);
    insert.addBindValue(quantidade);
    insert.addBindValue(id_carga);
    insert.addBindValue(cliente);
    bool b = insert.exec();
    insert.finish();
    return b;
}

bool DataBase::existeProdutoNaTabelaProduto(int cod, QString quantidade)
{
    QSqlQuery insert;
    insert.prepare("SELECT * FROM produtos WHERE COD  = ? AND quantidade = ?");
    insert.addBindValue(cod);
    insert.addBindValue(quantidade);
    insert.exec();
    int b = insert.next();
    return b;
}

bool DataBase::existeProdutoNaTabela(int id_carga, QString cliente, QString quantidade, int cod)
{
    QSqlQuery insert;
    insert.prepare("SELECT * FROM tabela WHERE COD  = ? AND quantidade = ? AND id_carga = ? AND nome_cliente = ?");
    insert.addBindValue(cod);
    insert.addBindValue(quantidade);
    insert.addBindValue(id_carga);
    insert.addBindValue(cliente);
    insert.exec();
    return insert.next();
}

bool DataBase::removeProduto(QString nome, int cod)
{
    QSqlQuery insert;
    insert.prepare("DELETE FROM produtos WHERE COD  = ? AND quantidade = ?");
    insert.addBindValue(cod);
    insert.addBindValue(nome);
    bool b = insert.exec();
    insert.finish();
    return b;
}

bool DataBase::removeClienteNaCarga(QString nome, int cargaAtual)
{
    QSqlQuery insert;
    insert.prepare("DELETE FROM tabela WHERE nome_cliente  = ? AND id_carga = ?");
    insert.addBindValue(nome);
    insert.addBindValue(cargaAtual);
    bool b = insert.exec();
    insert.finish();
    return b;
}

bool DataBase::removeEstoque(QString nome, int cod)
{

    QSqlQuery insert;
    insert.prepare("UPDATE produtos SET fator = (:fator) WHERE cod = (:cod) AND quantidade = (:quantidade)");
    insert.bindValue(":fator", 0);
    insert.bindValue(":cod", cod);
    insert.bindValue(":quantidade", nome);
    bool b = insert.exec();
    insert.finish();
    return b;
}
