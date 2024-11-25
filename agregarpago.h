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
    void setNuevoId(int &id);
    void setSocios(QVector<QStringList> &socios);
    void setUsuario(QStringList &usuario);
    void setPagoEditar(QStringList &pago);

private slots:
    void on_aceptar();
    void on_btnBuscarDni_clicked();
    void on_selectSocio();

private:
    Ui::agregarPago *ui;
    PagosCuotas pago;
    QVector<QStringList> socios;
};

#endif // AGREGARPAGO_H
