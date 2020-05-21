#ifndef VENDAFORADACARGA_H
#define VENDAFORADACARGA_H

#include <QWidget>
#include <QMessageBox>

namespace Ui
{
    class vendaForaDacarga;
}

class vendaForaDacarga : public QWidget
{
    Q_OBJECT

public:
    explicit vendaForaDacarga(QWidget *parent = nullptr);
    ~vendaForaDacarga();

private:
    Ui::vendaForaDacarga *ui;

public slots:
    void abre_janela();
    void on_b_voltar_clicked();

signals:
    void transita_fazer_venda();
    void transita_visualizar_pedido(int);

private slots:
    void on_b_adicionar_clicked();
    void on_in_nome_cliente_textEdited(const QString &arg1);
    void on_b_novo_pedido_clicked();
};

#endif // VENDAFORADACARGA_H
