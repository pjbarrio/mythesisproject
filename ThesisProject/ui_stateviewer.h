/*********************************************************************************
** Form generated from reading ui file 'stateviewer.ui'
**
** Created: Wed 20. May 17:20:33 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_STATEVIEWER_H
#define UI_STATEVIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <GUI/MovementGraph/paintmovement.h>

QT_BEGIN_NAMESPACE

class Ui_StateViewerClass
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QLabel *processedImage;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLabel *handState;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *vred1;
    QLabel *vred2;
    QLabel *vred3;
    QLabel *vorange1;
    QLabel *vorange2;
    QLabel *vorange3;
    QLabel *vyellow1;
    QLabel *vyellow2;
    QLabel *vyellow3;
    QLabel *vyellowlight1;
    QLabel *vyellowlight2;
    QLabel *vyellowlight3;
    QLabel *vgreen1;
    QLabel *vgreen2;
    QLabel *vgreen3;
    QLabel *vgreendark1;
    QLabel *vgreendark2;
    QLabel *vgreendark3;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *ared1;
    QLabel *ared2;
    QLabel *ared3;
    QLabel *aorange1;
    QLabel *aorange2;
    QLabel *aorange3;
    QLabel *ayellow1;
    QLabel *ayellow2;
    QLabel *ayellow3;
    QLabel *ayellowlight1;
    QLabel *ayellowlight2;
    QLabel *ayellowlight3;
    QLabel *agreen1;
    QLabel *agreen2;
    QLabel *agreen3;
    QLabel *agreendark1;
    QLabel *agreendark2;
    QLabel *agreendark3;
    QLabel *label;
    QLabel *label_2;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_39;
    QLabel *XCoord;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_40;
    QLabel *YCoord;
    paintMovement *widget_4;

    void setupUi(QDialog *StateViewerClass)
    {
        if (StateViewerClass->objectName().isEmpty())
            StateViewerClass->setObjectName(QString::fromUtf8("StateViewerClass"));
        StateViewerClass->resize(650, 723);
        gridLayout = new QGridLayout(StateViewerClass);
        gridLayout->setSpacing(6);
        gridLayout->setMargin(11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(StateViewerClass);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setMargin(11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        processedImage = new QLabel(groupBox);
        processedImage->setObjectName(QString::fromUtf8("processedImage"));
        processedImage->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(processedImage, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 1, 1, 1);

        groupBox_2 = new QGroupBox(StateViewerClass);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(350, 300));
        groupBox_2->setMaximumSize(QSize(350, 300));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setMargin(11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        handState = new QLabel(groupBox_2);
        handState->setObjectName(QString::fromUtf8("handState"));
        handState->setMinimumSize(QSize(320, 240));
        handState->setMaximumSize(QSize(320, 240));
        handState->setPixmap(QPixmap(QString::fromUtf8(":/HandState/hand_open.jpg")));
        handState->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(handState, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(StateViewerClass);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(276, 399));
        groupBox_3->setMaximumSize(QSize(276, 399));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setMargin(11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget = new QWidget(groupBox_3);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setMargin(11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        vred1 = new QLabel(widget);
        vred1->setObjectName(QString::fromUtf8("vred1"));
        vred1->setEnabled(false);
        vred1->setFrameShape(QFrame::NoFrame);
        vred1->setPixmap(QPixmap(QString::fromUtf8(":/GraphicalEqualizer/Red.jpg")));

        verticalLayout->addWidget(vred1);

        vred2 = new QLabel(widget);
        vred2->setObjectName(QString::fromUtf8("vred2"));
        vred2->setEnabled(false);
        vred2->setPixmap(QPixmap(QString::fromUtf8(":/GraphicalEqualizer/Red.jpg")));

        verticalLayout->addWidget(vred2);

        vred3 = new QLabel(widget);
        vred3->setObjectName(QString::fromUtf8("vred3"));
        vred3->setEnabled(false);
        vred3->setPixmap(QPixmap(QString::fromUtf8(":/GraphicalEqualizer/Red.jpg")));

        verticalLayout->addWidget(vred3);

        vorange1 = new QLabel(widget);
        vorange1->setObjectName(QString::fromUtf8("vorange1"));
        vorange1->setEnabled(false);
        vorange1->setPixmap(QPixmap(QString::fromUtf8(":/GraphicalEqualizer/Orange.jpg")));

        verticalLayout->addWidget(vorange1);

        vorange2 = new QLabel(widget);
        vorange2->setObjectName(QString::fromUtf8("vorange2"));
        vorange2->setEnabled(false);
        vorange2->setPixmap(QPixmap(QString::fromUtf8(":/GraphicalEqualizer/Orange.jpg")));

        verticalLayout->addWidget(vorange2);

        vorange3 = new QLabel(widget);
        vorange3->setObjectName(QString::fromUtf8("vorange3"));
        vorange3->setEnabled(false);
        vorange3->setPixmap(QPixmap(QString::fromUtf8(":/GraphicalEqualizer/Orange.jpg")));

        verticalLayout->addWidget(vorange3);

        vyellow1 = new QLabel(widget);
        vyellow1->setObjectName(QString::fromUtf8("vyellow1"));
        vyellow1->setEnabled(false);
        vyellow1->setPixmap(QPixmap(QString::fromUtf8(":/GraphicalEqualizer/Yellow.jpg")));

        verticalLayout->addWidget(vyellow1);

        vyellow2 = new QLabel(widget);
        vyellow2->setObjectName(QString::fromUtf8("vyellow2"));
        vyellow2->setEnabled(false);
        vyellow2->setPixmap(QPixmap(QString::fromUtf8(":/GraphicalEqualizer/Yellow.jpg")));

        verticalLayout->addWidget(vyellow2);

        vyellow3 = new QLabel(widget);
        vyellow3->setObjectName(QString::fromUtf8("vyellow3"));
        vyellow3->setEnabled(false);
        vyellow3->setPixmap(QPixmap(QString::fromUtf8(":/GraphicalEqualizer/Yellow.jpg")));

        verticalLayout->addWidget(vyellow3);

        vyellowlight1 = new QLabel(widget);
        vyellowlight1->setObjectName(QString::fromUtf8("vyellowlight1"));
        vyellowlight1->setEnabled(false);
        vyellowlight1->setPixmap(QPixmap(QString::fromUtf8(":/GraphicalEqualizer/YellowLight.jpg")));

        verticalLayout->addWidget(vyellowlight1);

        vyellowlight2 = new QLabel(widget);
        vyellowlight2->setObjectName(QString::fromUtf8("vyellowlight2"));
        vyellowlight2->setEnabled(false);
        vyellowlight2->setPixmap(QPixmap(QString::fromUtf8(":/GraphicalEqualizer/YellowLight.jpg")));

        verticalLayout->addWidget(vyellowlight2);

        vyellowlight3 = new QLabel(widget);
        vyellowlight3->setObjectName(QString::fromUtf8("vyellowlight3"));
        vyellowlight3->setEnabled(false);
        vyellowlight3->setPixmap(QPixmap(QString::fromUtf8(":/GraphicalEqualizer/YellowLight.jpg")));

        verticalLayout->addWidget(vyellowlight3);

        vgreen1 = new QLabel(widget);
        vgreen1->setObjectName(QString::fromUtf8("vgreen1"));
        vgreen1->setEnabled(false);
        vgreen1->setPixmap(QPixmap(QString::fromUtf8(":/GraphicalEqualizer/Green.jpg")));

        verticalLayout->addWidget(vgreen1);

        vgreen2 = new QLabel(widget);
        vgreen2->setObjectName(QString::fromUtf8("vgreen2"));
        vgreen2->setEnabled(false);
        vgreen2->setPixmap(QPixmap(QString::fromUtf8(":/GraphicalEqualizer/Green.jpg")));

        verticalLayout->addWidget(vgreen2);

        vgreen3 = new QLabel(widget);
        vgreen3->setObjectName(QString::fromUtf8("vgreen3"));
        vgreen3->setEnabled(false);
        vgreen3->setPixmap(QPixmap(QString::fromUtf8(":/GraphicalEqualizer/Green.jpg")));

        verticalLayout->addWidget(vgreen3);

        vgreendark1 = new QLabel(widget);
        vgreendark1->setObjectName(QString::fromUtf8("vgreendark1"));
        vgreendark1->setEnabled(false);
        vgreendark1->setPixmap(QPixmap(QString::fromUtf8(":/GraphicalEqualizer/GreenDark.jpg")));

        verticalLayout->addWidget(vgreendark1);

        vgreendark2 = new QLabel(widget);
        vgreendark2->setObjectName(QString::fromUtf8("vgreendark2"));
        vgreendark2->setEnabled(false);
        vgreendark2->setPixmap(QPixmap(QString::fromUtf8(":/GraphicalEqualizer/GreenDark.jpg")));

        verticalLayout->addWidget(vgreendark2);

        vgreendark3 = new QLabel(widget);
        vgreendark3->setObjectName(QString::fromUtf8("vgreendark3"));
        vgreendark3->setEnabled(false);
        vgreendark3->setPixmap(QPixmap(QString::fromUtf8(":/GraphicalEqualizer/GreenDark.jpg")));

        verticalLayout->addWidget(vgreendark3);


        gridLayout_2->addWidget(widget, 1, 0, 1, 1);

        widget_2 = new QWidget(groupBox_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setMargin(11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        ared1 = new QLabel(widget_2);
        ared1->setObjectName(QString::fromUtf8("ared1"));
        ared1->setEnabled(false);
        ared1->setPixmap(QPixmap(QString::fromUtf8(":/GraphicalEqualizer/Red.jpg")));

        verticalLayout_2->addWidget(ared1);

        ared2 = new QLabel(widget_2);
        ared2->setObjectName(QString::fromUtf8("ared2"));
        ared2->setEnabled(false);
        ared2->setPixmap(QPixmap(QString::fromUtf8(":/GraphicalEqualizer/Red.jpg")));

        verticalLayout_2->addWidget(ared2);

        ared3 = new QLabel(widget_2);
        ared3->setObjectName(QString::fromUtf8("ared3"));
        ared3->setEnabled(false);
        ared3->setPixmap(QPixmap(QString::fromUtf8(":/GraphicalEqualizer/Red.jpg")));

        verticalLayout_2->addWidget(ared3);

        aorange1 = new QLabel(widget_2);
        aorange1->setObjectName(QString::fromUtf8("aorange1"));
        aorange1->setEnabled(false);
        aorange1->setPixmap(QPixmap(QString::fromUtf8(":/GraphicalEqualizer/Orange.jpg")));

        verticalLayout_2->addWidget(aorange1);

        aorange2 = new QLabel(widget_2);
        aorange2->setObjectName(QString::fromUtf8("aorange2"));
        aorange2->setEnabled(false);
        aorange2->setPixmap(QPixmap(QString::fromUtf8(":/GraphicalEqualizer/Orange.jpg")));

        verticalLayout_2->addWidget(aorange2);

        aorange3 = new QLabel(widget_2);
        aorange3->setObjectName(QString::fromUtf8("aorange3"));
        aorange3->setEnabled(false);
        aorange3->setPixmap(QPixmap(QString::fromUtf8(":/GraphicalEqualizer/Orange.jpg")));

        verticalLayout_2->addWidget(aorange3);

        ayellow1 = new QLabel(widget_2);
        ayellow1->setObjectName(QString::fromUtf8("ayellow1"));
        ayellow1->setEnabled(false);
        ayellow1->setPixmap(QPixmap(QString::fromUtf8(":/GraphicalEqualizer/Yellow.jpg")));

        verticalLayout_2->addWidget(ayellow1);

        ayellow2 = new QLabel(widget_2);
        ayellow2->setObjectName(QString::fromUtf8("ayellow2"));
        ayellow2->setEnabled(false);
        ayellow2->setPixmap(QPixmap(QString::fromUtf8(":/GraphicalEqualizer/Yellow.jpg")));

        verticalLayout_2->addWidget(ayellow2);

        ayellow3 = new QLabel(widget_2);
        ayellow3->setObjectName(QString::fromUtf8("ayellow3"));
        ayellow3->setEnabled(false);
        ayellow3->setPixmap(QPixmap(QString::fromUtf8(":/GraphicalEqualizer/Yellow.jpg")));

        verticalLayout_2->addWidget(ayellow3);

        ayellowlight1 = new QLabel(widget_2);
        ayellowlight1->setObjectName(QString::fromUtf8("ayellowlight1"));
        ayellowlight1->setEnabled(false);
        ayellowlight1->setPixmap(QPixmap(QString::fromUtf8(":/GraphicalEqualizer/YellowLight.jpg")));

        verticalLayout_2->addWidget(ayellowlight1);

        ayellowlight2 = new QLabel(widget_2);
        ayellowlight2->setObjectName(QString::fromUtf8("ayellowlight2"));
        ayellowlight2->setEnabled(false);
        ayellowlight2->setPixmap(QPixmap(QString::fromUtf8(":/GraphicalEqualizer/YellowLight.jpg")));

        verticalLayout_2->addWidget(ayellowlight2);

        ayellowlight3 = new QLabel(widget_2);
        ayellowlight3->setObjectName(QString::fromUtf8("ayellowlight3"));
        ayellowlight3->setEnabled(false);
        ayellowlight3->setPixmap(QPixmap(QString::fromUtf8(":/GraphicalEqualizer/YellowLight.jpg")));

        verticalLayout_2->addWidget(ayellowlight3);

        agreen1 = new QLabel(widget_2);
        agreen1->setObjectName(QString::fromUtf8("agreen1"));
        agreen1->setEnabled(false);
        agreen1->setPixmap(QPixmap(QString::fromUtf8(":/GraphicalEqualizer/Green.jpg")));

        verticalLayout_2->addWidget(agreen1);

        agreen2 = new QLabel(widget_2);
        agreen2->setObjectName(QString::fromUtf8("agreen2"));
        agreen2->setEnabled(false);
        agreen2->setPixmap(QPixmap(QString::fromUtf8(":/GraphicalEqualizer/Green.jpg")));

        verticalLayout_2->addWidget(agreen2);

        agreen3 = new QLabel(widget_2);
        agreen3->setObjectName(QString::fromUtf8("agreen3"));
        agreen3->setEnabled(false);
        agreen3->setPixmap(QPixmap(QString::fromUtf8(":/GraphicalEqualizer/Green.jpg")));

        verticalLayout_2->addWidget(agreen3);

        agreendark1 = new QLabel(widget_2);
        agreendark1->setObjectName(QString::fromUtf8("agreendark1"));
        agreendark1->setEnabled(false);
        agreendark1->setPixmap(QPixmap(QString::fromUtf8(":/GraphicalEqualizer/GreenDark.jpg")));

        verticalLayout_2->addWidget(agreendark1);

        agreendark2 = new QLabel(widget_2);
        agreendark2->setObjectName(QString::fromUtf8("agreendark2"));
        agreendark2->setEnabled(false);
        agreendark2->setPixmap(QPixmap(QString::fromUtf8(":/GraphicalEqualizer/GreenDark.jpg")));

        verticalLayout_2->addWidget(agreendark2);

        agreendark3 = new QLabel(widget_2);
        agreendark3->setObjectName(QString::fromUtf8("agreendark3"));
        agreendark3->setEnabled(false);
        agreendark3->setPixmap(QPixmap(QString::fromUtf8(":/GraphicalEqualizer/GreenDark.jpg")));

        verticalLayout_2->addWidget(agreendark3);


        gridLayout_2->addWidget(widget_2, 1, 3, 1, 1);

        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_2, 0, 3, 1, 1);


        gridLayout->addWidget(groupBox_3, 1, 1, 1, 1);

        groupBox_4 = new QGroupBox(StateViewerClass);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_3 = new QVBoxLayout(groupBox_4);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setMargin(11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget_3 = new QWidget(groupBox_4);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setMargin(11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget_6 = new QWidget(widget_3);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        verticalLayout_4 = new QVBoxLayout(widget_6);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setMargin(11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_39 = new QLabel(widget_6);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_39);

        XCoord = new QLabel(widget_6);
        XCoord->setObjectName(QString::fromUtf8("XCoord"));
        XCoord->setFrameShape(QFrame::StyledPanel);
        XCoord->setFrameShadow(QFrame::Sunken);
        XCoord->setLineWidth(3);
        XCoord->setMidLineWidth(6);
        XCoord->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(XCoord);


        horizontalLayout->addWidget(widget_6);

        widget_5 = new QWidget(widget_3);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        verticalLayout_5 = new QVBoxLayout(widget_5);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setMargin(11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_40 = new QLabel(widget_5);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_40);

        YCoord = new QLabel(widget_5);
        YCoord->setObjectName(QString::fromUtf8("YCoord"));
        YCoord->setFrameShape(QFrame::StyledPanel);
        YCoord->setFrameShadow(QFrame::Sunken);
        YCoord->setLineWidth(3);
        YCoord->setMidLineWidth(6);
        YCoord->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(YCoord);


        horizontalLayout->addWidget(widget_5);


        verticalLayout_3->addWidget(widget_3);

        widget_4 = new paintMovement(groupBox_4);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));

        verticalLayout_3->addWidget(widget_4);


        gridLayout->addWidget(groupBox_4, 1, 0, 1, 1);


        retranslateUi(StateViewerClass);

        QMetaObject::connectSlotsByName(StateViewerClass);
    } // setupUi

    void retranslateUi(QDialog *StateViewerClass)
    {
        StateViewerClass->setWindowTitle(QApplication::translate("StateViewerClass", "Hand Tracking: Estado", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("StateViewerClass", "Imagen procesada", 0, QApplication::UnicodeUTF8));
        processedImage->setText(QApplication::translate("StateViewerClass", "TextLabel", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("StateViewerClass", "Estado de la mano", 0, QApplication::UnicodeUTF8));
        handState->setText(QString());
        groupBox_3->setTitle(QApplication::translate("StateViewerClass", "Velocidad y Aceleraci\303\263n", 0, QApplication::UnicodeUTF8));
        vred1->setText(QString());
        vred2->setText(QString());
        vred3->setText(QString());
        vorange1->setText(QString());
        vorange2->setText(QString());
        vorange3->setText(QString());
        vyellow1->setText(QString());
        vyellow2->setText(QString());
        vyellow3->setText(QString());
        vyellowlight1->setText(QString());
        vyellowlight2->setText(QString());
        vyellowlight3->setText(QString());
        vgreen1->setText(QString());
        vgreen2->setText(QString());
        vgreen3->setText(QString());
        vgreendark1->setText(QString());
        vgreendark2->setText(QString());
        vgreendark3->setText(QString());
        ared1->setText(QString());
        ared2->setText(QString());
        ared3->setText(QString());
        aorange1->setText(QString());
        aorange2->setText(QString());
        aorange3->setText(QString());
        ayellow1->setText(QString());
        ayellow2->setText(QString());
        ayellow3->setText(QString());
        ayellowlight1->setText(QString());
        ayellowlight2->setText(QString());
        ayellowlight3->setText(QString());
        agreen1->setText(QString());
        agreen2->setText(QString());
        agreen3->setText(QString());
        agreendark1->setText(QString());
        agreendark2->setText(QString());
        agreendark3->setText(QString());
        label->setText(QApplication::translate("StateViewerClass", "Velocidad", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("StateViewerClass", "Aceleraci\303\263n", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("StateViewerClass", "Trayecto detectado", 0, QApplication::UnicodeUTF8));
        label_39->setText(QApplication::translate("StateViewerClass", "Coordenada X", 0, QApplication::UnicodeUTF8));
        XCoord->setText(QApplication::translate("StateViewerClass", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_40->setText(QApplication::translate("StateViewerClass", "Coordenada Y", 0, QApplication::UnicodeUTF8));
        YCoord->setText(QApplication::translate("StateViewerClass", "TextLabel", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(StateViewerClass);
    } // retranslateUi

};

namespace Ui {
    class StateViewerClass: public Ui_StateViewerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATEVIEWER_H
