#include <agregarprestamo.h>
#include <ui_agregarprestamo.h>

agregarPrestamo::agregarPrestamo(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::agregarPrestamo)
{
    ui->setupUi(this);

    connect(ui->buttonBox_2, &QDialogButtonBox::accepted, this, &agregarPrestamo::on_aceptar);
    connect(ui->buttonBox_2, &QDialogButtonBox::rejected, this, &agregarPrestamo::reject);
}

agregarPrestamo::~agregarPrestamo()
{
    delete ui;
}

int agregarPrestamo::validarNumero(QLineEdit* num)
{
    // Para verificar que el texto se pudo convertir en un numero
    bool esNumero;

    int numero = num->text().toInt(&esNumero);

    // Verifica si el numero se pudo convertir y que sea positivo
    if (esNumero && numero >= 0) {
        qDebug () << "Se ingreso el numero: " << numero;
        return numero;

    } else {
        qDebug() << "Numero no valido";
        num->clear();
        return -1;
    }
}


void agregarPrestamo::on_aceptar() {

    if(validarNumero(ui->idPrestamoQLine) == -1)      return; // retorna si el id no es valido
    claPrestamo.setIdPrestamo(validarNumero(ui->idPrestamoQLine));

    if(validarNumero(ui->cantidadQLine) == -1)      return; // retorna si la cantidad no es valido
    claPrestamo.setCantidad(validarNumero(ui->cantidadQLine));

    QDate fechaPrestamo = ui->fechaPresDate->date();
    claPrestamo.setFechaPrestamo(fechaPrestamo);

    QDate fechaDevolucion = ui->fechaDevDate_2->date();
    claPrestamo.setFechaDevolucion(fechaDevolucion);


    // Obtener el usuario seleccionado del QComboBox
    QString seleccionUsuario = ui->empleadoComboBox->currentText();

    // Obtiene el nombre y apellido de la selección
    QString nombreSeleccionado, apellidoSeleccionado;
    QStringList nombreApellido = ui->empleadoComboBox->currentData().toString().split(";");
    if (nombreApellido.size() == 2) {
        nombreSeleccionado = nombreApellido[0];
        apellidoSeleccionado = nombreApellido[1];
    }

    // Verificar si el nombre y apellido seleccionado son iguales
    for (Usuario& usuario : mainWindow->usuarios) {
        if (usuario.obtenerNombre() == nombreSeleccionado && usuario.obtenerApellido() == apellidoSeleccionado) {
            qDebug() << "Coincide con el usuario: " << nombreSeleccionado << apellidoSeleccionado;
            claPrestamo.setUsuario(&usuario);
            break;
        }
    }
    accept();
}

clasePrestamo agregarPrestamo::getPrestamo() const {
    return claPrestamo;
}

void agregarPrestamo::llenarComboBox(const QList<Usuario>& usuarios){

    for (const Usuario& usuario : usuarios) {
        QString texto = usuario.obtenerNombre() + " " + usuario.obtenerApellido();
        ui->empleadoComboBox->addItem(texto);  // Solo agregar el texto
    }
}

void agregarPrestamo::setPrestamoEditar(int idPrestamo, int cantidad, const QDate& fechaPrestamo,
                                        const QDate& fechaDevolucion, Usuario* usuario){
    ui->idPrestamoQLine->setText(QString::number(idPrestamo));
    ui->cantidadQLine->setText(QString::number(cantidad));
    ui->fechaPresDate->setDate(fechaPrestamo);
    ui->fechaDevDate_2->setDate(fechaDevolucion);

    QString nombreApellido = usuario->obtenerNombre() + " " + usuario->obtenerApellido();
    int index = ui->empleadoComboBox->findText(nombreApellido);
    if (index != -1) {
        ui->empleadoComboBox->setCurrentIndex(index);
    }


}


