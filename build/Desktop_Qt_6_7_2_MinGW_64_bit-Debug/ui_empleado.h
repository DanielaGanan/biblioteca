/********************************************************************************
** Form generated from reading UI file 'empleado.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLEADO_H
#define UI_EMPLEADO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Empleado
{
public:

    void setupUi(QWidget *Empleado)
    {
        if (Empleado->objectName().isEmpty())
            Empleado->setObjectName("Empleado");
        Empleado->resize(400, 300);

        retranslateUi(Empleado);

        QMetaObject::connectSlotsByName(Empleado);
    } // setupUi

    void retranslateUi(QWidget *Empleado)
    {
        Empleado->setWindowTitle(QCoreApplication::translate("Empleado", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Empleado: public Ui_Empleado {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLEADO_H
