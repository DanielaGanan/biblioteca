#include "prestamo.h"
#include "ui_prestamo.h"

Prestamo::Prestamo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Prestamo)
{
    ui->setupUi(this);
}

Prestamo::~Prestamo()
{
    delete ui;
}










