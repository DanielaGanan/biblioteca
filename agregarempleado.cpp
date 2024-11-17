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
        QMessageBox::warning(this, "Numero no valida", "DNI debe ser un numero", QMessageBox::Ok);
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
        QMessageBox::warning(this, "Numero no valida", "Telefono debe ser un numero", QMessageBox::Ok);
        qDebug() << "Numero no valido";
        ui->telefonoEmpleado->clear();
        return false;
    }
}


int agregarEmpleado::idEmpleado()
{
    // Tenemos el contenido del qline
    QString texto = ui->idEmpleado->text();

    qDebug () << "Se ingreso el id: " << ui->idEmpleado->text();

    // Para verificar que el texto se pudo convertir en un numero
    bool siEsNumero;

    // convierte el texto a un entero
    int idEmpleado = texto.toInt(&siEsNumero);

    // Verifica si el numero se pudo convertir y que sea positivo
    if (siEsNumero && idEmpleado >= 0) {
        qDebug () << "Se ingreso el numero: " << idEmpleado;

        return idEmpleado;

    } else {
        QMessageBox::warning(this, "Numero no valida", "Id Empleado debe ser un numero", QMessageBox::Ok);
        qDebug() << "Numero no valido";
        ui->idEmpleado->clear();
        return false;
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



