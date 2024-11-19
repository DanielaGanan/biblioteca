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


void agregarPrestamo::on_buttonBox_accepted()
{
    accept(); // el usuario apreta ok
}


void agregarPrestamo::on_buttonBox_rejected()
{
    reject(); // Para saber que se cerro
}


int agregarPrestamo::validarNumero(QLineEdit* num)
{
    // Tenemos el contenido del qline
    QString texto = num->text();

    // Para verificar que el texto se pudo convertir en un numero
    bool esNumero;

    int numero = texto.toInt(&esNumero);

    // Verifica si el numero se pudo convertir y que sea positivo
    if (esNumero && numero >= 0) {
        qDebug () << "Se ingreso el numero: " << numero;
        return numero;

    } else {
        qDebug() << "Numero no valido";

        num->clear(); //Limpiar qline
        return -1;
    }
}


void agregarPrestamo::llenarFormulario()
{
    ui->libroComboBox->clear();

    for (libro* libr : libros){
        ui->libroComboBox->addItem(libr->getTitulo());
    }

    for (Empleado* empleado : empleados){
        ui->empleadoComboBox->addItem(QString::number(empleado->getIdEmpleado()));
    }

    /*
    for (Socio* socio : Socios){
        ui->sociosComboBox->addItem(socio.getIdSocio());
    }*/
}


int agregarPrestamo::idPrestamo()
{
    return validarNumero(ui->idPrestamoQLine);
}
/*
libro agregarPrestamo::libros()
{
    QString titulo = ui->libroComboBox->currentText();

    for ( libro libr : libros){
        if(titulo == libr.getTitulo()) return libr;
    }

    return nullptr;
}
*/
/*
Empleado agregarPrestamo::empleado()
{
    QString dni = ui->empleadoComboBox->currentText();

    for ( Empleado empl : empleados ){
        if(dni == empl.getIdEmpleado()) return libr;
    }

    return nullptr;
}
*/







