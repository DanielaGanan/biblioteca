#include "libro.h"
#include "librodatos.h"
#include "qpushbutton.h"
#include "ui_libro.h"

#include <QMessageBox>
#include <QDialog>
#include <agregarnuevolibro.h>

Libro::Libro(QWidget *parent)
    : QWidget(parent), ui(new Ui::Libro)
{
    ui->setupUi(this);

    connect(ui->agregarLibro, &QPushButton::clicked, this, &Libro::onAgregarLibro);
    connect(ui->modificarLibro, &QPushButton::clicked, this, &Libro::onModificarLibro);
    connect(ui->eliminarLibro, &QPushButton::clicked, this, &Libro::onEliminarLibro);
}

libroDatos::libros(const QString &titulo, const QString &autor, const QString &editorial, int año, int stock)
    : m_titulo(titulo), m_autor(autor), m_editorial(editorial), m_año(año), m_stock(stock)
{}

Libro::~Libro()
{
    delete ui;
}


// ---------------- CLASE LIBRO ---------------
void Libro::onAgregarLibro()
{
    agregarNuevoLibro dialogo(this);
    if (dialogo.exec() == QDialog::Accepted) {
        // Obtén los datos del diálogo
        QString titulo = dialogo.getTitulo();
        QString autor = dialogo.getAutor();
        QString editorial = dialogo.getEditorial();
        int año = dialogo.getAño();
        int stock = dialogo.getStock();

        // Crea un nuevo libro y añádelo a la lista
        Libro nuevoLibro(titulo, autor, editorial, año, stock);
        libros.append(nuevoLibro);

        // Actualiza la tabla
        actualizarTabla();
    }
}
void Libro::actualizarLibro(int fila, const Libro &libroSeleccionado)
{
    // Limpiar datos
    ui->tabla->clearContents();
    // Actualiza el libro en la lista
    libros[fila] = libroSeleccionado;

    // Actualizar solo la fila en la tabla
    ui->tabla->setItem(fila, 0, new QTableWidgetItem(libroSeleccionado.getTitulo()));
    ui->tabla->setItem(fila, 1, new QTableWidgetItem(libroSeleccionado.getAutor()));
    ui->tabla->setItem(fila, 2, new QTableWidgetItem(libroSeleccionado.getEditorial()));
    ui->tabla->setItem(fila, 3, new QTableWidgetItem(QString::number(libroSeleccionado.getAño())));
    ui->tabla->setItem(fila, 4, new QTableWidgetItem(QString::number(libroSeleccionado.getStock())));

}
void Libro::onModificarLibro()
{
    // Obtener la fila seleccionada en la tabla
    int filaSeleccionada = ui->tabla->currentRow();
    if (filaSeleccionada >= 0) {
        // Obtener el libro correspondiente de la lista
        Libro& libroSeleccionado = libros[filaSeleccionada];

        // Crear el diálogo de modificación y cargar los datos actuales
        agregarNuevoLibro dialogo(this);
        dialogo.cargarDatos(libroSeleccionado.getTitulo(), libroSeleccionado.getAutor(),
                            libroSeleccionado.getEditorial(), libroSeleccionado.getAño(),
                            libroSeleccionado.getStock());

        // Mostrar el diálogo y capturar los cambios
        if (dialogo.exec() == QDialog::Accepted) {
            // Actualizar los datos del libro con los valores del diálogo
            libroSeleccionado.setTitulo(dialogo.getTitulo());
            libroSeleccionado.setAutor(dialogo.getAutor());
            libroSeleccionado.setEditorial(dialogo.getEditorial());
            libroSeleccionado.setAño(dialogo.getAño());
            libroSeleccionado.setStock(dialogo.getStock());

            // Llamada a actualizarLibro para actualizar el libro en la lista y la tabla
            actualizarLibro(filaSeleccionada, libroSeleccionado);
        }
    } else {
        QMessageBox::warning(this, "Error", "Por favor selecciona un libro para modificar.");
    }
}
void Libro::onEliminarLibro()
{
    int filaSeleccionada = ui->tabla->currentRow();
    if (filaSeleccionada >= 0) {
        libros.removeAt(filaSeleccionada);
        actualizarTabla();
    } else {
        QMessageBox::warning(this, "Error", "Por favor selecciona un libro para eliminar.");
    }
}
void Libro::actualizarTabla()
{
    ui->tabla->setRowCount(libros.size());

    for (int i = 0; i < libros.size(); ++i) {
        const libroDatos &libroActual = libros[i];

        // Creamos un QVector de QStrings que contiene los valores de cada atributo del libro
        QVector<QString> datosLibro = {
            libroActual.getTitulo(),
            libroActual.getAutor(),
            libroActual.getEditorial(),
            QString::number(libroActual.getAño()),
            QString::number(libroActual.getStock())
        };

        // Asignamos cada valor a la columna correspondiente
        for (int j = 0; j < datosLibro.size(); ++j) {
            ui->tabla->setItem(i, j, new QTableWidgetItem(datosLibro[j]));
        }
    }
}
// ---------------- CLASE LIBRO ---------------
