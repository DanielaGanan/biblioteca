#ifndef PAGOSCUOTAS_H
#define PAGOSCUOTAS_H

#include <QDate>

class PagosCuotas
{
public:
    PagosCuotas(const int &idPago = 0,
                const int &dniUsuario = 0,
                const int &dniSocio = 0,
                const double &monto = 0,
                const QDate &fechaPago = QDate::currentDate());
    ~PagosCuotas();

    //Getters
    int getIdPago() const;
    int getDniUsuario() const;
    int getDniSocio() const;
    double getMonto() const;
    QDate getFechaPago() const;

    //Setters
    void setIdPago(const int &id);
    void setDniUsuario(const int &dni);
    void setDniSocio(const int &dni);
    void setMonto(const double &monto);
    void setFechaPago(const QDate &fecha);

private:
    int idPago;
    int dniUsuario;
    int dniSocio;
    double monto;
    QDate fechaPago;
};

#endif // PAGOSCUOTAS_H
