#ifndef ADICIONARCLIENTE_H
#define ADICIONARCLIENTE_H

#include <QWidget>
#include <QMessageBox>

namespace Ui
{
    class adicionarCliente;
}

class adicionarCliente : public QWidget
{
    Q_OBJECT

public:
    explicit adicionarCliente(QWidget *parent = nullptr);
    ~adicionarCliente();
    static int id_carga;

private:
    Ui::adicionarCliente *ui;

public slots:
    void abre_janela();

signals:
    void transita_clientes_da_carga();

private slots:
    void on_b_voltar_clicked();
    void on_b_adicionar_clicked();
    void on_in_nome_textEdited(const QString &arg1);
};

#endif // ADICIONARCLIENTE_H
