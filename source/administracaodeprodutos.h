#ifndef ADMINISTRACAODEPRODUTOS_H
#define ADMINISTRACAODEPRODUTOS_H

#include <QWidget>
#include <QMessageBox>

namespace Ui
{
    class administracaoDeProdutos;
}

class administracaoDeProdutos : public QWidget
{
    Q_OBJECT

public:
    explicit administracaoDeProdutos(QWidget *parent = nullptr);
    ~administracaoDeProdutos();

public slots:
    void abre_janela();

signals:
    void transita_tela_principal();
    void transita_cadastrar_produto();
    void transita_atualizar_produto();

private slots:
    void on_b_voltar_clicked();
    void on_b_cadastrar_produto_clicked();
    void on_b_atualizar_produto_clicked();
    void on_b_remover_produto_clicked();
    void on_b_imprimir_clicked();
    void on_in_nome_textEdited(const QString &arg1);
    void on_pushButton_clicked();

private:
    Ui::administracaoDeProdutos *ui;
};

#endif // ADMINISTRACAODEPRODUTOS_H
