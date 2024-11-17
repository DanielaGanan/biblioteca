#include "agregarempleado.h"
#include "ui_agregarempleado.h"

agregarEmpleado::agregarEmpleado(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::agregarEmpleado)
{
    ui->setupUi(this);
}

agregarEmpleado::~agregarEmpleado()
{
    delete ui;
}


void agregarEmpleado::on_buttonBox_accepted()
{
    accept(); // el usuario apreta ok
}


void agregarEmpleado::on_buttonBox_rejected()
{
    reject(); // Para saber que se cerro
}


int agregarEmpleado::validarNumero(QLineEdit* num)
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

QString agregarEmpleado::nombre()
{
    qDebug() << "Retorna nombre:" << ui->nombreEmpleado->text();
    return ui->nombreEmpleado->text();
}

QString agregarEmpleado::apellido()
{
    qDebug() << "Retorna apellido:" << ui->apellidoEmpleado->text();
    return ui->apellidoEmpleado->text();
}

QString agregarEmpleado::direccion()
{
    qDebug() << "Retorna apellido:" << ui->direccionEmpleado->text();
    return ui->direccionEmpleado->text();
}

int agregarEmpleado::dni()
{
    return validarNumero(ui->dniEmpleado);
}

int agregarEmpleado::telefono()
{
    return validarNumero(ui->telefonoEmpleado);
}


int agregarEmpleado::idEmpleado()
{
    return validarNumero(ui->idEmpleado);
}


void agregarEmpleado::limpiarPantalla()
{
    ui->nombreEmpleado->clear();
    ui->apellidoEmpleado->clear();
    ui->direccionEmpleado->clear();
    ui->dniEmpleado->clear();
    ui->idEmpleado->clear();
    ui->telefonoEmpleado->clear();
}

// void agregarEmpleado::llenarFormulario(QString nombre, QString apellido, QString dni, QString direccion,
//QString telefono, int idEmpleado);

void agregarEmpleado::llenarFormulario(int idEmpleado)
{

/*    ui->nombreEmpleado->setText(nombre);
    ui->apellidoEmpleado->setText(apellido);
    ui->dniEmpleado->setText(dni);
    ui->direccionEmpleado->setText(direccion);
    ui->telefonoEmpleado->setText(telefono);  */
    ui->idEmpleado->setText(QString::number(idEmpleado));
}



