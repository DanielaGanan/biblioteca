#ifndef AGREGARPRESTAMO_H
#define AGREGARPRESTAMO_H

#include <QDialog>
#include <libro.h>
#include <socio.h>
#include <claseprestamo.h>
#include <usuario.h>
#include "QMessageBox"
#include "QLineEdit"
#include "QDate"
#include "QDebug"
#include <mainwindow.h>


namespace Ui {
class agregarPrestamo;
}

class agregarPrestamo : public QDialog
{
    Q_OBJECT

public:
    explicit agregarPrestamo(QWidget *parent = nullptr);
    ~agregarPrestamo();


    clasePrestamo* getPrestamo() const;
    void setPrestamoEditar(int idPrestamo, int cantidad, const QDate& fechaPrestamo,
                           const QDate& fechaDevolucion, Usuario* usuario);

    int validarNumero(QLineEdit* num);
    void llenarComboBox(const QList<Usuario>& usuarios);


public slots:
    void on_aceptar();

private:
    Ui::agregarPrestamo *ui;
    clasePrestamo *prestamo;
    Usuario* usuario;
    // Socio socio;
    // Libro libro;
    MainWindow *mainWindow;

};

#endif // AGREGARPRESTAMO_H
