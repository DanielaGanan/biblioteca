#include "pagoscuotas.h"

PagosCuotas::PagosCuotas(const int &idPago,
                         const int &dniUsuario,
                         const int &dniSocio,
                         const double &monto,
                         const QDate &fecha)
{
    this->idPago = idPago;
    this->dniUsuario = dniUsuario;
    this->dniSocio = dniSocio;
    this->monto = monto;
    this->fechaPago = fecha;
}

PagosCuotas::~PagosCuotas() {}

//Getters
int PagosCuotas::getIdPago() const
{
    return idPago;
}

int PagosCuotas::getDniUsuario() const
{
    return dniUsuario;
}

int PagosCuotas::getDniSocio() const
{
    return dniSocio;
}

double PagosCuotas::getMonto() const
{
    return monto;
}

QDate PagosCuotas::getFechaPago() const
{
    return fechaPago;
}

//Setters
void PagosCuotas::setIdPago(const int &id)
{
    this->idPago = id;
}

void PagosCuotas::setDniUsuario(const int &dni)
{
    this->dniUsuario = dni;
}

void PagosCuotas::setDniSocio(const int &dni)
{
    this->dniSocio = dni;
}

void PagosCuotas::setMonto(const double &monto)
{
    this->monto = monto;
}

void PagosCuotas::setFechaPago(const QDate &fecha)
{
    this->fechaPago = fecha;
}
