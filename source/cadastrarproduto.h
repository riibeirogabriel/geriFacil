#ifndef CADASTRARPRODUTO_H
#define CADASTRARPRODUTO_H

#include <QWidget>
#include <QMessageBox>

namespace Ui
{
    class cadastrarProduto;
}

class cadastrarProduto : public QWidget
{
    Q_OBJECT

public:
    explicit cadastrarProduto(QWidget *parent = nullptr);
    ~cadastrarProduto();

public slots:
    void abre_janela();

signals:
    void transita_administracao_de_produtos();

private slots:
    void on_b_voltar_clicked();
    void on_b_adicionar_clicked();
    void on_b_limpar_clicked();

private:
    Ui::cadastrarProduto *ui;
};

#endif // CADASTRARPRODUTO_H
