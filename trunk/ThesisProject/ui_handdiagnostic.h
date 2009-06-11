/*********************************************************************************
** Form generated from reading ui file 'handdiagnostic.ui'
**
** Created: Mon 11. May 18:36:00 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_HANDDIAGNOSTIC_H
#define UI_HANDDIAGNOSTIC_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HandDiagnosticClass
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *handState;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QPushButton *but;

    void setupUi(QDialog *HandDiagnosticClass)
    {
        if (HandDiagnosticClass->objectName().isEmpty())
            HandDiagnosticClass->setObjectName(QString::fromUtf8("HandDiagnosticClass"));
        HandDiagnosticClass->resize(664, 337);
        verticalLayout = new QVBoxLayout(HandDiagnosticClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setMargin(11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(HandDiagnosticClass);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setMargin(11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(320, 240));
        label->setMaximumSize(QSize(320, 240));

        horizontalLayout->addWidget(label);

        handState = new QLabel(widget);
        handState->setObjectName(QString::fromUtf8("handState"));
        handState->setPixmap(QPixmap(QString::fromUtf8(":/HandState/hand_open.jpg")));

        horizontalLayout->addWidget(handState);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(HandDiagnosticClass);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setSpacing(6);
        gridLayout->setMargin(11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        but = new QPushButton(widget_2);
        but->setObjectName(QString::fromUtf8("but"));

        gridLayout->addWidget(but, 0, 0, 1, 1);


        verticalLayout->addWidget(widget_2);


        retranslateUi(HandDiagnosticClass);
        QObject::connect(but, SIGNAL(clicked()), HandDiagnosticClass, SLOT(proceder()));

        QMetaObject::connectSlotsByName(HandDiagnosticClass);
    } // setupUi

    void retranslateUi(QDialog *HandDiagnosticClass)
    {
        HandDiagnosticClass->setWindowTitle(QApplication::translate("HandDiagnosticClass", "Diagn\303\263stico de estado de la mano", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("HandDiagnosticClass", "Obteniendo Imagen...", 0, QApplication::UnicodeUTF8));
        handState->setText(QString());
        but->setText(QApplication::translate("HandDiagnosticClass", "Cargar Mano Abierta", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(HandDiagnosticClass);
    } // retranslateUi

};

namespace Ui {
    class HandDiagnosticClass: public Ui_HandDiagnosticClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HANDDIAGNOSTIC_H
