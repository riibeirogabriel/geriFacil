#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QApplication>
#include "telaprincipal.h"
#include "administracaodeclientes.h"
#include "visualizarpedido.h"
#include "adicionarproduto.h"
#include "dadoscadastrais.h"
#include "cadastrarcliente.h"
#include "adicionarcidade.h"
#include "estatisticas.h"
#include "visualizarcliente.h"
#include "visualizarcarga.h"
#include "clientesdacarga.h"
#include "adicionarcliente.h"
#include "relatoriocarga.h"
#include "novacarga.h"
#include <QObject>
#include "definircidades.h"
#include "cargas.h"
#include "administracaodecidades.h"
#include "adicionarcidade.h"
#include "administracaodeprodutos.h"
#include "cadastrarproduto.h"
#include "atualizarproduto.h"
#include "database.h"

int main(int argc, char *argv[])
{
    QApplication::addLibraryPath(".");
    DataBase::setupDatabase();
    QApplication app(argc, argv);

    telaPrincipal tela1;
    administracaoDeClientes tela_01;
    visualizarPedido tela_01_1_0;
    adicionarProduto tela_01_1_1;
    dadosCadastrais tela_01_2_0;
    cadastrarCliente tela_01_3_0;
    estatisticas tela_03;
    visualizarCliente tela_03_1_0;
    visualizarCarga tela_03_1_1;
    clientesDaCarga tela6;
    adicionarCliente tela8;
    relatorioCarga tela9;
    novaCarga tela10;
    Cargas tela11;
    definirCidades tela12;
    administracaoDeCidades tela13;
    adicionarCidade tela14;
    administracaoDeProdutos tela15;
    cadastrarProduto tela16;
    atualizarProduto tela17;
    tela1.showMaximized();

    QObject::connect(&tela1, SIGNAL(transita_administracao_de_clientes()), &tela_01, SLOT(abre_janela()));
    QObject::connect(&tela_01, SIGNAL(voltar_tela_principal()), &tela1, SLOT(abre_janela()));
    QObject::connect(&tela_01_1_0, SIGNAL(transita_adicionar_produto(int)), &tela_01_1_1, SLOT(abre_janela(int)));
    QObject::connect(&tela_01_1_1, SIGNAL(transita_visualizar_pedido()), &tela_01_1_0, SLOT(abre_janela()));
    QObject::connect(&tela_01, SIGNAL(transita_dados_cadastrais(QString)), &tela_01_2_0, SLOT(abre_janela(QString)));
    QObject::connect(&tela_01_2_0, SIGNAL(voltar_administracao_de_clientes()), &tela_01, SLOT(abre_janela()));
    QObject::connect(&tela_01, SIGNAL(transita_cadastrar_cliente()), &tela_01_3_0, SLOT(abre_janela()));
    QObject::connect(&tela_01_3_0, SIGNAL(voltar_administracao_de_clientes()), &tela_01, SLOT(abre_janela()));
    QObject::connect(&tela1, SIGNAL(transita_estatisticas()), &tela_03, SLOT(abre_janela()));
    QObject::connect(&tela_03, SIGNAL(voltar_tela_principal()), &tela1, SLOT(abre_janela()));
    QObject::connect(&tela_03, SIGNAL(transita_visualizar_cliente()), &tela_03_1_0, SLOT(abre_janela()));
    QObject::connect(&tela_03_1_0, SIGNAL(voltar_estatisticas()), &tela_03, SLOT(abre_janela()));
    QObject::connect(&tela_03_1_0, SIGNAL(transita_visualizar_carga()), &tela_03_1_1, SLOT(abre_janela()));
    QObject::connect(&tela_03_1_1, SIGNAL(voltar_visualizar_cliente()), &tela_03_1_0, SLOT(abre_janela()));
    QObject::connect(&tela_01_1_0, SIGNAL(transita_adicionar_produto(int)), &tela_01_1_1, SLOT(abre_janela(int)));
    QObject::connect(&tela6, SIGNAL(transita_visualizar_pedido(int)), &tela_01_1_0, SLOT(abre_janela(int)));
    QObject::connect(&tela6, SIGNAL(transita_adicionar_cliente()), &tela8, SLOT(abre_janela()));
    QObject::connect(&tela8, SIGNAL(transita_clientes_da_carga()), &tela6, SLOT(abre_janela()));
    QObject::connect(&tela11, SIGNAL(transita_tela_principal()), &tela1, SLOT(abre_janela()));
    QObject::connect(&tela11, SIGNAL(transita_clientes_da_carga(int)), &tela6, SLOT(abre_janela(int)));
    QObject::connect(&tela11, SIGNAL(transita_relatorio_carga()), &tela9, SLOT(abre_janela()));
    QObject::connect(&tela12, SIGNAL(transita_relatorio_carga()), &tela9, SLOT(abre_janela()));
    QObject::connect(&tela11, SIGNAL(transita_nova_carga()), &tela10, SLOT(abre_janela_1()));
    QObject::connect(&tela6, SIGNAL(transita_cargas()), &tela11, SLOT(abre_janela()));
    QObject::connect(&tela1, SIGNAL(transita_cargas()), &tela11, SLOT(abre_janela()));
    QObject::connect(&tela10, SIGNAL(transita_clientes_da_carga()), &tela11, SLOT(abre_janela()));
    QObject::connect(&tela_01_1_0, SIGNAL(transita_clientes_da_carga()), &tela6, SLOT(abre_janela()));
    QObject::connect(&tela9, SIGNAL(transita_cargas()), &tela11, SLOT(abre_janela()));
    QObject::connect(&tela9, SIGNAL(transita_definir_cidades()), &tela12, SLOT(abre_janela()));
    QObject::connect(&tela1, SIGNAL(transita_administracao_de_cidades()), &tela13, SLOT(abre_janela()));
    QObject::connect(&tela13, SIGNAL(transita_adicionar_cidade()), &tela14, SLOT(abre_janela()));
    QObject::connect(&tela14, SIGNAL(transita_administracao_de_cidades()), &tela13, SLOT(abre_janela()));
    QObject::connect(&tela13, SIGNAL(transita_tela_principal()), &tela1, SLOT(abre_janela()));
    QObject::connect(&tela1, SIGNAL(transita_administracao_de_produtos()), &tela15, SLOT(abre_janela()));
    QObject::connect(&tela15, SIGNAL(transita_atualizar_produto()), &tela17, SLOT(abre_janela()));
    QObject::connect(&tela15, SIGNAL(transita_cadastrar_produto()), &tela16, SLOT(abre_janela()));
    QObject::connect(&tela16, SIGNAL(transita_administracao_de_produtos()), &tela15, SLOT(abre_janela()));
    QObject::connect(&tela17, SIGNAL(transita_administracao_de_produtos()), &tela15, SLOT(abre_janela()));
    QObject::connect(&tela15, SIGNAL(transita_tela_principal()), &tela1, SLOT(abre_janela()));

    DataBase::closeDatabase();
    return app.exec();
}
