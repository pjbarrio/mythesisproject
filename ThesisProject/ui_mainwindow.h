/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Thu 28. May 14:14:39 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ThesisProjectClass
{
public:
    QAction *actionAbrir_Configuraci_n;
    QAction *actionGestos;
    QAction *actionSalir;
    QAction *actionAcerca_de;
    QAction *actionSimulaci_n_Tecla;
    QAction *actionEjecuci_n_Aplicaci_n;
    QAction *actionAbrir_Archivo;
    QAction *actionImportar_Todos;
    QAction *actionCombinaci_n_Teclas;
    QAction *actionSalvar_Configuraci_n;
    QAction *action_Detener_Captura;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QFrame *LeftFrame;
    QVBoxLayout *verticalLayout;
    QGroupBox *EntryObjectBox;
    QGridLayout *gridLayout_7;
    QLabel *capturedImage;
    QGroupBox *RotacionBox;
    QHBoxLayout *horizontalLayout_3;
    QWidget *LeftRotacionFrame;
    QGridLayout *gridLayout;
    QCheckBox *XRotationBox;
    QWidget *widget_4;
    QGridLayout *gridLayout_2;
    QCheckBox *YRotationBox;
    QWidget *RightFrame;
    QHBoxLayout *horizontalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *GestureSupport;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_8;
    QPushButton *GestureConfiguration;
    QCheckBox *StateSupport;
    QCheckBox *viewPointer;
    QCheckBox *ClickSupport;
    QGroupBox *ClickGroupBox;
    QGridLayout *gridLayout_3;
    QRadioButton *OpenHandRadio;
    QRadioButton *CloseHandRadio;
    QPushButton *ConfigButton;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *GestosGroupBox;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget_5;
    QGridLayout *gridLayout_4;
    QListWidget *GestosList;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_4;
    QPushButton *addGesto;
    QPushButton *RemoveGesto;
    QGroupBox *EventosGroupBox;
    QHBoxLayout *horizontalLayout_5;
    QWidget *widget_7;
    QGridLayout *gridLayout_5;
    QListWidget *EventosList;
    QWidget *widget_8;
    QVBoxLayout *verticalLayout_5;
    QPushButton *addEvento;
    QPushButton *RemoveEvento;
    QGroupBox *AsociacionGroupBox;
    QHBoxLayout *horizontalLayout_6;
    QWidget *widget_9;
    QGridLayout *gridLayout_6;
    QListWidget *AsociacionList;
    QWidget *widget_10;
    QVBoxLayout *verticalLayout_6;
    QPushButton *addAsociacion;
    QPushButton *RemoveAsociacion;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_7;
    QWidget *widget_11;
    QPushButton *startButton;
    QMenuBar *menubar;
    QMenu *menuConfiguraci_n;
    QMenu *menuImportar;
    QMenu *menuEventos;
    QMenu *menuAcerca_de;
    QMenu *menuControl;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ThesisProjectClass)
    {
        if (ThesisProjectClass->objectName().isEmpty())
            ThesisProjectClass->setObjectName(QString::fromUtf8("ThesisProjectClass"));
        ThesisProjectClass->setEnabled(true);
        ThesisProjectClass->resize(800, 510);
        actionAbrir_Configuraci_n = new QAction(ThesisProjectClass);
        actionAbrir_Configuraci_n->setObjectName(QString::fromUtf8("actionAbrir_Configuraci_n"));
        QIcon icon;
        icon.addPixmap(QPixmap(QString::fromUtf8(":/ToolBar/openconf.jpg")), QIcon::Normal, QIcon::Off);
        actionAbrir_Configuraci_n->setIcon(icon);
        actionGestos = new QAction(ThesisProjectClass);
        actionGestos->setObjectName(QString::fromUtf8("actionGestos"));
        QIcon icon1;
        icon1.addPixmap(QPixmap(QString::fromUtf8(":/ToolBar/gesture.png")), QIcon::Normal, QIcon::Off);
        actionGestos->setIcon(icon1);
        actionSalir = new QAction(ThesisProjectClass);
        actionSalir->setObjectName(QString::fromUtf8("actionSalir"));
        QIcon icon2;
        icon2.addPixmap(QPixmap(QString::fromUtf8(":/ToolBar/minimize.png")), QIcon::Normal, QIcon::Off);
        actionSalir->setIcon(icon2);
        actionAcerca_de = new QAction(ThesisProjectClass);
        actionAcerca_de->setObjectName(QString::fromUtf8("actionAcerca_de"));
        QIcon icon3;
        icon3.addPixmap(QPixmap(QString::fromUtf8(":/ToolBar/about.jpg")), QIcon::Normal, QIcon::Off);
        actionAcerca_de->setIcon(icon3);
        actionSimulaci_n_Tecla = new QAction(ThesisProjectClass);
        actionSimulaci_n_Tecla->setObjectName(QString::fromUtf8("actionSimulaci_n_Tecla"));
        QIcon icon4;
        icon4.addPixmap(QPixmap(QString::fromUtf8(":/ToolBar/key.jpg")), QIcon::Normal, QIcon::Off);
        actionSimulaci_n_Tecla->setIcon(icon4);
        actionEjecuci_n_Aplicaci_n = new QAction(ThesisProjectClass);
        actionEjecuci_n_Aplicaci_n->setObjectName(QString::fromUtf8("actionEjecuci_n_Aplicaci_n"));
        QIcon icon5;
        icon5.addPixmap(QPixmap(QString::fromUtf8(":/ToolBar/ExeApp.jpg")), QIcon::Normal, QIcon::Off);
        actionEjecuci_n_Aplicaci_n->setIcon(icon5);
        actionAbrir_Archivo = new QAction(ThesisProjectClass);
        actionAbrir_Archivo->setObjectName(QString::fromUtf8("actionAbrir_Archivo"));
        QIcon icon6;
        icon6.addPixmap(QPixmap(QString::fromUtf8(":/ToolBar/OpenFile.jpg")), QIcon::Normal, QIcon::Off);
        actionAbrir_Archivo->setIcon(icon6);
        actionImportar_Todos = new QAction(ThesisProjectClass);
        actionImportar_Todos->setObjectName(QString::fromUtf8("actionImportar_Todos"));
        QIcon icon7;
        icon7.addPixmap(QPixmap(QString::fromUtf8(":/ToolBar/importall.jpg")), QIcon::Normal, QIcon::Off);
        actionImportar_Todos->setIcon(icon7);
        actionCombinaci_n_Teclas = new QAction(ThesisProjectClass);
        actionCombinaci_n_Teclas->setObjectName(QString::fromUtf8("actionCombinaci_n_Teclas"));
        QIcon icon8;
        icon8.addPixmap(QPixmap(QString::fromUtf8(":/ToolBar/combined.jpg")), QIcon::Normal, QIcon::Off);
        actionCombinaci_n_Teclas->setIcon(icon8);
        actionSalvar_Configuraci_n = new QAction(ThesisProjectClass);
        actionSalvar_Configuraci_n->setObjectName(QString::fromUtf8("actionSalvar_Configuraci_n"));
        QIcon icon9;
        icon9.addPixmap(QPixmap(QString::fromUtf8(":/ToolBar/saveConfig.jpg")), QIcon::Normal, QIcon::Off);
        actionSalvar_Configuraci_n->setIcon(icon9);
        action_Detener_Captura = new QAction(ThesisProjectClass);
        action_Detener_Captura->setObjectName(QString::fromUtf8("action_Detener_Captura"));
        action_Detener_Captura->setEnabled(false);
        QIcon icon10;
        icon10.addPixmap(QPixmap(QString::fromUtf8(":/ToolBar/Stop.jpg")), QIcon::Normal, QIcon::Off);
        action_Detener_Captura->setIcon(icon10);
        centralwidget = new QWidget(ThesisProjectClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        LeftFrame = new QFrame(centralwidget);
        LeftFrame->setObjectName(QString::fromUtf8("LeftFrame"));
        LeftFrame->setMinimumSize(QSize(388, 438));
        LeftFrame->setFrameShape(QFrame::StyledPanel);
        LeftFrame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(LeftFrame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        EntryObjectBox = new QGroupBox(LeftFrame);
        EntryObjectBox->setObjectName(QString::fromUtf8("EntryObjectBox"));
        EntryObjectBox->setMinimumSize(QSize(368, 321));
        gridLayout_7 = new QGridLayout(EntryObjectBox);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        capturedImage = new QLabel(EntryObjectBox);
        capturedImage->setObjectName(QString::fromUtf8("capturedImage"));
        capturedImage->setMinimumSize(QSize(348, 287));
        capturedImage->setMaximumSize(QSize(348, 287));
        capturedImage->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        gridLayout_7->addWidget(capturedImage, 0, 0, 1, 1);


        verticalLayout->addWidget(EntryObjectBox);

        RotacionBox = new QGroupBox(LeftFrame);
        RotacionBox->setObjectName(QString::fromUtf8("RotacionBox"));
        horizontalLayout_3 = new QHBoxLayout(RotacionBox);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        LeftRotacionFrame = new QWidget(RotacionBox);
        LeftRotacionFrame->setObjectName(QString::fromUtf8("LeftRotacionFrame"));
        gridLayout = new QGridLayout(LeftRotacionFrame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        XRotationBox = new QCheckBox(LeftRotacionFrame);
        XRotationBox->setObjectName(QString::fromUtf8("XRotationBox"));

        gridLayout->addWidget(XRotationBox, 0, 0, 1, 1);


        horizontalLayout_3->addWidget(LeftRotacionFrame);

        widget_4 = new QWidget(RotacionBox);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        gridLayout_2 = new QGridLayout(widget_4);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        YRotationBox = new QCheckBox(widget_4);
        YRotationBox->setObjectName(QString::fromUtf8("YRotationBox"));
        YRotationBox->setLayoutDirection(Qt::RightToLeft);

        gridLayout_2->addWidget(YRotationBox, 0, 0, 1, 1);


        horizontalLayout_3->addWidget(widget_4);


        verticalLayout->addWidget(RotacionBox);


        horizontalLayout->addWidget(LeftFrame);

        RightFrame = new QWidget(centralwidget);
        RightFrame->setObjectName(QString::fromUtf8("RightFrame"));
        horizontalLayout_2 = new QHBoxLayout(RightFrame);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tabWidget = new QTabWidget(RightFrame);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        GestureSupport = new QCheckBox(tab);
        GestureSupport->setObjectName(QString::fromUtf8("GestureSupport"));

        verticalLayout_2->addWidget(GestureSupport);

        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setEnabled(false);
        gridLayout_8 = new QGridLayout(groupBox);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        GestureConfiguration = new QPushButton(groupBox);
        GestureConfiguration->setObjectName(QString::fromUtf8("GestureConfiguration"));

        gridLayout_8->addWidget(GestureConfiguration, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox);

        StateSupport = new QCheckBox(tab);
        StateSupport->setObjectName(QString::fromUtf8("StateSupport"));

        verticalLayout_2->addWidget(StateSupport);

        viewPointer = new QCheckBox(tab);
        viewPointer->setObjectName(QString::fromUtf8("viewPointer"));

        verticalLayout_2->addWidget(viewPointer);

        ClickSupport = new QCheckBox(tab);
        ClickSupport->setObjectName(QString::fromUtf8("ClickSupport"));

        verticalLayout_2->addWidget(ClickSupport);

        ClickGroupBox = new QGroupBox(tab);
        ClickGroupBox->setObjectName(QString::fromUtf8("ClickGroupBox"));
        ClickGroupBox->setEnabled(false);
        gridLayout_3 = new QGridLayout(ClickGroupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        OpenHandRadio = new QRadioButton(ClickGroupBox);
        OpenHandRadio->setObjectName(QString::fromUtf8("OpenHandRadio"));

        gridLayout_3->addWidget(OpenHandRadio, 0, 0, 1, 1);

        CloseHandRadio = new QRadioButton(ClickGroupBox);
        CloseHandRadio->setObjectName(QString::fromUtf8("CloseHandRadio"));
        CloseHandRadio->setLayoutDirection(Qt::RightToLeft);
        CloseHandRadio->setChecked(true);

        gridLayout_3->addWidget(CloseHandRadio, 0, 1, 1, 1);

        ConfigButton = new QPushButton(ClickGroupBox);
        ConfigButton->setObjectName(QString::fromUtf8("ConfigButton"));

        gridLayout_3->addWidget(ConfigButton, 1, 0, 1, 2);


        verticalLayout_2->addWidget(ClickGroupBox);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        GestosGroupBox = new QGroupBox(tab_2);
        GestosGroupBox->setObjectName(QString::fromUtf8("GestosGroupBox"));
        horizontalLayout_4 = new QHBoxLayout(GestosGroupBox);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        widget_5 = new QWidget(GestosGroupBox);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        gridLayout_4 = new QGridLayout(widget_5);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        GestosList = new QListWidget(widget_5);
        GestosList->setObjectName(QString::fromUtf8("GestosList"));

        gridLayout_4->addWidget(GestosList, 0, 0, 1, 1);


        horizontalLayout_4->addWidget(widget_5);

        widget_6 = new QWidget(GestosGroupBox);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        verticalLayout_4 = new QVBoxLayout(widget_6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        addGesto = new QPushButton(widget_6);
        addGesto->setObjectName(QString::fromUtf8("addGesto"));
        QIcon icon11;
        icon11.addPixmap(QPixmap(QString::fromUtf8(":/buttonsImages/Add.jpg")), QIcon::Normal, QIcon::Off);
        addGesto->setIcon(icon11);
        addGesto->setIconSize(QSize(36, 36));

        verticalLayout_4->addWidget(addGesto);

        RemoveGesto = new QPushButton(widget_6);
        RemoveGesto->setObjectName(QString::fromUtf8("RemoveGesto"));
        QIcon icon12;
        icon12.addPixmap(QPixmap(QString::fromUtf8(":/buttonsImages/Remove.jpg")), QIcon::Normal, QIcon::Off);
        RemoveGesto->setIcon(icon12);
        RemoveGesto->setIconSize(QSize(36, 36));

        verticalLayout_4->addWidget(RemoveGesto);


        horizontalLayout_4->addWidget(widget_6);


        verticalLayout_3->addWidget(GestosGroupBox);

        EventosGroupBox = new QGroupBox(tab_2);
        EventosGroupBox->setObjectName(QString::fromUtf8("EventosGroupBox"));
        horizontalLayout_5 = new QHBoxLayout(EventosGroupBox);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        widget_7 = new QWidget(EventosGroupBox);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        gridLayout_5 = new QGridLayout(widget_7);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        EventosList = new QListWidget(widget_7);
        EventosList->setObjectName(QString::fromUtf8("EventosList"));
        EventosList->setSelectionBehavior(QAbstractItemView::SelectItems);

        gridLayout_5->addWidget(EventosList, 0, 0, 1, 1);


        horizontalLayout_5->addWidget(widget_7);

        widget_8 = new QWidget(EventosGroupBox);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        verticalLayout_5 = new QVBoxLayout(widget_8);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        addEvento = new QPushButton(widget_8);
        addEvento->setObjectName(QString::fromUtf8("addEvento"));
        addEvento->setIcon(icon11);
        addEvento->setIconSize(QSize(36, 36));

        verticalLayout_5->addWidget(addEvento);

        RemoveEvento = new QPushButton(widget_8);
        RemoveEvento->setObjectName(QString::fromUtf8("RemoveEvento"));
        RemoveEvento->setIcon(icon12);
        RemoveEvento->setIconSize(QSize(36, 36));

        verticalLayout_5->addWidget(RemoveEvento);


        horizontalLayout_5->addWidget(widget_8);


        verticalLayout_3->addWidget(EventosGroupBox);

        AsociacionGroupBox = new QGroupBox(tab_2);
        AsociacionGroupBox->setObjectName(QString::fromUtf8("AsociacionGroupBox"));
        horizontalLayout_6 = new QHBoxLayout(AsociacionGroupBox);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        widget_9 = new QWidget(AsociacionGroupBox);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        gridLayout_6 = new QGridLayout(widget_9);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        AsociacionList = new QListWidget(widget_9);
        AsociacionList->setObjectName(QString::fromUtf8("AsociacionList"));

        gridLayout_6->addWidget(AsociacionList, 0, 0, 1, 1);


        horizontalLayout_6->addWidget(widget_9);

        widget_10 = new QWidget(AsociacionGroupBox);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        verticalLayout_6 = new QVBoxLayout(widget_10);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        addAsociacion = new QPushButton(widget_10);
        addAsociacion->setObjectName(QString::fromUtf8("addAsociacion"));
        addAsociacion->setIcon(icon11);
        addAsociacion->setIconSize(QSize(36, 36));

        verticalLayout_6->addWidget(addAsociacion);

        RemoveAsociacion = new QPushButton(widget_10);
        RemoveAsociacion->setObjectName(QString::fromUtf8("RemoveAsociacion"));
        RemoveAsociacion->setIcon(icon12);
        RemoveAsociacion->setIconSize(QSize(36, 36));

        verticalLayout_6->addWidget(RemoveAsociacion);


        horizontalLayout_6->addWidget(widget_10);


        verticalLayout_3->addWidget(AsociacionGroupBox);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_7 = new QVBoxLayout(tab_3);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        widget_11 = new QWidget(tab_3);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));

        verticalLayout_7->addWidget(widget_11);

        startButton = new QPushButton(tab_3);
        startButton->setObjectName(QString::fromUtf8("startButton"));

        verticalLayout_7->addWidget(startButton);

        tabWidget->addTab(tab_3, QString());

        horizontalLayout_2->addWidget(tabWidget);


        horizontalLayout->addWidget(RightFrame);

        ThesisProjectClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ThesisProjectClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuConfiguraci_n = new QMenu(menubar);
        menuConfiguraci_n->setObjectName(QString::fromUtf8("menuConfiguraci_n"));
        menuImportar = new QMenu(menuConfiguraci_n);
        menuImportar->setObjectName(QString::fromUtf8("menuImportar"));
        QIcon icon13;
        icon13.addPixmap(QPixmap(QString::fromUtf8(":/ToolBar/import.jpg")), QIcon::Normal, QIcon::Off);
        menuImportar->setIcon(icon13);
        menuEventos = new QMenu(menuImportar);
        menuEventos->setObjectName(QString::fromUtf8("menuEventos"));
        QIcon icon14;
        icon14.addPixmap(QPixmap(QString::fromUtf8(":/ToolBar/Events.jpg")), QIcon::Normal, QIcon::Off);
        menuEventos->setIcon(icon14);
        menuAcerca_de = new QMenu(menubar);
        menuAcerca_de->setObjectName(QString::fromUtf8("menuAcerca_de"));
        menuControl = new QMenu(menubar);
        menuControl->setObjectName(QString::fromUtf8("menuControl"));
        ThesisProjectClass->setMenuBar(menubar);
        statusbar = new QStatusBar(ThesisProjectClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ThesisProjectClass->setStatusBar(statusbar);

        menubar->addAction(menuConfiguraci_n->menuAction());
        menubar->addAction(menuControl->menuAction());
        menubar->addAction(menuAcerca_de->menuAction());
        menuConfiguraci_n->addAction(actionAbrir_Configuraci_n);
        menuConfiguraci_n->addAction(actionSalvar_Configuraci_n);
        menuConfiguraci_n->addSeparator();
        menuConfiguraci_n->addAction(menuImportar->menuAction());
        menuConfiguraci_n->addSeparator();
        menuConfiguraci_n->addAction(actionSalir);
        menuImportar->addAction(menuEventos->menuAction());
        menuImportar->addAction(actionGestos);
        menuEventos->addAction(actionSimulaci_n_Tecla);
        menuEventos->addAction(actionEjecuci_n_Aplicaci_n);
        menuEventos->addAction(actionAbrir_Archivo);
        menuEventos->addAction(actionCombinaci_n_Teclas);
        menuEventos->addSeparator();
        menuEventos->addAction(actionImportar_Todos);
        menuAcerca_de->addAction(actionAcerca_de);
        menuControl->addAction(action_Detener_Captura);

        retranslateUi(ThesisProjectClass);
        QObject::connect(ClickSupport, SIGNAL(clicked(bool)), ClickGroupBox, SLOT(setEnabled(bool)));
        QObject::connect(addGesto, SIGNAL(clicked()), ThesisProjectClass, SLOT(addGesture()));
        QObject::connect(addEvento, SIGNAL(clicked()), ThesisProjectClass, SLOT(addEvent()));
        QObject::connect(addAsociacion, SIGNAL(clicked()), ThesisProjectClass, SLOT(addAsociation()));
        QObject::connect(RemoveGesto, SIGNAL(clicked()), ThesisProjectClass, SLOT(removeGesture()));
        QObject::connect(RemoveEvento, SIGNAL(clicked()), ThesisProjectClass, SLOT(removeEvent()));
        QObject::connect(RemoveAsociacion, SIGNAL(clicked()), ThesisProjectClass, SLOT(removeAsociation()));
        QObject::connect(YRotationBox, SIGNAL(clicked(bool)), ThesisProjectClass, SLOT(rotateY(bool)));
        QObject::connect(XRotationBox, SIGNAL(clicked(bool)), ThesisProjectClass, SLOT(rotateX(bool)));
        QObject::connect(startButton, SIGNAL(clicked()), ThesisProjectClass, SLOT(startApplication()));
        QObject::connect(ConfigButton, SIGNAL(clicked()), ThesisProjectClass, SLOT(runHandDiagnostic()));
        QObject::connect(AsociacionList, SIGNAL(itemChanged(QListWidgetItem*)), ThesisProjectClass, SLOT(analizeChange(QListWidgetItem*)));
        QObject::connect(GestureSupport, SIGNAL(toggled(bool)), groupBox, SLOT(setEnabled(bool)));
        QObject::connect(GestureConfiguration, SIGNAL(clicked()), ThesisProjectClass, SLOT(configureGestureParameters()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ThesisProjectClass);
    } // setupUi

    void retranslateUi(QMainWindow *ThesisProjectClass)
    {
        ThesisProjectClass->setWindowTitle(QApplication::translate("ThesisProjectClass", "Hand Tracking: Mouse virtual multi-funcional", 0, QApplication::UnicodeUTF8));
        actionAbrir_Configuraci_n->setText(QApplication::translate("ThesisProjectClass", "&Abrir Configuraci\303\263n", 0, QApplication::UnicodeUTF8));
        actionAbrir_Configuraci_n->setIconText(QApplication::translate("ThesisProjectClass", "Abrir Configuraci\303\263n", 0, QApplication::UnicodeUTF8));
        actionAbrir_Configuraci_n->setShortcut(QApplication::translate("ThesisProjectClass", "Ctrl+A", 0, QApplication::UnicodeUTF8));
        actionGestos->setText(QApplication::translate("ThesisProjectClass", "Gestos", 0, QApplication::UnicodeUTF8));
        actionGestos->setShortcut(QApplication::translate("ThesisProjectClass", "Ctrl+G", 0, QApplication::UnicodeUTF8));
        actionSalir->setText(QApplication::translate("ThesisProjectClass", "&Minimizar", 0, QApplication::UnicodeUTF8));
        actionSalir->setIconText(QApplication::translate("ThesisProjectClass", "Minimizar", 0, QApplication::UnicodeUTF8));
        actionSalir->setShortcut(QApplication::translate("ThesisProjectClass", "Ctrl+Shift+M", 0, QApplication::UnicodeUTF8));
        actionAcerca_de->setText(QApplication::translate("ThesisProjectClass", "Acerca de", 0, QApplication::UnicodeUTF8));
        actionAcerca_de->setShortcut(QApplication::translate("ThesisProjectClass", "Ctrl+K", 0, QApplication::UnicodeUTF8));
        actionSimulaci_n_Tecla->setText(QApplication::translate("ThesisProjectClass", "Simulaci\303\263n Tecla", 0, QApplication::UnicodeUTF8));
        actionSimulaci_n_Tecla->setShortcut(QApplication::translate("ThesisProjectClass", "Ctrl+T", 0, QApplication::UnicodeUTF8));
        actionEjecuci_n_Aplicaci_n->setText(QApplication::translate("ThesisProjectClass", "Ejecuci\303\263n Aplicaci\303\263n", 0, QApplication::UnicodeUTF8));
        actionEjecuci_n_Aplicaci_n->setShortcut(QApplication::translate("ThesisProjectClass", "Ctrl+X", 0, QApplication::UnicodeUTF8));
        actionAbrir_Archivo->setText(QApplication::translate("ThesisProjectClass", "Abrir Archivo", 0, QApplication::UnicodeUTF8));
        actionAbrir_Archivo->setShortcut(QApplication::translate("ThesisProjectClass", "Ctrl+F", 0, QApplication::UnicodeUTF8));
        actionImportar_Todos->setText(QApplication::translate("ThesisProjectClass", "Imp&ortar Todos", 0, QApplication::UnicodeUTF8));
        actionImportar_Todos->setShortcut(QApplication::translate("ThesisProjectClass", "Ctrl+I", 0, QApplication::UnicodeUTF8));
        actionCombinaci_n_Teclas->setText(QApplication::translate("ThesisProjectClass", "Combinaci\303\263n Teclas", 0, QApplication::UnicodeUTF8));
        actionCombinaci_n_Teclas->setShortcut(QApplication::translate("ThesisProjectClass", "Ctrl+Shift+T", 0, QApplication::UnicodeUTF8));
        actionSalvar_Configuraci_n->setText(QApplication::translate("ThesisProjectClass", "Salvar Configuraci\303\263n", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        actionSalvar_Configuraci_n->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        actionSalvar_Configuraci_n->setShortcut(QApplication::translate("ThesisProjectClass", "Ctrl+V", 0, QApplication::UnicodeUTF8));
        action_Detener_Captura->setText(QApplication::translate("ThesisProjectClass", "&Detener Captura", 0, QApplication::UnicodeUTF8));
        action_Detener_Captura->setShortcut(QApplication::translate("ThesisProjectClass", "Ctrl+D", 0, QApplication::UnicodeUTF8));
        EntryObjectBox->setTitle(QApplication::translate("ThesisProjectClass", "Entrada", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        capturedImage->setToolTip(QApplication::translate("ThesisProjectClass", "Configuraci\303\263n actual de c\303\241mara", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        capturedImage->setText(QApplication::translate("ThesisProjectClass", "Obteniendo Imagen...", 0, QApplication::UnicodeUTF8));
        RotacionBox->setTitle(QApplication::translate("ThesisProjectClass", "Rotaci\303\263n", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        XRotationBox->setToolTip(QApplication::translate("ThesisProjectClass", "Rotaci\303\263n horizontal", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        XRotationBox->setText(QApplication::translate("ThesisProjectClass", "Rotar X", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        YRotationBox->setToolTip(QApplication::translate("ThesisProjectClass", "Rotaci\303\263n vertical", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        YRotationBox->setText(QApplication::translate("ThesisProjectClass", "Rotar Y", 0, QApplication::UnicodeUTF8));
        GestureSupport->setText(QApplication::translate("ThesisProjectClass", "Habilitar soporte de gestos", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ThesisProjectClass", "Par\303\241metros del Reconocimiento de gestos", 0, QApplication::UnicodeUTF8));
        GestureConfiguration->setText(QApplication::translate("ThesisProjectClass", "Configurar", 0, QApplication::UnicodeUTF8));
        StateSupport->setText(QApplication::translate("ThesisProjectClass", "Habilitar visualizador de estado", 0, QApplication::UnicodeUTF8));
        viewPointer->setText(QApplication::translate("ThesisProjectClass", "Visualizar puntero del Mouse", 0, QApplication::UnicodeUTF8));
        ClickSupport->setText(QApplication::translate("ThesisProjectClass", "Habilitar Click", 0, QApplication::UnicodeUTF8));
        ClickGroupBox->setTitle(QApplication::translate("ThesisProjectClass", "Estado Click", 0, QApplication::UnicodeUTF8));
        OpenHandRadio->setText(QApplication::translate("ThesisProjectClass", "Mano Abierta", 0, QApplication::UnicodeUTF8));
        CloseHandRadio->setText(QApplication::translate("ThesisProjectClass", "Mano Cerrada", 0, QApplication::UnicodeUTF8));
        ConfigButton->setText(QApplication::translate("ThesisProjectClass", "Configurar", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ThesisProjectClass", "Configuraci\303\263n", 0, QApplication::UnicodeUTF8));
        GestosGroupBox->setTitle(QApplication::translate("ThesisProjectClass", "Gestos", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        GestosList->setToolTip(QApplication::translate("ThesisProjectClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Seleccione los gestos a habilitar</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        addGesto->setToolTip(QApplication::translate("ThesisProjectClass", "Agregar nuevo gesto", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        addGesto->setText(QString());
#ifndef QT_NO_TOOLTIP
        RemoveGesto->setToolTip(QApplication::translate("ThesisProjectClass", "Remover gesto seleccionado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        RemoveGesto->setText(QString());
        EventosGroupBox->setTitle(QApplication::translate("ThesisProjectClass", "Eventos", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        EventosList->setToolTip(QApplication::translate("ThesisProjectClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Seleccione los eventos a habilitar</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        addEvento->setToolTip(QApplication::translate("ThesisProjectClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI'; font-size:9pt;\">Agregar Evento</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        addEvento->setText(QString());
#ifndef QT_NO_TOOLTIP
        RemoveEvento->setToolTip(QApplication::translate("ThesisProjectClass", "Eliminar Evento seleccionado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        RemoveEvento->setText(QString());
        AsociacionGroupBox->setTitle(QApplication::translate("ThesisProjectClass", "Asociaci\303\263n Gestos-Eventos", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        AsociacionList->setToolTip(QApplication::translate("ThesisProjectClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Seleccione las asociaciones Gesto-Evento a habilitar</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        addAsociacion->setToolTip(QApplication::translate("ThesisProjectClass", "Agregar Asociaciones", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        addAsociacion->setText(QString());
#ifndef QT_NO_TOOLTIP
        RemoveAsociacion->setToolTip(QApplication::translate("ThesisProjectClass", "Eliminar Asociaci\303\263n seleccionada", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        RemoveAsociacion->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("ThesisProjectClass", "Entrenamiento", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        startButton->setToolTip(QApplication::translate("ThesisProjectClass", "Comenzar aplicaci\303\263n", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        startButton->setText(QApplication::translate("ThesisProjectClass", "Comenzar", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("ThesisProjectClass", "Comienzo", 0, QApplication::UnicodeUTF8));
        menuConfiguraci_n->setTitle(QApplication::translate("ThesisProjectClass", "&Configuraci\303\263n", 0, QApplication::UnicodeUTF8));
        menuImportar->setTitle(QApplication::translate("ThesisProjectClass", "Importar", 0, QApplication::UnicodeUTF8));
        menuEventos->setTitle(QApplication::translate("ThesisProjectClass", "Eventos", 0, QApplication::UnicodeUTF8));
        menuAcerca_de->setTitle(QApplication::translate("ThesisProjectClass", "Acerca de...", 0, QApplication::UnicodeUTF8));
        menuControl->setTitle(QApplication::translate("ThesisProjectClass", "Control", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ThesisProjectClass: public Ui_ThesisProjectClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
