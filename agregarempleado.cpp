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
    // Tenemos el contenido del qline
    QString texto = ui->dniEmpleado->text();

    // Para verificar que el texto se pudo convertir en un numero
    bool siEsNumero;

    // convierte el texto a un entero
    int dni = texto.toInt(&siEsNumero);

    // Verifica si el numero se pudo convertir y que sea positivo
    if (siEsNumero && dni >= 0) {
        qDebug () << "Se ingreso el numero: " << dni;

        return dni;

    } else {
        QMessageBox::warning(this, "Numero no valida", "Debe ser un numero positivo", QMessageBox::Ok);
        qDebug() << "Numero no valido";
        ui->dniEmpleado->clear();
        return -1;
    }
}

int agregarEmpleado::telefono()
{
    // Tenemos el contenido del qline
    QString texto = ui->telefonoEmpleado->text();

    // Para verificar que el texto se pudo convertir en un numero
    bool siEsNumero;

    // convierte el texto a un entero
    int telefono = texto.toInt(&siEsNumero);

    // Verifica si el numero se pudo convertir y que sea positivo
    if (siEsNumero && telefono >= 0) {
        qDebug () << "Se ingreso el numero: " << telefono;

        return telefono;

    } else {
        QMessageBox::warning(this, "Numero no valida", "Debe ser un numero positivo", QMessageBox::Ok);
        qDebug() << "Numero no valido";
        ui->telefonoEmpleado->clear();
        return -1;
    }
}


int agregarEmpleado::idEmpleado()
{
    // Tenemos el contenido del qline
    QString texto = ui->idEmpleado->text();

    // Para verificar que el texto se pudo convertir en un numero
    bool siEsNumero;

    // convierte el texto a un entero
    int idEmpleado = texto.toInt(&siEsNumero);

    // Verifica si el numero se pudo convertir y que sea positivo
    if (siEsNumero && idEmpleado >= 0) {
        qDebug () << "Se ingreso el numero: " << idEmpleado;

        return idEmpleado;

    } else {
        QMessageBox::warning(this, "Numero no valida", "Debe ser un numero positivo", QMessageBox::Ok);
        qDebug() << "Numero no valido";
        ui->idEmpleado->clear();
        return -1;
    }
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





