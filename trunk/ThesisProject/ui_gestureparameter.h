/********************************************************************************
** Form generated from reading ui file 'gestureparameter.ui'
**
** Created: Thu 28. May 15:05:26 2009
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
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
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
    QSpinBox *bufferSize;
    QSpinBox *relaxedCount;
    QComboBox *distanceCalculatorAGM;
    QLineEdit *nonVaryingAccelerationRate;
    QLineEdit *accelerationThreshold;
    QGroupBox *gestureDescriptionGroup;
    QGridLayout *gridLayout_2;
    QSpinBox *walkedPixels;
    QSpinBox *minimunPointCount;
    QDoubleSpinBox *distanceThreshold;
    QDoubleSpinBox *maxGestureTime;
    QGroupBox *dtwGroup;
    QGridLayout *gridLayout_3;
    QComboBox *valuesNormalizator;
    QComboBox *distanceCalculatorDTW;
    QSpinBox *relaxedRatio;
    QComboBox *dtwAlgorithm;
    QDoubleSpinBox *rate;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *accept;
    QPushButton *reject;

    void setupUi(QDialog *GestureParameterClass)
    {
        if (GestureParameterClass->objectName().isEmpty())
            GestureParameterClass->setObjectName(QString::fromUtf8("GestureParameterClass"));
        GestureParameterClass->resize(584, 316);
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
        bufferSize = new QSpinBox(detectionGroup);
        bufferSize->setObjectName(QString::fromUtf8("bufferSize"));
        bufferSize->setMinimum(1);
        bufferSize->setMaximum(20);

        gridLayout->addWidget(bufferSize, 0, 0, 1, 1);

        relaxedCount = new QSpinBox(detectionGroup);
        relaxedCount->setObjectName(QString::fromUtf8("relaxedCount"));

        gridLayout->addWidget(relaxedCount, 0, 1, 1, 1);

        distanceCalculatorAGM = new QComboBox(detectionGroup);
        distanceCalculatorAGM->setObjectName(QString::fromUtf8("distanceCalculatorAGM"));

        gridLayout->addWidget(distanceCalculatorAGM, 0, 2, 1, 1);

        nonVaryingAccelerationRate = new QLineEdit(detectionGroup);
        nonVaryingAccelerationRate->setObjectName(QString::fromUtf8("nonVaryingAccelerationRate"));

        gridLayout->addWidget(nonVaryingAccelerationRate, 1, 1, 1, 1);

        accelerationThreshold = new QLineEdit(detectionGroup);
        accelerationThreshold->setObjectName(QString::fromUtf8("accelerationThreshold"));

        gridLayout->addWidget(accelerationThreshold, 1, 2, 1, 1);


        verticalLayout->addWidget(detectionGroup);

        gestureDescriptionGroup = new QGroupBox(GestureParameterClass);
        gestureDescriptionGroup->setObjectName(QString::fromUtf8("gestureDescriptionGroup"));
        gridLayout_2 = new QGridLayout(gestureDescriptionGroup);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setMargin(11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        walkedPixels = new QSpinBox(gestureDescriptionGroup);
        walkedPixels->setObjectName(QString::fromUtf8("walkedPixels"));
        walkedPixels->setMinimum(15);
        walkedPixels->setMaximum(100);

        gridLayout_2->addWidget(walkedPixels, 0, 0, 1, 1);

        minimunPointCount = new QSpinBox(gestureDescriptionGroup);
        minimunPointCount->setObjectName(QString::fromUtf8("minimunPointCount"));
        minimunPointCount->setMinimum(10);
        minimunPointCount->setMaximum(80);

        gridLayout_2->addWidget(minimunPointCount, 0, 2, 1, 1);

        distanceThreshold = new QDoubleSpinBox(gestureDescriptionGroup);
        distanceThreshold->setObjectName(QString::fromUtf8("distanceThreshold"));
        distanceThreshold->setMaximum(1);
        distanceThreshold->setSingleStep(0.05);

        gridLayout_2->addWidget(distanceThreshold, 1, 1, 1, 1);

        maxGestureTime = new QDoubleSpinBox(gestureDescriptionGroup);
        maxGestureTime->setObjectName(QString::fromUtf8("maxGestureTime"));
        maxGestureTime->setMaximum(2);
        maxGestureTime->setSingleStep(0.05);

        gridLayout_2->addWidget(maxGestureTime, 1, 2, 1, 1);


        verticalLayout->addWidget(gestureDescriptionGroup);

        dtwGroup = new QGroupBox(GestureParameterClass);
        dtwGroup->setObjectName(QString::fromUtf8("dtwGroup"));
        gridLayout_3 = new QGridLayout(dtwGroup);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setMargin(11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        valuesNormalizator = new QComboBox(dtwGroup);
        valuesNormalizator->setObjectName(QString::fromUtf8("valuesNormalizator"));

        gridLayout_3->addWidget(valuesNormalizator, 0, 0, 1, 1);

        distanceCalculatorDTW = new QComboBox(dtwGroup);
        distanceCalculatorDTW->setObjectName(QString::fromUtf8("distanceCalculatorDTW"));

        gridLayout_3->addWidget(distanceCalculatorDTW, 0, 1, 1, 1);

        relaxedRatio = new QSpinBox(dtwGroup);
        relaxedRatio->setObjectName(QString::fromUtf8("relaxedRatio"));
        relaxedRatio->setMinimum(1);

        gridLayout_3->addWidget(relaxedRatio, 0, 2, 1, 1);

        dtwAlgorithm = new QComboBox(dtwGroup);
        dtwAlgorithm->setObjectName(QString::fromUtf8("dtwAlgorithm"));

        gridLayout_3->addWidget(dtwAlgorithm, 1, 0, 1, 1);

        rate = new QDoubleSpinBox(dtwGroup);
        rate->setObjectName(QString::fromUtf8("rate"));
        rate->setMaximum(1);
        rate->setSingleStep(0.05);

        gridLayout_3->addWidget(rate, 1, 2, 1, 1);


        verticalLayout->addWidget(dtwGroup);

        widget = new QWidget(GestureParameterClass);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setMargin(11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        accept = new QPushButton(widget);
        accept->setObjectName(QString::fromUtf8("accept"));

        horizontalLayout->addWidget(accept);

        reject = new QPushButton(widget);
        reject->setObjectName(QString::fromUtf8("reject"));

        horizontalLayout->addWidget(reject);


        verticalLayout->addWidget(widget);


        retranslateUi(GestureParameterClass);
        QObject::connect(bufferSize, SIGNAL(valueChanged(int)), GestureParameterClass, SLOT(setDetectedCount(int)));
        QObject::connect(relaxedCount, SIGNAL(valueChanged(int)), GestureParameterClass, SLOT(setMaxRelatedRatio(int)));
        QObject::connect(accept, SIGNAL(clicked()), GestureParameterClass, SLOT(accept()));
        QObject::connect(reject, SIGNAL(clicked()), GestureParameterClass, SLOT(reject()));

        QMetaObject::connectSlotsByName(GestureParameterClass);
    } // setupUi

    void retranslateUi(QDialog *GestureParameterClass)
    {
        GestureParameterClass->setWindowTitle(QApplication::translate("GestureParameterClass", "GestureParameter", 0, QApplication::UnicodeUTF8));
        detectionGroup->setTitle(QApplication::translate("GestureParameterClass", "Par\303\241metros de detecci\303\263n", 0, QApplication::UnicodeUTF8));
        distanceCalculatorAGM->clear();
        distanceCalculatorAGM->insertItems(0, QStringList()
         << QApplication::translate("GestureParameterClass", "Distancia Eucl\303\255dea", 0, QApplication::UnicodeUTF8)
        );
        gestureDescriptionGroup->setTitle(QApplication::translate("GestureParameterClass", "Par\303\241metros del gesto", 0, QApplication::UnicodeUTF8));
        dtwGroup->setTitle(QApplication::translate("GestureParameterClass", "Par\303\241metros del reconocimiento", 0, QApplication::UnicodeUTF8));
        valuesNormalizator->clear();
        valuesNormalizator->insertItems(0, QStringList()
         << QApplication::translate("GestureParameterClass", "Normalizador Simple", 0, QApplication::UnicodeUTF8)
        );
        distanceCalculatorDTW->clear();
        distanceCalculatorDTW->insertItems(0, QStringList()
         << QApplication::translate("GestureParameterClass", "Distancia Eucl\303\255dea", 0, QApplication::UnicodeUTF8)
        );
        dtwAlgorithm->clear();
        dtwAlgorithm->insertItems(0, QStringList()
         << QApplication::translate("GestureParameterClass", "DTW Simple", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GestureParameterClass", "Paralelogramo de Itakura", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GestureParameterClass", "Banda de Sakoe/Chiba", 0, QApplication::UnicodeUTF8)
        );
        accept->setText(QApplication::translate("GestureParameterClass", "Aceptar", 0, QApplication::UnicodeUTF8));
        reject->setText(QApplication::translate("GestureParameterClass", "Cancelar", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(GestureParameterClass);
    } // retranslateUi

};

namespace Ui {
    class GestureParameterClass: public Ui_GestureParameterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTUREPARAMETER_H
