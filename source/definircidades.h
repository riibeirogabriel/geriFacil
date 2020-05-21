#ifndef DEFINIRCIDADES_H
#define DEFINIRCIDADES_H

#include <QWidget>
#include <QMessageBox>

namespace Ui
{
    class definirCidades;
}

class definirCidades : public QWidget
{
    Q_OBJECT

public:
    explicit definirCidades(QWidget *parent = nullptr);
    ~definirCidades();

private slots:
    void on_b_voltar_clicked();
    void on_b_selecionar_todas_as_cidades_clicked();
    void on_b_limpar_clicked();
    void on_b_salvae_clicked();

private:
    Ui::definirCidades *ui;

signals:
    void transita_relatorio_carga();

public slots:
    void abre_janela();
};

#endif // DEFINIRCIDADES_H
