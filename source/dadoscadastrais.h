#ifndef DADOSCADASTRAIS_H
#define DADOSCADASTRAIS_H

#include <QWidget>
#include <QMessageBox>

namespace Ui
{
    class dadosCadastrais;
}

class dadosCadastrais : public QWidget
{
    Q_OBJECT

public:
    explicit dadosCadastrais(QWidget *parent = nullptr);
    ~dadosCadastrais();

signals:
    void voltar_administracao_de_clientes();

public slots:
    void abre_janela(QString);

private slots:
    void on_b_voltar_clicked();
    void on_b_salvar_clicked();

private:
    Ui::dadosCadastrais *ui;
};

#endif // DADOSCADASTRAIS_H
