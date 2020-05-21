#ifndef ESTATISTICAS_H
#define ESTATISTICAS_H

#include <QWidget>
#include <QMessageBox>

namespace Ui
{
    class estatisticas;
}

class estatisticas : public QWidget
{
    Q_OBJECT

public:
    explicit estatisticas(QWidget *parent = nullptr);
    ~estatisticas();

signals:
    void transita_visualizar_cliente();
    void transita_pagamento_pendente();
    void voltar_tela_principal();

public slots:
    void abre_janela();

private slots:
    void on_b_visualizarCliente_clicked();
    void on_b_pagamentosPendete_clicked();
    void on_b_voltar_clicked();
    void on_in_cliente_textEdited(const QString &arg1);

private:
    Ui::estatisticas *ui;
};

#endif // ESTATISTICAS_H
