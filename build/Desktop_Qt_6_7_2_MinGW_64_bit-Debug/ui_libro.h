/********************************************************************************
** Form generated from reading UI file 'libro.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIBRO_H
#define UI_LIBRO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Libro
{
public:
    QPushButton *eliminarLibro;
    QPushButton *modificarLibro;
    QPushButton *agregarLibro;
    QTableWidget *tabla;

    void setupUi(QWidget *Libro)
    {
        if (Libro->objectName().isEmpty())
            Libro->setObjectName("Libro");
        Libro->resize(672, 355);
        eliminarLibro = new QPushButton(Libro);
        eliminarLibro->setObjectName("eliminarLibro");
        eliminarLibro->setGeometry(QRect(400, 250, 80, 24));
        modificarLibro = new QPushButton(Libro);
        modificarLibro->setObjectName("modificarLibro");
        modificarLibro->setGeometry(QRect(270, 250, 80, 24));
        agregarLibro = new QPushButton(Libro);
        agregarLibro->setObjectName("agregarLibro");
        agregarLibro->setGeometry(QRect(140, 250, 80, 24));
        tabla = new QTableWidget(Libro);
        if (tabla->columnCount() < 5)
            tabla->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tabla->setObjectName("tabla");
        tabla->setGeometry(QRect(60, 50, 501, 192));
        tabla->setAutoScrollMargin(10);
        tabla->setAlternatingRowColors(true);
        tabla->setSelectionMode(QAbstractItemView::SelectionMode::MultiSelection);
        tabla->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        tabla->horizontalHeader()->setDefaultSectionSize(100);

        retranslateUi(Libro);

        QMetaObject::connectSlotsByName(Libro);
    } // setupUi

    void retranslateUi(QWidget *Libro)
    {
        Libro->setWindowTitle(QCoreApplication::translate("Libro", "Form", nullptr));
        eliminarLibro->setText(QCoreApplication::translate("Libro", "Eliminar", nullptr));
        modificarLibro->setText(QCoreApplication::translate("Libro", "Modificar", nullptr));
        agregarLibro->setText(QCoreApplication::translate("Libro", "Agregar", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tabla->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Libro", "Titulo", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tabla->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Libro", "Autor", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tabla->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Libro", "Editorial", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tabla->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Libro", "A\303\261o", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tabla->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Libro", "Stock", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Libro: public Ui_Libro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIBRO_H
