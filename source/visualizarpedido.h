#ifndef VISUALIZARPEDIDO_H
#define VISUALIZARPEDIDO_H

#include <QWidget>
#include <QMessageBox>

namespace Ui
{
    class visualizarPedido;
}

class visualizarPedido : public QWidget
{
    Q_OBJECT

public:
    explicit visualizarPedido(QWidget *parent = nullptr);
    ~visualizarPedido();
    static int id_carga;
    static QString cliente;
    static double valor_venda;

private:
    Ui::visualizarPedido *ui;
    int janela_que_abriu;

public slots:
    void abre_janela(int = -1);

private slots:
    void on_b_voltar_clicked();
    void on_b_adicionar_produto_clicked();
    void on_b_salvar_clicked();
    void on_b_remover_produto_clicked();
    void on_b_imprimir_clicked();

signals:
    void transita_clientes_da_carga();
    void transita_venda_fora_da_carga();
    void transita_adicionar_produto(int);
    void transita_visualizar_debito();
};

#endif // VISUALIZARPEDIDO_H
