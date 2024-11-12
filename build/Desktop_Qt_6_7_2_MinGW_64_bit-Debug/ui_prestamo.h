/********************************************************************************
** Form generated from reading UI file 'prestamo.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRESTAMO_H
#define UI_PRESTAMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Prestamo
{
public:

    void setupUi(QWidget *Prestamo)
    {
        if (Prestamo->objectName().isEmpty())
            Prestamo->setObjectName("Prestamo");
        Prestamo->resize(400, 300);

        retranslateUi(Prestamo);

        QMetaObject::connectSlotsByName(Prestamo);
    } // setupUi

    void retranslateUi(QWidget *Prestamo)
    {
        Prestamo->setWindowTitle(QCoreApplication::translate("Prestamo", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Prestamo: public Ui_Prestamo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRESTAMO_H
