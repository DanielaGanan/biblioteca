#include "libro.h"
#include "ui_libro.h"

Libro::Libro(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Libro)
{
    ui->setupUi(this);
}

Libro::~Libro()
{
    delete ui;
}
