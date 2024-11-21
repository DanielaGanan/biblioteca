#include "agregarprestamo.h"
#include "ui_agregarprestamo.h"

agregarPrestamo::agregarPrestamo(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::agregarPrestamo)
{
    ui->setupUi(this);
}

agregarPrestamo::~agregarPrestamo()
{
    delete ui;
}




