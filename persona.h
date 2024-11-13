#ifndef PERSONA_H
#define PERSONA_H
#include <stedio.h>


#include <QObject>

class Persona : public QObject
{
    Q_OBJECT
public:
    explicit Persona(QObject *parent = nullptr);

signals:
};

#endif // PERSONA_H
