#ifndef PAGARCUOTA_H
#define PAGARCUOTA_H

#include <QWidget>
#include "qdebug.h"
#include "socio.h"
#include <QDate>

namespace Ui {
class PagarCuota;
}

class PagarCuota : public QWidget
{
    Q_OBJECT

public:
    explicit PagarCuota(QWidget *parent = nullptr);
    ~PagarCuota();

    int getIdCuotaPrestamo();
    float getCuota();
    QDate getFecha();
    Socio getSocio();

    void setIdCuotaPrestamo(int idCuotaPrestamo);
    void setCuota(float cuota);
    void setFecha(QDate fecha);
    void setSocio(Socio socio);

private slots:
    bool agregarPago();
    bool modificarPago();
    bool eliminarPago();
    void listarPagos(); //Va en slots o no?
    void buscarPagoSocio(Socio); //Busca un pago de un socio en particular

private:
    Ui::PagarCuota *ui;
    int idCuotaPrestamo;
    float cuota;
    QDate fecha;
    Socio socio;
};

#endif // PAGARCUOTA_H
