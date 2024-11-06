#include "empleado.h"
#include "ui_empleado.h"

Empleado::Empleado(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Empleado)
{
    ui->setupUi(this);
}

Empleado::~Empleado()
{
    delete ui;
}
