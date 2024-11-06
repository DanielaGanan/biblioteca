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
