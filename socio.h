#ifndef SOCIO_H
#define SOCIO_H

#include <QWidget>

namespace Ui {
class Socio;
}

class Socio : public QWidget
{
    Q_OBJECT

public:
    explicit Socio(QWidget *parent = nullptr);
    ~Socio();

private:
    Ui::Socio *ui;
};

#endif // SOCIO_H
