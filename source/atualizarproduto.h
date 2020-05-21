#ifndef ATUALIZARPRODUTO_H
#define ATUALIZARPRODUTO_H

#include <QWidget>
#include <QMessageBox>

namespace Ui
{
    class atualizarProduto;
}

class atualizarProduto : public QWidget
{
    Q_OBJECT

public:
    explicit atualizarProduto(QWidget *parent = nullptr);
    ~atualizarProduto();

private:
    Ui::atualizarProduto *ui;

public slots:
    void abre_janela();

signals:
    void transita_administracao_de_produtos();

private slots:
    void on_b_voltar_clicked();
    void on_b_salvar_clicked();
    void on_in_nome_textEdited(const QString &arg1);
};

#endif // ATUALIZARPRODUTO_H
