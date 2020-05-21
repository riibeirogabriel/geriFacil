#ifndef CADASTRARCLIENTE_H
#define CADASTRARCLIENTE_H

#include <QWidget>
#include <QMessageBox>

namespace Ui
{
    class cadastrarCliente;
}

class cadastrarCliente : public QWidget
{
    Q_OBJECT

public:
    explicit cadastrarCliente(QWidget *parent = nullptr);
    ~cadastrarCliente();

signals:
    void voltar_administracao_de_clientes();

public slots:
    void abre_janela();

private slots:
    void on_b_voltar_clicked();
    void on_b_cadastrar_clicked();
    void on_b_limpar_clicked();

private:
    Ui::cadastrarCliente *ui;
};

#endif // CADASTRARCLIENTE_H
