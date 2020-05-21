#include "removerproduto.h"
#include "ui_removerproduto.h"

removerProduto::removerProduto(QWidget *parent) : QWidget(parent),
                                                  ui(new Ui::removerProduto)
{
    ui->setupUi(this);
}

removerProduto::~removerProduto()
{
    delete ui;
}
