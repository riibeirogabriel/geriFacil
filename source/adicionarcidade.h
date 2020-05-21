#ifndef ADICIONARCIDADE_H
#define ADICIONARCIDADE_H

#include <QWidget>
#include <QMessageBox>
#include "database.h"
#include "qdebug.h"

namespace Ui
{
    class adicionarCidade;
}

class adicionarCidade : public QWidget
{
    Q_OBJECT

public:
    explicit adicionarCidade(QWidget *parent = nullptr);
    ~adicionarCidade();

private:
    Ui::adicionarCidade *ui;

signals:
    void transita_administracao_de_cidades();

public slots:
    void abre_janela();

private slots:
    void on_b_voltar_clicked();
    void on_b_salvar_clicked();
};

#endif // ADICIONARCIDADE_H
