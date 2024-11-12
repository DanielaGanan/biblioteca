/********************************************************************************
** Form generated from reading UI file 'agregarnuevolibro.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGREGARNUEVOLIBRO_H
#define UI_AGREGARNUEVOLIBRO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_agregarNuevoLibro
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *campoTitulo;
    QLabel *label_2;
    QLineEdit *campoAutor;
    QLabel *label_7;
    QLineEdit *campoGenero;
    QLabel *label_3;
    QLineEdit *campoEditorial;
    QLabel *label_4;
    QDateEdit *anioLibro;
    QLabel *label_6;
    QLineEdit *campoIsbn;
    QLabel *label_5;
    QSpinBox *campoStock;
    QGridLayout *gridLayout_2;
    QPushButton *confirmarCambio;
    QPushButton *cancelarCambio;

    void setupUi(QDialog *agregarNuevoLibro)
    {
        if (agregarNuevoLibro->objectName().isEmpty())
            agregarNuevoLibro->setObjectName("agregarNuevoLibro");
        agregarNuevoLibro->resize(400, 412);
        formLayoutWidget = new QWidget(agregarNuevoLibro);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(30, 30, 321, 301));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        campoTitulo = new QLineEdit(formLayoutWidget);
        campoTitulo->setObjectName("campoTitulo");

        formLayout->setWidget(0, QFormLayout::FieldRole, campoTitulo);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        campoAutor = new QLineEdit(formLayoutWidget);
        campoAutor->setObjectName("campoAutor");

        formLayout->setWidget(1, QFormLayout::FieldRole, campoAutor);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName("label_7");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_7);

        campoGenero = new QLineEdit(formLayoutWidget);
        campoGenero->setObjectName("campoGenero");

        formLayout->setWidget(2, QFormLayout::FieldRole, campoGenero);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        campoEditorial = new QLineEdit(formLayoutWidget);
        campoEditorial->setObjectName("campoEditorial");

        formLayout->setWidget(3, QFormLayout::FieldRole, campoEditorial);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        anioLibro = new QDateEdit(formLayoutWidget);
        anioLibro->setObjectName("anioLibro");

        formLayout->setWidget(4, QFormLayout::FieldRole, anioLibro);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName("label_6");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        campoIsbn = new QLineEdit(formLayoutWidget);
        campoIsbn->setObjectName("campoIsbn");

        formLayout->setWidget(5, QFormLayout::FieldRole, campoIsbn);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName("label_5");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_5);

        campoStock = new QSpinBox(formLayoutWidget);
        campoStock->setObjectName("campoStock");

        formLayout->setWidget(6, QFormLayout::FieldRole, campoStock);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        confirmarCambio = new QPushButton(formLayoutWidget);
        confirmarCambio->setObjectName("confirmarCambio");
        confirmarCambio->setEnabled(true);
        confirmarCambio->setMinimumSize(QSize(0, 40));
        confirmarCambio->setMaximumSize(QSize(100, 100));
        confirmarCambio->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        gridLayout_2->addWidget(confirmarCambio, 0, 0, 1, 1);

        cancelarCambio = new QPushButton(formLayoutWidget);
        cancelarCambio->setObjectName("cancelarCambio");
        cancelarCambio->setMinimumSize(QSize(0, 40));
        cancelarCambio->setMaximumSize(QSize(100, 16777215));

        gridLayout_2->addWidget(cancelarCambio, 0, 1, 1, 1);


        formLayout->setLayout(7, QFormLayout::FieldRole, gridLayout_2);


        retranslateUi(agregarNuevoLibro);

        QMetaObject::connectSlotsByName(agregarNuevoLibro);
    } // setupUi

    void retranslateUi(QDialog *agregarNuevoLibro)
    {
        agregarNuevoLibro->setWindowTitle(QCoreApplication::translate("agregarNuevoLibro", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("agregarNuevoLibro", "     Titulo   ", nullptr));
        label_2->setText(QCoreApplication::translate("agregarNuevoLibro", "     Autor   ", nullptr));
        label_7->setText(QCoreApplication::translate("agregarNuevoLibro", "    Genero  ", nullptr));
        label_3->setText(QCoreApplication::translate("agregarNuevoLibro", "  Editorial    ", nullptr));
        label_4->setText(QCoreApplication::translate("agregarNuevoLibro", "     A\303\261o     ", nullptr));
        label_6->setText(QCoreApplication::translate("agregarNuevoLibro", "    ISBN    ", nullptr));
        label_5->setText(QCoreApplication::translate("agregarNuevoLibro", "    Stock    ", nullptr));
        confirmarCambio->setText(QCoreApplication::translate("agregarNuevoLibro", "OK", nullptr));
        cancelarCambio->setText(QCoreApplication::translate("agregarNuevoLibro", "Cancelar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class agregarNuevoLibro: public Ui_agregarNuevoLibro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGREGARNUEVOLIBRO_H
