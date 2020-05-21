#ifndef ADMINISTRACAODECLIENTES_H
#define ADMINISTRACAODECLIENTES_H

#include <QWidget>
#include <QMessageBox>

namespace Ui
{
    class administracaoDeClientes;
}

class administracaoDeClientes : public QWidget
{
    Q_OBJECT

public:
    explicit administracaoDeClientes(QWidget *parent = nullptr);
    ~administracaoDeClientes();

signals:
    void transita_dados_cadastrais(QString);
    void transita_cadastrar_cliente();
    void voltar_tela_principal();

public slots:
    void abre_janela();

private slots:
    void on_b_dadosCadastrais_clicked();
    void on_b_cadastrarCliente_clicked();
    void on_b_voltar_clicked();

    void on_b_removerCliente_clicked();

    void on_b_imprimirClientes_clicked();

    void on_in_cliente_textEdited(const QString &arg1);

private:
    Ui::administracaoDeClientes *ui;
};

#endif // ADMINISTRACAODECLIENTES_H
