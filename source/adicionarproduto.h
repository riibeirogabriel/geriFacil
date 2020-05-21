#ifndef ADICIONARPRODUTO_H
#define ADICIONARPRODUTO_H

#include <QWidget>
#include <QMessageBox>

namespace Ui
{
    class adicionarProduto;
}

class adicionarProduto : public QWidget
{
    Q_OBJECT

public:
    explicit adicionarProduto(QWidget *parent = nullptr);
    ~adicionarProduto();
    int janela_que_abriu;
    static int id_carga;
    static QString cliente;
    static int pagamento;
    static int situacao;

private:
    Ui::adicionarProduto *ui;

public slots:
    void abre_janela(int janela);

signals:
    void transita_visualizar_pedido();
    void transita_estoque();

private slots:
    void on_b_voltar_clicked();
    void on_b_adicionar_clicked();
    void on_in_cod_textEdited(const QString &arg1);
};

#endif // ADICIONARPRODUTO_H
