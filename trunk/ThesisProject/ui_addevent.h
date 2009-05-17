/********************************************************************************
** Form generated from reading ui file 'addevent.ui'
**
** Created: Mon 11. May 18:36:00 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_ADDEVENT_H
#define UI_ADDEVENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddEventClass
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *idEvent;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QRadioButton *teclaOption;
    QRadioButton *appOption;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *appEdit;
    QToolButton *findApp;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *argsEdit;
    QCheckBox *argCheck;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *changeButton;
    QPushButton *acceptButton;

    void setupUi(QDialog *AddEventClass)
    {
        if (AddEventClass->objectName().isEmpty())
            AddEventClass->setObjectName(QString::fromUtf8("AddEventClass"));
        AddEventClass->resize(547, 327);
        verticalLayout = new QVBoxLayout(AddEventClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setMargin(11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(AddEventClass);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setMargin(11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        idEvent = new QLineEdit(widget);
        idEvent->setObjectName(QString::fromUtf8("idEvent"));

        horizontalLayout_3->addWidget(idEvent);


        verticalLayout->addWidget(widget);

        groupBox = new QGroupBox(AddEventClass);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setMargin(11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        teclaOption = new QRadioButton(groupBox);
        teclaOption->setObjectName(QString::fromUtf8("teclaOption"));
        teclaOption->setChecked(false);

        horizontalLayout->addWidget(teclaOption);

        appOption = new QRadioButton(groupBox);
        appOption->setObjectName(QString::fromUtf8("appOption"));
        appOption->setLayoutDirection(Qt::RightToLeft);
        appOption->setChecked(false);

        horizontalLayout->addWidget(appOption);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(AddEventClass);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setEnabled(false);
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setMargin(11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(226, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(24, 16));
        label_2->setMaximumSize(QSize(24, 16));

        gridLayout_2->addWidget(label_2, 0, 1, 1, 1);

        comboBox = new QComboBox(groupBox_2);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMinimumSize(QSize(69, 20));
        comboBox->setMaximumSize(QSize(69, 20));
        comboBox->setLayoutDirection(Qt::LeftToRight);

        gridLayout_2->addWidget(comboBox, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(225, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 3, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(AddEventClass);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setEnabled(false);
        gridLayout = new QGridLayout(groupBox_3);
        gridLayout->setSpacing(6);
        gridLayout->setMargin(11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        appEdit = new QLineEdit(groupBox_3);
        appEdit->setObjectName(QString::fromUtf8("appEdit"));
        appEdit->setEnabled(false);
        appEdit->setReadOnly(true);

        gridLayout->addWidget(appEdit, 0, 1, 1, 2);

        findApp = new QToolButton(groupBox_3);
        findApp->setObjectName(QString::fromUtf8("findApp"));

        gridLayout->addWidget(findApp, 0, 3, 1, 1);

        widget_2 = new QWidget(groupBox_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setEnabled(false);
        horizontalLayout_4 = new QHBoxLayout(widget_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setMargin(11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_4->addWidget(label_4);

        argsEdit = new QLineEdit(widget_2);
        argsEdit->setObjectName(QString::fromUtf8("argsEdit"));
        argsEdit->setEnabled(false);

        horizontalLayout_4->addWidget(argsEdit);


        gridLayout->addWidget(widget_2, 1, 1, 1, 3);

        argCheck = new QCheckBox(groupBox_3);
        argCheck->setObjectName(QString::fromUtf8("argCheck"));
        argCheck->setChecked(false);

        gridLayout->addWidget(argCheck, 1, 0, 1, 1);


        verticalLayout->addWidget(groupBox_3);

        widget_3 = new QWidget(AddEventClass);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_5 = new QHBoxLayout(widget_3);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setMargin(11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        changeButton = new QPushButton(widget_3);
        changeButton->setObjectName(QString::fromUtf8("changeButton"));

        horizontalLayout_5->addWidget(changeButton);

        acceptButton = new QPushButton(widget_3);
        acceptButton->setObjectName(QString::fromUtf8("acceptButton"));

        horizontalLayout_5->addWidget(acceptButton);


        verticalLayout->addWidget(widget_3);


        retranslateUi(AddEventClass);
        QObject::connect(teclaOption, SIGNAL(toggled(bool)), groupBox_2, SLOT(setEnabled(bool)));
        QObject::connect(changeButton, SIGNAL(clicked()), AddEventClass, SLOT(reject()));
        QObject::connect(appOption, SIGNAL(toggled(bool)), groupBox_3, SLOT(setEnabled(bool)));
        QObject::connect(argCheck, SIGNAL(clicked(bool)), argsEdit, SLOT(setEnabled(bool)));
        QObject::connect(appOption, SIGNAL(toggled(bool)), appEdit, SLOT(setEnabled(bool)));
        QObject::connect(appOption, SIGNAL(toggled(bool)), widget_2, SLOT(setEnabled(bool)));
        QObject::connect(appOption, SIGNAL(toggled(bool)), argsEdit, SLOT(setDisabled(bool)));
        QObject::connect(findApp, SIGNAL(clicked()), AddEventClass, SLOT(openExecutableFile()));
        QObject::connect(appOption, SIGNAL(toggled(bool)), findApp, SLOT(setEnabled(bool)));
        QObject::connect(acceptButton, SIGNAL(clicked()), AddEventClass, SLOT(accept()));

        QMetaObject::connectSlotsByName(AddEventClass);
    } // setupUi

    void retranslateUi(QDialog *AddEventClass)
    {
        AddEventClass->setWindowTitle(QApplication::translate("AddEventClass", "Agregar Evento", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AddEventClass", "Identificador", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        idEvent->setToolTip(QApplication::translate("AddEventClass", "Cargue el nombre del identificador del evento", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        groupBox->setTitle(QApplication::translate("AddEventClass", "Tipo de Evento", 0, QApplication::UnicodeUTF8));
        teclaOption->setText(QApplication::translate("AddEventClass", "Simulaci\303\263n de Tecla", 0, QApplication::UnicodeUTF8));
        appOption->setText(QApplication::translate("AddEventClass", "Ejecuci\303\263n de aplicaci\303\263n", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("AddEventClass", "Simulaci\303\263n de Tecla", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AddEventClass", "Tecla", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("AddEventClass", "Up", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AddEventClass", "Down", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AddEventClass", "Right", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AddEventClass", "Left", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AddEventClass", "Esc", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AddEventClass", "Space", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AddEventClass", "Intro", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AddEventClass", "Tab", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AddEventClass", "F5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AddEventClass", "Pg.Up", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AddEventClass", "Pg.Dn", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AddEventClass", "Alt+Tab", 0, QApplication::UnicodeUTF8)
        );
        groupBox_3->setTitle(QApplication::translate("AddEventClass", "Ejecuci\303\263n de aplicaci\303\263n", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AddEventClass", "Aplicaci\303\263n o Archivo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        findApp->setToolTip(QApplication::translate("AddEventClass", "Seleccione la aplicaci\303\263n a ejecutar", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        findApp->setText(QApplication::translate("AddEventClass", "...", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AddEventClass", "Argumentos", 0, QApplication::UnicodeUTF8));
        argCheck->setText(QApplication::translate("AddEventClass", "\302\277Argumentos?", 0, QApplication::UnicodeUTF8));
        changeButton->setText(QApplication::translate("AddEventClass", "Cancelar", 0, QApplication::UnicodeUTF8));
        acceptButton->setText(QApplication::translate("AddEventClass", "Aceptar", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(AddEventClass);
    } // retranslateUi

};

namespace Ui {
    class AddEventClass: public Ui_AddEventClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEVENT_H
