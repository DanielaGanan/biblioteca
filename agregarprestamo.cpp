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
    prestamo->setIdPrestamo(validarNumero(ui->idPrestamoQLine));

    if(validarNumero(ui->cantidadQLine) == -1)      return; // retorna si la cantidad no es valido
    prestamo->setCantidad(validarNumero(ui->cantidadQLine));


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
    for (const Usuario& usuario : mainWindow->usuarios) {
        if (usuario.obtenerNombre() == nombreSeleccionado && usuario.obtenerApellido() == apellidoSeleccionado) {
            // El nombre y apellido coinciden, realiza la acción deseada
            qDebug() << "Coincide con el usuario: " << nombreSeleccionado << apellidoSeleccionado;
            break;
        }
    }

    accept();
}

clasePrestamo* agregarPrestamo::getPrestamo() const {
    return nullptr;
}

void agregarPrestamo::llenarComboBox(const QList<Usuario>& usuarios){

    for (const Usuario& usuario : usuarios) {
        QString texto = usuario.obtenerNombre() + " " + usuario.obtenerApellido();
        ui->empleadoComboBox->addItem(texto, usuario.obtenerNombre() + ";" + usuario.obtenerApellido());
    }
}



