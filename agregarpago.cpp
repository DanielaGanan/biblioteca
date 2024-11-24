#include "agregarpago.h"
#include "ui_agregarpago.h"

agregarPago::agregarPago(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::agregarPago)
{
    ui->setupUi(this);
}

agregarPago::~agregarPago()
{
    delete ui;
}
