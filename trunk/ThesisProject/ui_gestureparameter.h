/********************************************************************************
** Form generated from reading ui file 'gestureparameter.ui'
**
** Created: Fri 29. May 02:23:35 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_GESTUREPARAMETER_H
#define UI_GESTUREPARAMETER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GestureParameterClass
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *detectionGroup;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *bufferSize;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QSpinBox *relaxedCount;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;
    QComboBox *distanceCalculatorAGM;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_4;
    QLineEdit *nonVaryingAccelerationRate;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_5;
    QLineEdit *accelerationThreshold;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *gestureDescriptionGroup;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_6;
    QSpinBox *walkedPixels;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_7;
    QSpinBox *minimunPointCount;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_11;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_10;
    QLabel *label_9;
    QDoubleSpinBox *maxGestureTime;
    QSpacerItem *horizontalSpacer_9;
    QDoubleSpinBox *distanceThreshold;
    QGroupBox *dtwGroup;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_14;
    QLabel *label_10;
    QComboBox *valuesNormalizator;
    QSpacerItem *horizontalSpacer_13;
    QLabel *label_11;
    QSpinBox *relaxedRatio;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *horizontalSpacer_15;
    QLabel *label_12;
    QComboBox *distanceCalculatorDTW;
    QSpacerItem *horizontalSpacer_16;
    QLabel *label_13;
    QComboBox *dtwAlgorithm;
    QLabel *label_14;
    QDoubleSpinBox *rate;
    QSpacerItem *horizontalSpacer_18;
    QSpacerItem *horizontalSpacer_17;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *reject;
    QPushButton *accept;

    void setupUi(QDialog *GestureParameterClass)
    {
        if (GestureParameterClass->objectName().isEmpty())
            GestureParameterClass->setObjectName(QString::fromUtf8("GestureParameterClass"));
        GestureParameterClass->resize(659, 348);
        verticalLayout = new QVBoxLayout(GestureParameterClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setMargin(11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        detectionGroup = new QGroupBox(GestureParameterClass);
        detectionGroup->setObjectName(QString::fromUtf8("detectionGroup"));
        gridLayout = new QGridLayout(detectionGroup);
        gridLayout->setSpacing(6);
        gridLayout->setMargin(11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(detectionGroup);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 2);

        bufferSize = new QSpinBox(detectionGroup);
        bufferSize->setObjectName(QString::fromUtf8("bufferSize"));
        bufferSize->setMinimum(1);
        bufferSize->setMaximum(20);
        bufferSize->setValue(8);

        gridLayout->addWidget(bufferSize, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(82, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 3, 1, 1);

        label_2 = new QLabel(detectionGroup);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 4, 1, 1);

        relaxedCount = new QSpinBox(detectionGroup);
        relaxedCount->setObjectName(QString::fromUtf8("relaxedCount"));
        relaxedCount->setValue(5);

        gridLayout->addWidget(relaxedCount, 0, 5, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(78, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 6, 1, 1);

        label_3 = new QLabel(detectionGroup);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 7, 1, 1);

        distanceCalculatorAGM = new QComboBox(detectionGroup);
        distanceCalculatorAGM->setObjectName(QString::fromUtf8("distanceCalculatorAGM"));

        gridLayout->addWidget(distanceCalculatorAGM, 0, 8, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(55, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        label_4 = new QLabel(detectionGroup);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 1, 1, 1);

        nonVaryingAccelerationRate = new QLineEdit(detectionGroup);
        nonVaryingAccelerationRate->setObjectName(QString::fromUtf8("nonVaryingAccelerationRate"));

        gridLayout->addWidget(nonVaryingAccelerationRate, 1, 2, 1, 2);

        horizontalSpacer_4 = new QSpacerItem(54, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 4, 1, 1);

        label_5 = new QLabel(detectionGroup);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 1, 5, 1, 1);

        accelerationThreshold = new QLineEdit(detectionGroup);
        accelerationThreshold->setObjectName(QString::fromUtf8("accelerationThreshold"));

        gridLayout->addWidget(accelerationThreshold, 1, 6, 1, 2);

        horizontalSpacer_3 = new QSpacerItem(109, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 8, 1, 1);


        verticalLayout->addWidget(detectionGroup);

        gestureDescriptionGroup = new QGroupBox(GestureParameterClass);
        gestureDescriptionGroup->setObjectName(QString::fromUtf8("gestureDescriptionGroup"));
        gridLayout_2 = new QGridLayout(gestureDescriptionGroup);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setMargin(11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSpacer_8 = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_8, 0, 0, 1, 1);

        label_6 = new QLabel(gestureDescriptionGroup);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 0, 1, 1, 1);

        walkedPixels = new QSpinBox(gestureDescriptionGroup);
        walkedPixels->setObjectName(QString::fromUtf8("walkedPixels"));
        walkedPixels->setMinimum(15);
        walkedPixels->setMaximum(100);
        walkedPixels->setValue(30);

        gridLayout_2->addWidget(walkedPixels, 0, 2, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(97, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_7, 0, 3, 1, 1);

        label_7 = new QLabel(gestureDescriptionGroup);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 0, 4, 1, 2);

        minimunPointCount = new QSpinBox(gestureDescriptionGroup);
        minimunPointCount->setObjectName(QString::fromUtf8("minimunPointCount"));
        minimunPointCount->setMinimum(10);
        minimunPointCount->setMaximum(80);
        minimunPointCount->setValue(15);

        gridLayout_2->addWidget(minimunPointCount, 0, 6, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(97, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 0, 7, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_11, 1, 0, 1, 1);

        label_8 = new QLabel(gestureDescriptionGroup);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 1, 1, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_10, 1, 3, 1, 2);

        label_9 = new QLabel(gestureDescriptionGroup);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_2->addWidget(label_9, 1, 5, 1, 1);

        maxGestureTime = new QDoubleSpinBox(gestureDescriptionGroup);
        maxGestureTime->setObjectName(QString::fromUtf8("maxGestureTime"));
        maxGestureTime->setMaximum(2.5);
        maxGestureTime->setSingleStep(0.05);
        maxGestureTime->setValue(2);

        gridLayout_2->addWidget(maxGestureTime, 1, 6, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(97, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_9, 1, 7, 1, 1);

        distanceThreshold = new QDoubleSpinBox(gestureDescriptionGroup);
        distanceThreshold->setObjectName(QString::fromUtf8("distanceThreshold"));
        distanceThreshold->setMaximum(1);
        distanceThreshold->setSingleStep(0.05);
        distanceThreshold->setValue(0.75);

        gridLayout_2->addWidget(distanceThreshold, 1, 2, 1, 1);


        verticalLayout->addWidget(gestureDescriptionGroup);

        dtwGroup = new QGroupBox(GestureParameterClass);
        dtwGroup->setObjectName(QString::fromUtf8("dtwGroup"));
        gridLayout_3 = new QGridLayout(dtwGroup);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setMargin(11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalSpacer_14 = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_14, 0, 0, 1, 1);

        label_10 = new QLabel(dtwGroup);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_10, 0, 1, 1, 1);

        valuesNormalizator = new QComboBox(dtwGroup);
        valuesNormalizator->setObjectName(QString::fromUtf8("valuesNormalizator"));

        gridLayout_3->addWidget(valuesNormalizator, 0, 2, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(62, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_13, 0, 3, 1, 1);

        label_11 = new QLabel(dtwGroup);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_3->addWidget(label_11, 0, 4, 1, 1);

        relaxedRatio = new QSpinBox(dtwGroup);
        relaxedRatio->setObjectName(QString::fromUtf8("relaxedRatio"));
        relaxedRatio->setMinimum(1);
        relaxedRatio->setValue(2);

        gridLayout_3->addWidget(relaxedRatio, 0, 5, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(62, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_12, 0, 6, 1, 1);

        horizontalSpacer_15 = new QSpacerItem(62, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_15, 1, 0, 1, 2);

        label_12 = new QLabel(dtwGroup);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_12, 1, 2, 1, 1);

        distanceCalculatorDTW = new QComboBox(dtwGroup);
        distanceCalculatorDTW->setObjectName(QString::fromUtf8("distanceCalculatorDTW"));

        gridLayout_3->addWidget(distanceCalculatorDTW, 1, 3, 1, 1);

        horizontalSpacer_16 = new QSpacerItem(62, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_16, 1, 4, 1, 3);

        label_13 = new QLabel(dtwGroup);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_3->addWidget(label_13, 2, 0, 1, 2);

        dtwAlgorithm = new QComboBox(dtwGroup);
        dtwAlgorithm->setObjectName(QString::fromUtf8("dtwAlgorithm"));

        gridLayout_3->addWidget(dtwAlgorithm, 2, 2, 1, 1);

        label_14 = new QLabel(dtwGroup);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_3->addWidget(label_14, 2, 4, 1, 1);

        rate = new QDoubleSpinBox(dtwGroup);
        rate->setObjectName(QString::fromUtf8("rate"));
        rate->setMaximum(1);
        rate->setSingleStep(0.05);
        rate->setValue(0.3);

        gridLayout_3->addWidget(rate, 2, 5, 1, 1);

        horizontalSpacer_18 = new QSpacerItem(62, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_18, 2, 6, 1, 1);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_17, 2, 3, 1, 1);


        verticalLayout->addWidget(dtwGroup);

        widget = new QWidget(GestureParameterClass);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setMargin(11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        reject = new QPushButton(widget);
        reject->setObjectName(QString::fromUtf8("reject"));

        horizontalLayout->addWidget(reject);

        accept = new QPushButton(widget);
        accept->setObjectName(QString::fromUtf8("accept"));

        horizontalLayout->addWidget(accept);


        verticalLayout->addWidget(widget);

        QWidget::setTabOrder(bufferSize, relaxedCount);
        QWidget::setTabOrder(relaxedCount, distanceCalculatorAGM);
        QWidget::setTabOrder(distanceCalculatorAGM, nonVaryingAccelerationRate);
        QWidget::setTabOrder(nonVaryingAccelerationRate, accelerationThreshold);
        QWidget::setTabOrder(accelerationThreshold, walkedPixels);
        QWidget::setTabOrder(walkedPixels, minimunPointCount);
        QWidget::setTabOrder(minimunPointCount, distanceThreshold);
        QWidget::setTabOrder(distanceThreshold, maxGestureTime);
        QWidget::setTabOrder(maxGestureTime, valuesNormalizator);
        QWidget::setTabOrder(valuesNormalizator, relaxedRatio);
        QWidget::setTabOrder(relaxedRatio, distanceCalculatorDTW);
        QWidget::setTabOrder(distanceCalculatorDTW, dtwAlgorithm);
        QWidget::setTabOrder(dtwAlgorithm, rate);
        QWidget::setTabOrder(rate, reject);
        QWidget::setTabOrder(reject, accept);

        retranslateUi(GestureParameterClass);
        QObject::connect(accept, SIGNAL(clicked()), GestureParameterClass, SLOT(accept()));
        QObject::connect(reject, SIGNAL(clicked()), GestureParameterClass, SLOT(reject()));
        QObject::connect(bufferSize, SIGNAL(valueChanged(int)), GestureParameterClass, SLOT(setDetectedCount(int)));
        QObject::connect(relaxedCount, SIGNAL(valueChanged(int)), GestureParameterClass, SLOT(setMaxRelatedRatio(int)));
        QObject::connect(bufferSize, SIGNAL(valueChanged(int)), GestureParameterClass, SLOT(bufferSizeModified(int)));
        QObject::connect(relaxedCount, SIGNAL(valueChanged(int)), GestureParameterClass, SLOT(relaxedCountModified(int)));
        QObject::connect(distanceCalculatorAGM, SIGNAL(currentIndexChanged(QString)), GestureParameterClass, SLOT(distanceCalculatorAGMModified(QString)));
        QObject::connect(nonVaryingAccelerationRate, SIGNAL(textChanged(QString)), GestureParameterClass, SLOT(nonVaryingAccelerationRateModified(QString)));
        QObject::connect(accelerationThreshold, SIGNAL(textChanged(QString)), GestureParameterClass, SLOT(accelerationThresholdModified(QString)));
        QObject::connect(walkedPixels, SIGNAL(valueChanged(int)), GestureParameterClass, SLOT(walkedPixelsModified(int)));
        QObject::connect(minimunPointCount, SIGNAL(valueChanged(int)), GestureParameterClass, SLOT(minimumPointCountModified(int)));
        QObject::connect(distanceThreshold, SIGNAL(valueChanged(double)), GestureParameterClass, SLOT(distanceThresholdModified(double)));
        QObject::connect(maxGestureTime, SIGNAL(valueChanged(double)), GestureParameterClass, SLOT(maxGestureTimeModified(double)));
        QObject::connect(valuesNormalizator, SIGNAL(currentIndexChanged(QString)), GestureParameterClass, SLOT(valuesNormalizatorModified(QString)));
        QObject::connect(relaxedRatio, SIGNAL(valueChanged(int)), GestureParameterClass, SLOT(relaxedRatioModified(int)));
        QObject::connect(distanceCalculatorDTW, SIGNAL(currentIndexChanged(QString)), GestureParameterClass, SLOT(distanceCalculatorDTWModified(QString)));
        QObject::connect(dtwAlgorithm, SIGNAL(currentIndexChanged(QString)), GestureParameterClass, SLOT(dtwAlgorithmModified(QString)));
        QObject::connect(rate, SIGNAL(valueChanged(double)), GestureParameterClass, SLOT(rateModified(double)));

        QMetaObject::connectSlotsByName(GestureParameterClass);
    } // setupUi

    void retranslateUi(QDialog *GestureParameterClass)
    {
        GestureParameterClass->setWindowTitle(QApplication::translate("GestureParameterClass", "Parametro del Reconocimiento de Gestos", 0, QApplication::UnicodeUTF8));
        detectionGroup->setTitle(QApplication::translate("GestureParameterClass", "Par\303\241metros de detecci\303\263n", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("GestureParameterClass", "Tama\303\261o del buffer", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("GestureParameterClass", "Puntos a utilizar", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("GestureParameterClass", "Distancia entre puntos", 0, QApplication::UnicodeUTF8));
        distanceCalculatorAGM->clear();
        distanceCalculatorAGM->insertItems(0, QStringList()
         << QApplication::translate("GestureParameterClass", "Distancia Eucl\303\255dea", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("GestureParameterClass", "Tolerancia aceleraci\303\263n", 0, QApplication::UnicodeUTF8));
        nonVaryingAccelerationRate->setInputMask(QApplication::translate("GestureParameterClass", "0000; ", 0, QApplication::UnicodeUTF8));
        nonVaryingAccelerationRate->setText(QApplication::translate("GestureParameterClass", "700", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("GestureParameterClass", "Valor de activaci\303\263n", 0, QApplication::UnicodeUTF8));
        accelerationThreshold->setInputMask(QApplication::translate("GestureParameterClass", "00000; ", 0, QApplication::UnicodeUTF8));
        accelerationThreshold->setText(QApplication::translate("GestureParameterClass", "2000", 0, QApplication::UnicodeUTF8));
        gestureDescriptionGroup->setTitle(QApplication::translate("GestureParameterClass", "Par\303\241metros del gesto", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("GestureParameterClass", "Espacio recorrido (en pixels)", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("GestureParameterClass", "Cantidad de puntos m\303\255nima", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("GestureParameterClass", "Factor de recorrido aceptado", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("GestureParameterClass", "M\303\241xima duraci\303\263n de gesto", 0, QApplication::UnicodeUTF8));
        dtwGroup->setTitle(QApplication::translate("GestureParameterClass", "Par\303\241metros del reconocimiento", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("GestureParameterClass", "Normalizador", 0, QApplication::UnicodeUTF8));
        valuesNormalizator->clear();
        valuesNormalizator->insertItems(0, QStringList()
         << QApplication::translate("GestureParameterClass", "Normalizador Simple", 0, QApplication::UnicodeUTF8)
        );
        label_11->setText(QApplication::translate("GestureParameterClass", "Secci\303\263n detecci\303\263n", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("GestureParameterClass", "Distancia entre puntos", 0, QApplication::UnicodeUTF8));
        distanceCalculatorDTW->clear();
        distanceCalculatorDTW->insertItems(0, QStringList()
         << QApplication::translate("GestureParameterClass", "Distancia Eucl\303\255dea", 0, QApplication::UnicodeUTF8)
        );
        label_13->setText(QApplication::translate("GestureParameterClass", "Algoritmo de Dynamic Time Warping", 0, QApplication::UnicodeUTF8));
        dtwAlgorithm->clear();
        dtwAlgorithm->insertItems(0, QStringList()
         << QApplication::translate("GestureParameterClass", "Paralelogramo de Itakura", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GestureParameterClass", "DTW Simple", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GestureParameterClass", "Banda de Sakoe/Chiba", 0, QApplication::UnicodeUTF8)
        );
        label_14->setText(QApplication::translate("GestureParameterClass", "Amplitud", 0, QApplication::UnicodeUTF8));
        reject->setText(QApplication::translate("GestureParameterClass", "Cancelar", 0, QApplication::UnicodeUTF8));
        accept->setText(QApplication::translate("GestureParameterClass", "Aceptar", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(GestureParameterClass);
    } // retranslateUi

};

namespace Ui {
    class GestureParameterClass: public Ui_GestureParameterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTUREPARAMETER_H
