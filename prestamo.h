#ifndef PRESTAMO_H
#define PRESTAMO_H

#include <QWidget>
#include "QDebug"
#include <QDate>

namespace Ui {
class Prestamo;
}

class Prestamo : public QWidget
{
    Q_OBJECT

public:
    explicit Prestamo(QWidget *parent = nullptr);
    ~Prestamo();

private slots:


private:
    Ui::Prestamo *ui;

};

#endif // PRESTAMO_H
