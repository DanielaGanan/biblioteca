#include "empleado.h"
#include "ui_empleado.h"

Empleado::Empleado(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Empleado)
{
    ui->setupUi(this);

    this->setWindowTitle("Formulario Empleado");

    connect(ui->botonAgregarEmpleado, &QPushButton::clicked, this, &Empleado::agregarEmpleadoNuevo);
    connect(ui->botonModificarEmpleado, &QPushButton::clicked, this, &Empleado::modificarEmpleado);
    connect(ui->botonEliminarEmpleado, &QPushButton::clicked, this, &Empleado::eliminarEmpleado);
}

/*Empleado::Empleado(QString nombre, QString apellido,
    QString dni, QString direccion, QString telefono,
    int idEmpleado, QString usuario, QString contrasenia,
    QWidget *parent)
    :QWidget(parent)
    , ui(new Ui::Empleado)*/


/*Empleado::Empleado(int idEmpleado, QString usuario, QString contrasenia,
    QWidget *parent)
    :QWidget(parent)
    , ui(new Ui::Empleado)*/

    Empleado::Empleado(int idEmpleado, QWidget *parent)
    :QWidget(parent)
    , ui(new Ui::Empleado)


{
    ui->setupUi(this);

  //  this->Nombre = nombre;
  //  this->Apellido = apellido;
  //  this->DNI = dni;
  //  this->Direccion = direccion;
  //  this->Telefono = telefono;
    this->idEmpleado = idEmpleado;
  //  this->usuario = usuario;
  //  this->contrasenia = contrasenia;
}

Empleado::~Empleado()
{
    delete ui;
}


// Metodos getters
int Empleado::getIdEmpleado()
{
    return idEmpleado;
}

/*
QString Empleado::getUsuario()
{
    return usuario;
}

QString Empleado::getContrasenia()
{
    return contrasenia;
}*/

// Metodos setters
void Empleado::setIdEmpleado(int idEmpleado)
{
    this->idEmpleado = idEmpleado;
}

/*
void Empleado::setUsuario(QString usuario)
{
    this->usuario = usuario;
}

void Empleado::setContrasenia(QString contrasenia)
{
    this->contrasenia = contrasenia;
}
*/
// Metodo para agregar empleados
bool Empleado::agregarEmpleadoNuevo()
{
    //Limpia la pantalla
    agregar.limpiarPantalla();

    qDebug() << "ingreso";

    int respuesta; // Para saber si se apreto ok o cancelar

    respuesta = agregar.exec(); // Se abre ventana

    // si se apreta cancelar, se sale del programa sino se toman los datos del formularioAgregar
    if(respuesta == QDialog::Rejected) return false;
    else {
        qDebug() << "ingreso1";

        QString nombre = agregar.nombre();
        QString apellido = agregar.apellido();
        int dni = agregar.dni();
        int telefono = agregar.telefono();
        int idEmpleado = agregar.idEmpleado();

        //Validamos que todos los campos esten llenos
        if (nombre.isEmpty() || apellido.isEmpty() || dni == false || telefono == false || idEmpleado == false){
            QMessageBox::warning(this, "Error", "Error al cargar empleado");
            return false;
        } else {
           // Empleado* empleado = new Empleado(nombre, apellido, dni, telegono, idEmpleado);
            Empleado* empleado = new Empleado(idEmpleado);

           qDebug() << "idEmpleado:" << idEmpleado;

           // se agrega la persona al vector
           vecEmpleados.push_back(empleado);

           // Llama a la funcion mostrarPersonas en la tabla
           mostrarEmpleados();
        }
    }
}

// Metodo para eliminar empleados
bool Empleado::eliminarEmpleado()
{
    qDebug() << "entro";

    // Declaramos un iterador tipo persona para poder recorrer y eliminar la persona seleccionada
    QVector <Empleado*>::iterator it;

    // para obtener la fila seleccionada
    int filaSeleccionada = ui->tablaEmpleado->currentRow();

    // Si no se selecciona nada salta error
    if (filaSeleccionada == -1) {
        QMessageBox::warning(this, "Error", "Seleccione un empleado para eliminar.");
        return false;
    }

    // Buscamos la persona con el numero de dni
    QString idEmpleadoSeleccionado = ui->tablaEmpleado->item(filaSeleccionada, 5)->text();

    bool seEncontro = false;

    for (it = vecEmpleados.begin(); it != vecEmpleados.end(); ){

        if (QString::number((*it)->getIdEmpleado()) == idEmpleadoSeleccionado) {
        //if (idEmpleadoSeleccionado == QString::number(*it.id)) {

            // Libera la memoria asignada al empleado
            delete *it;

            // lo elimina del vector
            it = vecEmpleados.erase(it);

            // lo elimina de la tabla
            ui->tablaEmpleado->removeRow(filaSeleccionada);

            seEncontro = true;
            break;
        } else {
            ++it;
        }
    }

    if (!seEncontro) QMessageBox::warning(this, "Error", "No se encontro la persona", QMessageBox::Ok);
}

// Metodo para modificar empleados
bool Empleado::modificarEmpleado()
{
    int filaSeleccionada = ui->tablaEmpleado->currentRow();

    qDebug() << "Fila selecciona" << filaSeleccionada;

    if (filaSeleccionada >= 0) {

        // tomamos el empleado de la fila selacciona
        Empleado* empleadoSeleccionado = vecEmpleados[filaSeleccionada];

        int respuesta; // Para saber si se apreto ok o cancelar

        respuesta = agregar.exec(); // Se abre ventana

        // Llenar los datos en el formulario
        //Llenar una vez que esten los atributos de persona
        agregar.llenarFormulario(empleadoSeleccionado->getIdEmpleado());

        // si se apreta cancelar, se sale del programa sino se toman los datos del formularioAgregar
        if(respuesta == QDialog::Rejected) return false;

        else {
            // se modifican los datos del empleado
        /*    empleadoSeleccionado.setNombre(agregar.nombre());
            empleadoSeleccionado.setApellido(agregar.apellido());
            empleadoSeleccionado.setDni(agregar.dni());
            empleadoSeleccionado.setDireccion(agregar.direccion());
            empleadoSeleccionado.setTelefono(agregar.telefono());   */
            empleadoSeleccionado->setIdEmpleado(agregar.idEmpleado());

            qDebug() << "idEmpleado: " << empleadoSeleccionado->getIdEmpleado();

            agregar.accept();

            mostrarEmpleados();
        }
    } else {
        QMessageBox::warning(this, "Error", "Se debe seleccionar un empleado");
    }
}

void Empleado::mostrarEmpleados()
{
    // limpia la tabla
    ui->tablaEmpleado->setRowCount(0);

    // Recorre el vector y muestra cada persona en una nueva fila en la tabla
    for (const Empleado* empleado : vecEmpleados) {

        // almacenamos la cantidad de filas
        int row = ui->tablaEmpleado->rowCount();

        ui->tablaEmpleado->insertRow(row);

        // Agrega en la fila los datos que corresponden en la columna
    /*    ui->tablaEmpleado->setItem(row, 0, new QTableWidgetItem(persona.apellido));
        ui->tablaEmpleado->setItem(row, 1, new QTableWidgetItem(persona.nombre));
        ui->tablaEmpleado->setItem(row, 2, new QTableWidgetItem(QString::number(persona.dni)));
        ui->tablaEmpleado->setItem(row, 3, new QTableWidgetItem(persona.direccion));
        ui->tablaEmpleado->setItem(row, 4, new QTableWidgetItem(QString::number(persona.telefono))); */
        ui->tablaEmpleado->setItem(row, 5, new QTableWidgetItem(QString::number(empleado->idEmpleado)));
    }
}




