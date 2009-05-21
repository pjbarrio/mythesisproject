/********************************************************************************
** Form generated from reading ui file 'addasociation.ui'
**
** Created: Thu 21. May 16:17:38 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_ADDASOCIATION_H
#define UI_ADDASOCIATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddAsociationClass
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QListWidget *gestosView;
    QPushButton *addAsociacion;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QListWidget *eventosView;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QListWidget *asociacionesView;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QDialog *AddAsociationClass)
    {
        if (AddAsociationClass->objectName().isEmpty())
            AddAsociationClass->setObjectName(QString::fromUtf8("AddAsociationClass"));
        AddAsociationClass->resize(578, 460);
        verticalLayout = new QVBoxLayout(AddAsociationClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setMargin(11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(AddAsociationClass);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_4 = new QGridLayout(widget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setMargin(11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setMargin(11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gestosView = new QListWidget(groupBox);
        gestosView->setObjectName(QString::fromUtf8("gestosView"));

        gridLayout->addWidget(gestosView, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        addAsociacion = new QPushButton(widget);
        addAsociacion->setObjectName(QString::fromUtf8("addAsociacion"));
        addAsociacion->setEnabled(false);

        gridLayout_4->addWidget(addAsociacion, 0, 1, 1, 1);

        groupBox_2 = new QGroupBox(widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setMargin(11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        eventosView = new QListWidget(groupBox_2);
        eventosView->setObjectName(QString::fromUtf8("eventosView"));

        gridLayout_2->addWidget(eventosView, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 0, 2, 1, 1);

        groupBox_3 = new QGroupBox(widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setMargin(11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        asociacionesView = new QListWidget(groupBox_3);
        asociacionesView->setObjectName(QString::fromUtf8("asociacionesView"));
        asociacionesView->setModelColumn(0);

        gridLayout_3->addWidget(asociacionesView, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_3, 1, 0, 1, 3);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(AddAsociationClass);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setMargin(11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addWidget(widget_2);


        retranslateUi(AddAsociationClass);
        QObject::connect(pushButton_2, SIGNAL(clicked()), AddAsociationClass, SLOT(reject()));
        QObject::connect(pushButton, SIGNAL(clicked()), AddAsociationClass, SLOT(accept()));
        QObject::connect(addAsociacion, SIGNAL(clicked()), AddAsociationClass, SLOT(addSelectedItems()));
        QObject::connect(gestosView, SIGNAL(itemClicked(QListWidgetItem*)), AddAsociationClass, SLOT(saveGestureClicked(QListWidgetItem*)));
        QObject::connect(eventosView, SIGNAL(itemClicked(QListWidgetItem*)), AddAsociationClass, SLOT(saveEventClicked(QListWidgetItem*)));

        QMetaObject::connectSlotsByName(AddAsociationClass);
    } // setupUi

    void retranslateUi(QDialog *AddAsociationClass)
    {
        AddAsociationClass->setWindowTitle(QApplication::translate("AddAsociationClass", "Agregar asociaci\303\263n", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("AddAsociationClass", "Gestos", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        gestosView->setToolTip(QApplication::translate("AddAsociationClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Gestos cargados</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        addAsociacion->setToolTip(QApplication::translate("AddAsociationClass", "Agregar asociaci\303\263n seleccionada", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        addAsociacion->setText(QApplication::translate("AddAsociationClass", "Agregar", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("AddAsociationClass", "Eventos", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        eventosView->setToolTip(QApplication::translate("AddAsociationClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Eventos cargados</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        groupBox_3->setTitle(QApplication::translate("AddAsociationClass", "Asociaciones", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        asociacionesView->setToolTip(QApplication::translate("AddAsociationClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Asociaciones cargadas</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButton_2->setText(QApplication::translate("AddAsociationClass", "Cancelar", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("AddAsociationClass", "Aceptar", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(AddAsociationClass);
    } // retranslateUi

};

namespace Ui {
    class AddAsociationClass: public Ui_AddAsociationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDASOCIATION_H
