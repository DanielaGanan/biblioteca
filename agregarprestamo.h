#ifndef AGREGARPRESTAMO_H
#define AGREGARPRESTAMO_H

#include <QDialog>
#include "libro.h"
#include "socio.h"
#include "empleado.h"
#include "QDate"
#include "QDebug"
#include "QMessageBox"

namespace Ui {
class agregarPrestamo;
}

class agregarPrestamo : public QDialog
{
    Q_OBJECT

public:
    explicit agregarPrestamo(QWidget *parent = nullptr);
    ~agregarPrestamo();

    int idPrestamo(); // Retorna idPrestamo
    libro Libros(); // Retorna el libro
    // Socio socio(); // Retorna el socio
    int cantidad(); // Retorna la cantidad
    Empleado empleado(); //Retorna empleado
    QDate fechaPrestamo(); // Retorna la fecha del prestamo
    QDate fechaDevolucion(); // Retorna la fecha en que se debe devolver


    void limpiarPantalla();
    /* void llenarFormulario(QString nombre, QString apellido, QString dni, QString direccion,
                          QString telefono, int idEmpleado); */

    void llenarFormulario();
    int validarNumero(QLineEdit* num);

public slots:
    // Metodos para saber que presiona el usuario en el Qdialog
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::agregarPrestamo *ui;
    QVector <libro*> libros;
    //QVector <Socio*> Socios;
    QVector <Empleado*> empleados;
};

#endif // AGREGARPRESTAMO_H
