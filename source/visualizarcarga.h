#ifndef VISUALIZARCARGA_H
#define VISUALIZARCARGA_H

#include <QWidget>
#include <QMessageBox>

namespace Ui
{
    class visualizarCarga;
}

class visualizarCarga : public QWidget
{
    Q_OBJECT
    double valor_venda;

public:
    explicit visualizarCarga(QWidget *parent = nullptr);
    ~visualizarCarga();

signals:
    void voltar_visualizar_cliente();

public slots:
    void abre_janela();

private slots:
    void on_b_voltar_clicked();
    void on_b_imprimir_clicked();

private:
    Ui::visualizarCarga *ui;
};

#endif // VISUALIZARCARGA_H
