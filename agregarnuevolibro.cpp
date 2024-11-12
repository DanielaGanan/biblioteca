#include "agregarnuevolibro.h"
#include "ui_agregarnuevolibro.h"
#include <QMessageBox>

agregarNuevoLibro::agregarNuevoLibro(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::agregarNuevoLibro)
{
    ui->setupUi(this);
}

agregarNuevoLibro::~agregarNuevoLibro()
{
    delete ui;
}
QString agregarNuevoLibro::getTitulo() const { return ui->campoTitulo->text(); }
QString agregarNuevoLibro::getAutor() const { return ui->campoAutor->text(); }
QString agregarNuevoLibro::getEditorial() const { return ui->campoEditorial->text(); }
int agregarNuevoLibro::getAño() const { return ui->anioLibro->date().year(); }
int agregarNuevoLibro::getStock() const { return ui->campoStock->value(); }

void agregarNuevoLibro::on_botonAceptar_clicked()
{
    // Obtener los valores de los campos
    QString titulo = ui->campoTitulo->text();
    QString autor = ui->campoAutor->text();
    QString editorial = ui->campoEditorial->text();
    int año = ui->anioLibro->date().year();
    int stock = ui->campoStock->value();

    // Validar que todos los campos estén completos
    if (titulo.isEmpty() || autor.isEmpty() || editorial.isEmpty()) {
        // Mostrar mensaje de error si algún campo está vacío
        QMessageBox::warning(this, "Error", "Todos los campos son obligatorios.");
        return;  // No continuar, ya que hay un error
    }

    // Validar que el año esté en un rango lógico (por ejemplo, mayor que 1800)
    if (año < 1800 || año > QDate::currentDate().year()) {
        QMessageBox::warning(this, "Error", "El año debe estar entre 1800 y el año actual.");
        return;  // No continuar, ya que hay un error
    }

    // Validar que el stock sea un número positivo
    if (stock < 0) {
        QMessageBox::warning(this, "Error", "El stock no puede ser negativo.");
        return;  // No continuar, ya que hay un error
    }

    // Si todo es válido, aceptamos el diálogo
    accept();
}

void agregarNuevoLibro::on_botonCancelar_clicked()
{
    // Cerrar el diálogo sin hacer nada
    reject();
}
void agregarNuevoLibro::cargarDatos(const QString &titulo, const QString &autor, const QString &editorial, int año, int stock)
{
    ui->campoTitulo->setText(titulo);
    ui->campoAutor->setText(autor);
    ui->campoEditorial->setText(editorial);
    ui->anioLibro->setDate(QDate(año, 1, 1));
    ui->campoStock->setValue(stock);
}
