/********************************************************************************
** Form generated from reading UI file 'pagarcuota.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGARCUOTA_H
#define UI_PAGARCUOTA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PagarCuota
{
public:

    void setupUi(QWidget *PagarCuota)
    {
        if (PagarCuota->objectName().isEmpty())
            PagarCuota->setObjectName("PagarCuota");
        PagarCuota->resize(400, 300);

        retranslateUi(PagarCuota);

        QMetaObject::connectSlotsByName(PagarCuota);
    } // setupUi

    void retranslateUi(QWidget *PagarCuota)
    {
        PagarCuota->setWindowTitle(QCoreApplication::translate("PagarCuota", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PagarCuota: public Ui_PagarCuota {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGARCUOTA_H
