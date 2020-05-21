#ifndef REMOVERPRODUTO_H
#define REMOVERPRODUTO_H

#include <QWidget>

namespace Ui
{
    class removerProduto;
}

class removerProduto : public QWidget
{
    Q_OBJECT

public:
    explicit removerProduto(QWidget *parent = nullptr);
    ~removerProduto();

private:
    Ui::removerProduto *ui;
};

#endif // REMOVERPRODUTO_H
