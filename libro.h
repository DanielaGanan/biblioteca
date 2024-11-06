#ifndef LIBRO_H
#define LIBRO_H

#include <QWidget>

namespace Ui {
class Libro;
}

class Libro : public QWidget
{
    Q_OBJECT

public:
    explicit Libro(QWidget *parent = nullptr);
    ~Libro();

private:
    Ui::Libro *ui;
};

#endif // LIBRO_H
