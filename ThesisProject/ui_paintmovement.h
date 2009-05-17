/********************************************************************************
** Form generated from reading ui file 'paintmovement.ui'
**
** Created: Tue 5. May 02:26:08 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_PAINTMOVEMENT_H
#define UI_PAINTMOVEMENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_paintMovementClass
{
public:

    void setupUi(QWidget *paintMovementClass)
    {
        if (paintMovementClass->objectName().isEmpty())
            paintMovementClass->setObjectName(QString::fromUtf8("paintMovementClass"));
        paintMovementClass->resize(400, 300);

        retranslateUi(paintMovementClass);

        QMetaObject::connectSlotsByName(paintMovementClass);
    } // setupUi

    void retranslateUi(QWidget *paintMovementClass)
    {
        paintMovementClass->setWindowTitle(QApplication::translate("paintMovementClass", "paintMovement", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(paintMovementClass);
    } // retranslateUi

};

namespace Ui {
    class paintMovementClass: public Ui_paintMovementClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAINTMOVEMENT_H
