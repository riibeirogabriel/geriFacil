#ifndef TELAPRINCIPAL_H
#define TELAPRINCIPAL_H

#include <QWidget>
#include <QMessageBox>

namespace Ui
{
    class telaPrincipal;
}

class telaPrincipal : public QWidget
{
    Q_OBJECT

public:
    explicit telaPrincipal(QWidget *parent = nullptr);
    ~telaPrincipal();

signals:
    void transita_fazer_venda();
    void transita_administracao_de_clientes();
    void transita_administracao_de_cidades();
    void transita_estatisticas();
    void transita_cargas();
    void transita_administracao_de_produtos();

private slots:
    void abre_janela();
    void on_b_fazer_venda_clicked();
    void on_b_administracao_de_clientes_clicked();
    void on_b_estatisticas_clicked();
    void on_b_cargas_clicked();
    void on_b_administracao_de_cidades_clicked();
    void on_b_administracao_de_produtos_clicked();

private:
    Ui::telaPrincipal *ui;
};

#endif // TELAPRINCIPAL_H
