#ifndef AGREGAREMPLEADO_H
#define AGREGAREMPLEADO_H

#include <QDialog>
#include "QDebug"
#include "QMessageBox"

namespace Ui {
class agregarEmpleado;
}

class agregarEmpleado : public QDialog
{
    Q_OBJECT

public:
    explicit agregarEmpleado(QWidget *parent = nullptr);
    ~agregarEmpleado();

public slots:
    // Metodos para saber que presiona el usuario en el Qdialog
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    QString nombre(); // Retorna nombre
    QString apellido(); // Retorna apellido
    int dni(); // Retorna dni
    QString direccion(); // Retorna observaciones
    int telefono();
    int idEmpleado();

    void limpiarPantalla();

private:
    Ui::agregarEmpleado *ui;
};

#endif // AGREGAREMPLEADO_H
