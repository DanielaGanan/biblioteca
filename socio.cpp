#include "socio.h"
#include "ui_socio.h"

Socio::Socio(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Socio)
{
    ui->setupUi(this);
}

Socio::~Socio()
{
    delete ui;
}
