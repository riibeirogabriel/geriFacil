#ifndef VISUALIZARCLIENTE_H
#define VISUALIZARCLIENTE_H

#include <QWidget>
#include <QMessageBox>

namespace Ui
{
    class visualizarCliente;
}

class visualizarCliente : public QWidget
{
    Q_OBJECT

public:
    explicit visualizarCliente(QWidget *parent = nullptr);
    ~visualizarCliente();
    static QString nome_cliente;
    static QString nome_carga;

signals:
    void transita_visualizar_carga();
    void voltar_estatisticas();

public slots:
    void abre_janela();

private slots:
    void on_b_visualizarCarga_clicked();
    void on_b_voltar_clicked();

private:
    Ui::visualizarCliente *ui;
};

#endif // VISUALIZARCLIENTE_H
