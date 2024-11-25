#ifndef AGREGARPAGO_H
#define AGREGARPAGO_H

#include <QDialog>
#include "pagoscuotas.h"

namespace Ui {
class agregarPago;
}

class agregarPago : public QDialog
{
    Q_OBJECT

public:
    explicit agregarPago(QWidget *parent = nullptr);
    ~agregarPago();

    //Getter
    QStringList getDatosPago() const;

    //Setter
    void setDatosPago(QStringList &datosPago);
    void setNuevoId(int &id);
    void setSocios(QVector<QStringList> &socios);

private slots:
    void on_buttonBox_accepted();

    void on_pushButton_clicked();

private:
    Ui::agregarPago *ui;
    PagosCuotas *pago;
    QVector<QStringList> socios;
};

#endif // AGREGARPAGO_H
