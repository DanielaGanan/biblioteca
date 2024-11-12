/********************************************************************************
** Form generated from reading UI file 'socio.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOCIO_H
#define UI_SOCIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Socio
{
public:

    void setupUi(QWidget *Socio)
    {
        if (Socio->objectName().isEmpty())
            Socio->setObjectName("Socio");
        Socio->resize(400, 300);

        retranslateUi(Socio);

        QMetaObject::connectSlotsByName(Socio);
    } // setupUi

    void retranslateUi(QWidget *Socio)
    {
        Socio->setWindowTitle(QCoreApplication::translate("Socio", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Socio: public Ui_Socio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOCIO_H
