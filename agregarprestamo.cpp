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

    // Validaciones iniciales
    if (ui->cantidadQLine->text().isEmpty() || ui->idPrestamoQLine->text().isEmpty() ||
        !ui->calendarfechaPrest->selectedDate().isValid() || !ui->calendarfecheDev->selectedDate().isValid()) {
        QMessageBox::warning(this, "Advertencia", "Los campos no pueden estar vacíos y ambas fechas deben ser válidas.");
        reject();
        return;
    }

    if (validarNumero(ui->idPrestamoQLine) == -1 || validarNumero(ui->cantidadQLine) == -1) return;

    QDate fechaPrestamo = ui->calendarfechaPrest->selectedDate();
    QDate fechaDevolucion = ui->calendarfecheDev->selectedDate();

    if (fechaDevolucion < fechaPrestamo) {
        QMessageBox::warning(this, "Error", "La fecha de devolución no puede ser anterior a la fecha de préstamo.");
        return;
    }

    // Se configura la clase prestamo
    clasePrestamos.setIdPrestamo(validarNumero(ui->idPrestamoQLine));
    clasePrestamos.setFechaPrestamo(fechaPrestamo);
    clasePrestamos.setFechaDevolucion(fechaDevolucion);

    // Obtener la cantidad de libros para prestar
    int cantidad = validarNumero(ui->cantidadQLine);
    clasePrestamos.setCantidad(cantidad);

    // Configurar Libro
    int indexLibro = ui->libroComboBox->currentIndex();
    if (indexLibro >= 0) { // Validar que el índice sea válido
        QString isbnLibro = ui->libroComboBox->itemData(indexLibro).toString(); // Obtener el ISBN seleccionado

        // Buscar en la lista de libros el correspondiente al ISBN seleccionado
        for (libro& libroData : mainWindow->libros) {
            if (libroData.getIsbn() == isbnLibro) {
                if (cantidad > libroData.getStock()) {
                    QMessageBox::warning(this, "Stock insuficiente", "No hay suficientes libros en stock para realizar este préstamo.");
                    return; // Salir de la función si no hay suficiente stock
                }

                // Si el stock es suficiente, actualizar el stock
                int stock = libroData.getStock() - cantidad;
                libroData.setStock(stock);

                // Asignar el libro al objeto clasePrestamos
                clasePrestamos.setlibro(isbnLibro);
                break; // Salir del bucle una vez encontrado
            }
        }
    }

    // Configurar Usuario
    int indexUsuario = ui->empleadoComboBox->currentIndex();
    if (indexUsuario >= 0) { // Validar que el índice sea válido
        QString dniUsuario = ui->empleadoComboBox->itemData(indexUsuario).toString();

        // Buscar en la lista de usuarios el correspondiente al DNI seleccionado
        for (const QStringList& usuarioData : mainWindow->usuarios) {
            if (usuarioData.size() >= 3 && usuarioData[2] == dniUsuario) { // Verificar el índice correcto del DNI
                // Asignar el usuario al objeto clasePrestamos
                clasePrestamos.setUsuario(dniUsuario);
                break; // Salir del bucle una vez encontrado
            }
        }
    }

    // Configurar Socio
    int indexSocio = ui->socioComboBox->currentIndex();
    if (indexSocio >= 0) { // Validar que el índice sea válido
        QString dniSocio = ui->socioComboBox->itemData(indexSocio).toString();

        // Buscar en la lista de usuarios el correspondiente al DNI seleccionado
        for (const QStringList& socioData : mainWindow->socios) {
            if (socioData.size() >= 3 && socioData[2] == dniSocio) { // Verificar el índice correcto del DNI
                // Asignar el usuario al objeto clasePrestamos
                clasePrestamos.setsocio(dniSocio);
                break; // Salir del bucle una vez encontrado
            }
        }
    }

    // Validar que los datos están configurados correctamente
    qDebug() << "Usuario:" << clasePrestamos.getUsuario();
    qDebug() << "Socio:" << clasePrestamos.getsocio();

    accept();

}

QStringList agregarPrestamo::getPrestamo() const{

    QStringList clasePrestamos;


    clasePrestamos.append(QString::number(this->clasePrestamos.getIdPrestamo()));
    clasePrestamos.append(QString::number(this->clasePrestamos.getCantidad()));
    clasePrestamos.append(this->clasePrestamos.getlibro());
    clasePrestamos.append(this->clasePrestamos.getsocio());
    clasePrestamos.append(this->clasePrestamos.getUsuario());
    clasePrestamos.append(this->clasePrestamos.getFechaPrestamo().toString("yyyy-MM-dd"));
    clasePrestamos.append(this->clasePrestamos.getFechaDevolucion().toString("yyyy-MM-dd"));


    qDebug() << "prestamo" << clasePrestamos;

    return clasePrestamos;
}

void agregarPrestamo::setPrestamoEditar(QStringList prestamo) {

    ui->idPrestamoQLine->setText(prestamo[0]);
    ui->cantidadQLine->setText(prestamo[1]);

    // Cargar las fechas en los calendarios
    QDate fecha = QDate::fromString(prestamo[5], "yyyy-MM-dd");  // Ajusta el formato según el formato de tu fecha
    ui->calendarfechaPrest->setSelectedDate(fecha);

    QDate fecha2 = QDate::fromString(prestamo[6], "yyyy-MM-dd");  // Ajusta el formato según el formato de tu fecha
    ui->calendarfecheDev->setSelectedDate(fecha2);

}

void agregarPrestamo::llenarComboBoxUsuario(const QVector<QStringList>& usuarios) {
    ui->empleadoComboBox->clear(); // Limpia el ComboBox para evitar duplicados

    for (const QStringList& usuario : usuarios) {
        if (usuario.size() >= 2) { // Asegúrate de que hay datos suficientes
            QString nombreCompleto = usuario[0] + " " + usuario[1]; // Asume que índice 1 = nombre, 2 = apellido
            QString dni = usuario[2]; // Índice 0 = DNI

            QString textoCombo = nombreCompleto + " (" + dni + ")";

            // Agrega el nombre al ComboBox y asocia el DNI
            ui->empleadoComboBox->addItem(textoCombo, dni);
        }
    }
}


void agregarPrestamo::llenarComboBoxSocio(const QVector<QStringList>& socios) {
    ui->socioComboBox->clear(); // Limpia el ComboBox para evitar duplicados

    for (const QStringList& socio : socios) {

        if(socio.size()>= 6 && socio[5] == "Activo"){
                QString nombreCompleto = socio[0] + " " + socio[1]; // Asume que índice 1 = nombre, 2 = apellido
                QString dni = socio[2]; // Índice 0 = DNI

                QString textoCombo = nombreCompleto + " (" + dni + ")";

                // Agrega el nombre al ComboBox y asocia el DNI
                ui->socioComboBox->addItem(textoCombo, dni);
        }
    }
}


void agregarPrestamo::llenarComboBoxLibros(const QList<libro>& libros) {
    ui->libroComboBox->clear(); // Limpia el ComboBox para evitar duplicados

    for (const libro& l : libros) {
        // Validar que el libro tenga stock disponible
        if (l.getStock() > 0) {
            QString titulo = l.getTitulo(); // Obtener el título del libro
            QString isbn = l.getIsbn();    // Obtener el ISBN del libro (o algún identificador único)

            // Agrega el título al ComboBox y asocia el ISBN
            ui->libroComboBox->addItem(titulo, isbn);
        }
    }
}

