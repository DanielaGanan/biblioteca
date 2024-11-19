#ifndef AGREGAREMPLEADO_H
#define AGREGAREMPLEADO_H

#include <QDialog>
#include "QDebug"
#include "QMessageBox"
#include <QLineEdit>

namespace Ui {
class agregarEmpleado;
}

class agregarEmpleado : public QDialog
{
    Q_OBJECT

public:
    explicit agregarEmpleado(QWidget *parent = nullptr);
    ~agregarEmpleado();

    QString nombre(); // Retorna nombre
    QString apellido(); // Retorna apellido
    int dni(); // Retorna dni
    QString direccion(); // Retorna observaciones
    int telefono();
    int idEmpleado();

    void limpiarPantalla();
    /* void llenarFormulario(QString nombre, QString apellido, QString dni, QString direccion,
                          QString telefono, int idEmpleado); */

    void llenarFormulario(int idEmpleado);
    int validarNumero(QLineEdit* num);

public slots:
    // Metodos para saber que presiona el usuario en el Qdialog
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::agregarEmpleado *ui;

};

#endif // AGREGAREMPLEADO_H
