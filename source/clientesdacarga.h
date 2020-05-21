#ifndef CLIENTESDACARGA_H
#define CLIENTESDACARGA_H

#include <QWidget>
#include <QMessageBox>

namespace Ui
{
    class clientesDaCarga;
}

class clientesDaCarga : public QWidget
{
    Q_OBJECT

public:
    explicit clientesDaCarga(QWidget *parent = nullptr);
    ~clientesDaCarga();
    static QString carga;

private:
    Ui::clientesDaCarga *ui;
    int janela_que_ativou;
    int cargagRecente;

public slots:
    void abre_janela(int = -1);
    void on_b_voltar_clicked();

signals:
    void transita_fazer_venda();
    void transita_visualizar_pedido(int);
    void transita_adicionar_cliente();
    void transita_cargas();

private slots:
    void on_b_visualizar_pedido_clicked();
    void on_b_adicionar_cliente_clicked();
    void on_b_remover_produto_clicked();
    void on_in_nome_cliente_textEdited(const QString &arg1);
};

#endif // CLIENTESDACARGA_H
