#include "telaprincipal.h"
#include "ui_telaprincipal.h"

telaPrincipal::telaPrincipal(QWidget *parent) : QWidget(parent),
                                                ui(new Ui::telaPrincipal)
{
    ui->setupUi(this);
}

telaPrincipal::~telaPrincipal()
{
    delete ui;
}

void telaPrincipal::on_b_fazer_venda_clicked()
{
    hide();
    emit transita_fazer_venda();
}

void telaPrincipal::on_b_administracao_de_clientes_clicked()
{
    hide();
    emit transita_administracao_de_clientes();
}

void telaPrincipal::on_b_estatisticas_clicked()
{
    hide();
    emit transita_estatisticas();
}

void telaPrincipal::abre_janela()
{
    showMaximized();
}

void telaPrincipal::on_b_cargas_clicked()
{
    hide();
    emit transita_cargas();
}

void telaPrincipal::on_b_administracao_de_cidades_clicked()
{
    hide();
    emit transita_administracao_de_cidades();
}

void telaPrincipal::on_b_administracao_de_produtos_clicked()
{
    hide();
    emit transita_administracao_de_produtos();
}
