#ifndef PAGARCUOTA_H
#define PAGARCUOTA_H

#include <QWidget>

namespace Ui {
class PagarCuota;
}

class PagarCuota : public QWidget
{
    Q_OBJECT

public:
    explicit PagarCuota(QWidget *parent = nullptr);
    ~PagarCuota();

private:
    Ui::PagarCuota *ui;
};

#endif // PAGARCUOTA_H
