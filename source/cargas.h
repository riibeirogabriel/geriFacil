#ifndef CARGAS_H
#define CARGAS_H

#include <QWidget>
#include <QMessageBox>

namespace Ui
{
    class Cargas;
}

class Cargas : public QWidget
{
    Q_OBJECT

public:
    explicit Cargas(QWidget *parent = nullptr);
    ~Cargas();

private slots:
    void on_b_voltar_clicked();
    void on_b_clientes_da_carga_clicked();
    void on_b_relatorio_carga_clicked();
    void on_b_nova_carga_clicked();
    void abre_janela();
    void on_in_nome_textEdited(const QString &arg1);

signals:
    void transita_tela_principal();
    void transita_clientes_da_carga(int);
    void transita_relatorio_carga();
    void transita_nova_carga();

private:
    Ui::Cargas *ui;
};

#endif // CARGAS_H
