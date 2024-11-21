#ifndef AGREGARPRESTAMO_H
#define AGREGARPRESTAMO_H

#include <QDialog>
#include "libro.h"
#include "socio.h"
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


public slots:

private:
    Ui::agregarPrestamo *ui;

};

#endif // AGREGARPRESTAMO_H
