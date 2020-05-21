#ifndef NOVACARGA_H
#define NOVACARGA_H

#include <QWidget>
#include <QMessageBox>

namespace Ui
{
    class novaCarga;
}

class novaCarga : public QWidget
{
    Q_OBJECT

public:
    explicit novaCarga(QWidget *parent = nullptr);
    ~novaCarga();

private:
    Ui::novaCarga *ui;

public slots:
    void abre_janela_1();

private slots:
    void on_b_voltar_clicked();
    void on_b_criar_nova_carga_clicked();

signals:
    void transita_clientes_da_carga();
};

#endif // NOVACARGA_H
