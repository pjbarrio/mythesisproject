/********************************************************************************
** Form generated from reading ui file 'addgesture.ui'
**
** Created: Mon 11. May 18:36:00 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_ADDGESTURE_H
#define UI_ADDGESTURE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddGestureClass
{
public:
    QGridLayout *gridLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *idGestureEdit;
    QPushButton *add;
    QPushButton *cancelButton;
    QPushButton *acceptButton;

    void setupUi(QDialog *AddGestureClass)
    {
        if (AddGestureClass->objectName().isEmpty())
            AddGestureClass->setObjectName(QString::fromUtf8("AddGestureClass"));
        AddGestureClass->resize(470, 92);
        gridLayout_2 = new QGridLayout(AddGestureClass);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setMargin(11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget = new QWidget(AddGestureClass);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setMargin(11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        idGestureEdit = new QLineEdit(widget);
        idGestureEdit->setObjectName(QString::fromUtf8("idGestureEdit"));

        gridLayout->addWidget(idGestureEdit, 0, 1, 1, 2);

        add = new QPushButton(widget);
        add->setObjectName(QString::fromUtf8("add"));

        gridLayout->addWidget(add, 0, 3, 1, 1);

        cancelButton = new QPushButton(widget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        gridLayout->addWidget(cancelButton, 1, 0, 1, 2);

        acceptButton = new QPushButton(widget);
        acceptButton->setObjectName(QString::fromUtf8("acceptButton"));

        gridLayout->addWidget(acceptButton, 1, 2, 1, 2);


        gridLayout_2->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(AddGestureClass);
        QObject::connect(cancelButton, SIGNAL(clicked()), AddGestureClass, SLOT(reject()));
        QObject::connect(acceptButton, SIGNAL(clicked()), AddGestureClass, SLOT(accept()));
        QObject::connect(add, SIGNAL(clicked()), AddGestureClass, SLOT(newGesture()));

        QMetaObject::connectSlotsByName(AddGestureClass);
    } // setupUi

    void retranslateUi(QDialog *AddGestureClass)
    {
        AddGestureClass->setWindowTitle(QApplication::translate("AddGestureClass", "Agregar Gesto", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AddGestureClass", "Identificador:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        idGestureEdit->setToolTip(QApplication::translate("AddGestureClass", "Cargue nombre del gesto", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        add->setToolTip(QApplication::translate("AddGestureClass", "Proceder a la carga del gesto", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        add->setText(QApplication::translate("AddGestureClass", "Cargar", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("AddGestureClass", "Cancelar", 0, QApplication::UnicodeUTF8));
        acceptButton->setText(QApplication::translate("AddGestureClass", "Aceptar", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(AddGestureClass);
    } // retranslateUi

};

namespace Ui {
    class AddGestureClass: public Ui_AddGestureClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDGESTURE_H
