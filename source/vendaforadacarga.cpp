#include "vendaforadacarga.h"
#include "ui_vendaforadacarga.h"
#include "database.h"
#include "qsqlquery.h"
#include "qsqlrecord.h"
#include "qdebug.h"
#include "QtPrintSupport/QPrinter"
#include "QtPrintSupport/QPrintDialog"
#include <QPrinter>
#include <QtWidgets>
#include <vector>

vendaForaDacarga::vendaForaDacarga(QWidget *parent) : QWidget(parent),
                                                      ui(new Ui::vendaForaDacarga)
{
    ui->setupUi(this);
}

vendaForaDacarga::~vendaForaDacarga()
{
    delete ui;
}

void vendaForaDacarga::abre_janela()
{
    ui->listWidget->clear();
    DataBase db;
    QSqlQuery *query = db.coletaClientes();
    int fieldNo1 = query->record().indexOf("nome");
    QString texto;

    for (int i = 0; query->next(); i++)
    {

        texto = query->value(fieldNo1).toString();
        QListWidgetItem *newItem = new QListWidgetItem;
        newItem->setText(texto);
        ui->listWidget->insertItem(i, newItem);
    }

    showMaximized();
}

void vendaForaDacarga::on_b_voltar_clicked()
{
    hide();
    emit transita_fazer_venda();
}

void vendaForaDacarga::on_b_adicionar_clicked()
{
    hide();
    emit transita_visualizar_pedido(1);
}

void vendaForaDacarga::on_in_nome_cliente_textEdited(const QString &arg1)
{
    ui->listWidget->clear();
    QMessageBox msgBox;
    QString nomeProcura = arg1;
    nomeProcura.remove(QRegExp("[^A-z áàâãéèêíïóôõöúçñÁÀÂÃÉÈÍÏÓÔÕÖÚÇÑ]"));
    DataBase db;

    if (nomeProcura == "")
    {
        abre_janela();
        return;
    }

    QSqlQuery *query = db.coletaClientes();
    int fieldNo1 = query->record().indexOf("nome");

    for (int i = 0; query->next();)
    {
        QString nome = query->value(fieldNo1).toString();

        if (nome.contains(nomeProcura))
        {
            QListWidgetItem *newItem;
            newItem = new QListWidgetItem(nome);
            ui->listWidget->insertItem(i++, newItem);
        }
    }
}

void vendaForaDacarga::on_b_novo_pedido_clicked()
{
}
