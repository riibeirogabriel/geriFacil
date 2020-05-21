#ifndef RELATORIOCARGA_H
#define RELATORIOCARGA_H

#include <QWidget>
#include <QMessageBox>
#include <vector>

using namespace std;

namespace Ui
{
    class relatorioCarga;
}

class relatorioCarga : public QWidget
{
    Q_OBJECT
    double valor_venda;

public:
    explicit relatorioCarga(QWidget *parent = nullptr);
    ~relatorioCarga();
    static QString id_carga;
    static vector<QString> cidades;
    static vector<QString> clientes;
    static int condicao;

private:
    Ui::relatorioCarga *ui;

public slots:
    void abre_janela();

private slots:
    void on_b_voltar_clicked();
    void on_b_definir_cidades_clicked();
    void on_b_imprimir_clicked();
    void on_pushButton_clicked();

signals:
    void transita_cargas();
    void transita_definir_cidades();
};

#endif // RELATORIOCARGA_H
