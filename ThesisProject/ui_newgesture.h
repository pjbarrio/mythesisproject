/********************************************************************************
** Form generated from reading ui file 'newgesture.ui'
**
** Created: Mon 11. May 19:59:40 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_NEWGESTURE_H
#define UI_NEWGESTURE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <GUI/MovementGraph/paintmovement.h>

QT_BEGIN_NAMESPACE

class Ui_NewGestureClass
{
public:
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QWidget *viewWidget;
    QGridLayout *gridLayout_2;
    QPushButton *gestureView;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *reject;
    QPushButton *accept;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_3;
    QWidget *captureWidget;
    QGridLayout *gridLayout_3;
    QLabel *imageLabel;
    QProgressBar *progressBar;
    paintMovement *visualWidget;

    void setupUi(QDialog *NewGestureClass)
    {
        if (NewGestureClass->objectName().isEmpty())
            NewGestureClass->setObjectName(QString::fromUtf8("NewGestureClass"));
        NewGestureClass->resize(713, 484);
        NewGestureClass->setFocusPolicy(Qt::StrongFocus);
        horizontalLayout_2 = new QHBoxLayout(NewGestureClass);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setMargin(11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        widget_3 = new QWidget(NewGestureClass);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout = new QVBoxLayout(widget_3);
        verticalLayout->setSpacing(6);
        verticalLayout->setMargin(11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setSpacing(6);
        gridLayout->setMargin(11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textEdit = new QTextEdit(widget_2);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setMinimumSize(QSize(311, 324));
        textEdit->setMaximumSize(QSize(311, 324));
        textEdit->setReadOnly(true);

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);


        verticalLayout->addWidget(widget_2);

        viewWidget = new QWidget(widget_3);
        viewWidget->setObjectName(QString::fromUtf8("viewWidget"));
        gridLayout_2 = new QGridLayout(viewWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setMargin(11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gestureView = new QPushButton(viewWidget);
        gestureView->setObjectName(QString::fromUtf8("gestureView"));
        gestureView->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(gestureView, 0, 0, 1, 1);


        verticalLayout->addWidget(viewWidget);

        widget = new QWidget(widget_3);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setMargin(11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        reject = new QPushButton(widget);
        reject->setObjectName(QString::fromUtf8("reject"));
        reject->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(reject);

        accept = new QPushButton(widget);
        accept->setObjectName(QString::fromUtf8("accept"));
        accept->setEnabled(false);
        accept->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(accept);


        verticalLayout->addWidget(widget);


        horizontalLayout_2->addWidget(widget_3);

        widget_4 = new QWidget(NewGestureClass);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        verticalLayout_3 = new QVBoxLayout(widget_4);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setMargin(11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        captureWidget = new QWidget(widget_4);
        captureWidget->setObjectName(QString::fromUtf8("captureWidget"));
        gridLayout_3 = new QGridLayout(captureWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setMargin(11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        imageLabel = new QLabel(captureWidget);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        imageLabel->setMinimumSize(QSize(270, 180));
        imageLabel->setMaximumSize(QSize(270, 180));

        gridLayout_3->addWidget(imageLabel, 1, 0, 1, 1);

        progressBar = new QProgressBar(captureWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setMaximum(99);
        progressBar->setValue(24);
        progressBar->setTextVisible(false);

        gridLayout_3->addWidget(progressBar, 0, 0, 1, 1);


        verticalLayout_3->addWidget(captureWidget);

        visualWidget = new paintMovement(widget_4);
        visualWidget->setObjectName(QString::fromUtf8("visualWidget"));
        visualWidget->setMinimumSize(QSize(324, 216));
        visualWidget->setMaximumSize(QSize(324, 216));

        verticalLayout_3->addWidget(visualWidget);


        horizontalLayout_2->addWidget(widget_4);


        retranslateUi(NewGestureClass);
        QObject::connect(accept, SIGNAL(clicked()), NewGestureClass, SLOT(accept()));
        QObject::connect(reject, SIGNAL(clicked()), NewGestureClass, SLOT(reject()));
        QObject::connect(gestureView, SIGNAL(clicked()), NewGestureClass, SLOT(viewGesture()));

        QMetaObject::connectSlotsByName(NewGestureClass);
    } // setupUi

    void retranslateUi(QDialog *NewGestureClass)
    {
        NewGestureClass->setWindowTitle(QApplication::translate("NewGestureClass", "Nuevo Gesto", 0, QApplication::UnicodeUTF8));
        textEdit->setHtml(QApplication::translate("NewGestureClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:600; font-style:italic; text-decoration: underline; color:#005500;\">Pasos para Introducir un gesto:</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600; font-style:italic; color:#005500;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; font-weight:600; color:#00000"
                        "0;\">1.- Presione la barra espaciadora.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; font-weight:600; color:#000000;\">2.- En 5 segundos comenzar\303\241 la lectura. Por lo tanto, posicione la mano frente a la c\303\241mara.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; font-weight:600; color:#000000;\">3.- Para finalizar la carga presione nuevamente la barra espaciadora.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt; font-weight:600; color:#000000;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:600; font-style:italic; text"
                        "-decoration: underline; color:#005500;\">Luego de la carga:</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:11pt; font-weight:600; font-style:italic; text-decoration: underline; color:#005500;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; font-weight:600; color:#000000;\">Puede ver el gesto introducido presionando \"Ver Gesto\".</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; font-weight:600; color:#000000;\">Presione aceptar o cancelar para finalizar.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt; font-weight:600; color:#000000;\"></p>\n"
""
                        "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt; font-weight:600; color:#005500;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        gestureView->setText(QApplication::translate("NewGestureClass", "Ver Gesto", 0, QApplication::UnicodeUTF8));
        reject->setText(QApplication::translate("NewGestureClass", "Cancelar", 0, QApplication::UnicodeUTF8));
        accept->setText(QApplication::translate("NewGestureClass", "Aceptar", 0, QApplication::UnicodeUTF8));
        imageLabel->setText(QApplication::translate("NewGestureClass", "Obteniendo Imagen...", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(NewGestureClass);
    } // retranslateUi

};

namespace Ui {
    class NewGestureClass: public Ui_NewGestureClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWGESTURE_H
