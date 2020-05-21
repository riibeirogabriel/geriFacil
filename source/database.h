#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>

class DataBase
{

    friend class DatabaseHelperImplTest;

public:
    DataBase();
    QSqlQuery *coletaLinhasdaTabelaDaCarga(QString carga);
    QSqlQuery *coletaCargasCliente(QString nome_cliente);
    QSqlQuery *coletaCargasDeClientesPendentes();
    bool verificaCargaExiste(QString carga);
    virtual ~DataBase();
    bool existeProdutoNaTabelaProduto(int cod, QString quantidade);
    bool criaHistoricoProduto(int cod, QString nome, QString quantidade, double custo, double venda);
    QSqlQuery *coletaHistoricoProduto(QString quant, int cod);
    bool verificaCidadeExiste(QString cidade);
    bool verificaClienteExiste(QString cliente);
    bool verificaProdutoExiste(QString cod);
    bool criaLinhaNaTabela(int linha, int carga, QString cidade, QString id_cliente);
    bool criaCidade(QString cidade);
    bool criaProduto(int cod, QString nome, QString quantidade, double custo, double venda);
    QSqlQuery *coletaLinhaDaTabela(int linha, int id_cliente);
    QSqlQuery *coletaCidade(QString nome);
    QSqlQuery *coletaCidade(int cod);
    bool atualizaLinhaNaTabela(int linha, QString carga, QString cidade, int id_cliente, int COD, QString nome, QString unidade, QString quantidade, double preco_custo, double preco_venda, QString pagamento, QString situacao);
    QSqlQuery *coletaCidades();
    bool removeCidade(QString cidade);
    bool verificaLinhaClienteCargaNaTabela(int id_carga, QString cliente);
    bool atualizaProduto(QString nome, double custo, double venda, int cod, QString quantidade);
    int coletaIdcarga(QString id);
    bool adicionaProdutoNaTabela(int linha, int carga, QString cidade, QString id_cliente, QString quantidade, int codProduto, int pagamento, int situacao);
    bool atualizaProdutoNaTabela(int carga, QString id_cliente, QString quantidade, int codProduto, double venda, int pagamento, int situacao, int fator);
    bool removeLinhaNaTabelaDoCliente(QString quantidade, int COD, int id_carga, QString cliente);
    bool existeProdutoNaTabela(int id_carga, QString cliente, QString quantidade, int cod);
    bool criaCliente(QString cidade, QString telefone, QString nome);
    bool removeProduto(QString nome, int cod);
    bool atualizaProduto(int fator, int cod, QString quantidade);
    QSqlQuery *coletaClientesDaCargaNaTabela(int carga);
    QString coletaNomecarga(int id);
    int maiorNumLinhaNaTabelaDoCliente(int idCarga, QString nomeCliente);
    bool removeClienteNaCarga(QString nome, int cargaAtual);
    QSqlQuery *coletaCliente(QString nome);
    QSqlQuery *coletaClientes();
    bool atualizaCliente(QString, QString, QString);
    bool removeCliente(QString nome);
    bool removeEstoque(QString, int);
    static void closeDatabase();
    static void setupDatabase();
    QSqlQuery *coletaProdutos();
    bool criaCarga(QString carga);
    int maiorNumCarga();
    QSqlQuery *coletaProduto(QString quant, int cod);
    QSqlQuery *coletaCargas();
    QSqlQuery *coletaLinhasDaTabelaDoCliente(QString cliente, int id_carga);

protected:
    QSqlDatabase sqlDatabase;

private:
    DataBase(const DataBase &);
    DataBase &operator=(const DataBase &);
};

#endif // DATABASE_H
