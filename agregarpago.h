#ifndef AGREGARPAGO_H
#define AGREGARPAGO_H

#include <QDialog>

namespace Ui {
class agregarPago;
}

class agregarPago : public QDialog
{
    Q_OBJECT

public:
    explicit agregarPago(QWidget *parent = nullptr);
    ~agregarPago();

private:
    Ui::agregarPago *ui;
};

#endif // AGREGARPAGO_H
