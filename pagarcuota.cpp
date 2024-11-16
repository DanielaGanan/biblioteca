#include "pagarcuota.h"
#include "ui_pagarcuota.h"

PagarCuota::PagarCuota(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PagarCuota)
{
    ui->setupUi(this);
}

PagarCuota::~PagarCuota()
{
    delete ui;
}
/*
//Metodos getters
int getIdCuotaPrestamo()
{
    return getIdCuotaPrestamo;
}

float getCuota()
{
    return cuota;
}

QDate getFecha()
{
    return fecha;
}

Socio getSocio()
{
    return socio;
}

// Metodos setters
void setIdCuotaPrestamo(int idCuotaPrestamo)
{
    this.idCuotaPrestamo = idCuotaPrestamo;
}

void setCuota(float cuota)
{
    this.cuota = cuota;
}

void setFecha(QDate fecha)
{
    this.fecha = fecha;
}

void setSocio(Socio socio)
{
    this.socio = socio;
}

// Metodo para agregar un pago
bool PagarCuota::agregarPago()
{
    return false;
}

// Metodo para modificar un pago
bool PagarCuota::modificarPago()
{
    return false;
}

// Metodo para eliminar un pago
bool PagarCuota::eliminarPago()
{
    return false;
}

void PagarCuota::listarPagos()
{

}

void PagarCuota::buscarPagoSocio(Socio)
{

}
*/
