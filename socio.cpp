#include "socio.h"
#include "ui_socio.h"

Socio::Socio(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Socio)
{
    ui->setupUi(this);
    this->setWindowTitle("Socios");
}

Socio::~Socio()
{
    delete ui;
}

//Getters
int Socio::getIdSocio() const
{
    return idSocio;
}

bool Socio::getEstado() const
{
    return estado;
}

//Setters
void Socio::setIdSocio(const int idSocio)
{
    this->idSocio = idSocio;
}

void Socio::setEstado(const bool estado)
{
    this->estado = estado;
}

//Métodos de acciones en el formulario
bool Socio::consultarEstado()
{

}
