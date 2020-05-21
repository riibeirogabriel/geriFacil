#ifndef ADMINISTRACAODECIDADES_H
#define ADMINISTRACAODECIDADES_H

#include <QWidget>
#include <QMessageBox>
#include "database.h"

namespace Ui
{
    class administracaoDeCidades;
}

class administracaoDeCidades : public QWidget
{
    Q_OBJECT

public:
    explicit administracaoDeCidades(QWidget *parent = nullptr);
    ~administracaoDeCidades();

private:
    Ui::administracaoDeCidades *ui;

public slots:
    void abre_janela();

signals:
    void transita_adicionar_cidade();
    void transita_tela_principal();

private slots:
    void on_b_voltar_clicked();
    void on_b_adicionar_cidade_clicked();
    void on_b_remover_cidade_clicked();
};

#endif // ADMINISTRACAODECIDADES_H
