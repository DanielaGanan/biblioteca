#ifndef TABLALIBROS_H
#define TABLALIBROS_H
#include <QWidget>
#include <QTableWidgetItem>
#include <libro.h>
#include <QDialog>
#include <QMessageBox>
#include <agregarnuevolibro.h>
#include <qdatetime.h>
#include <QFile>

namespace Ui {
class tablaLibros;
}

class tablaLibros : public QWidget
{
    Q_OBJECT

public:
    explicit tablaLibros(QWidget *parent = nullptr);
    ~tablaLibros();

private slots:
    void onAgregarLibro();
    void onModificarLibro();
    void onEliminarLibro();
    void actualizarLibro(int fila, const libro &libro);
    void filtrarLibros();
    void mostrarTodosLosLibros();
    void guardarEnCSV();
    void cargarDesdeCSV();

private:
    Ui::tablaLibros *ui;
    QList<libro> &libros;  // Referencia a la lista estática 'libros'
    void actualizarTabla();
};

#endif // TABLALIBROS_H
