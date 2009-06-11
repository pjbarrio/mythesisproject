/**
 * handdiagnostic.h
 *
 *  Created on: 05/05/2009
 *      \author  Pablo
 *
 * This GUI class is used to configure the values
 * of hand state (Open/Close).
 */

#ifndef HANDDIAGNOSTIC_H
#define HANDDIAGNOSTIC_H

#include <QtGui/QDialog>
#include "ui_handdiagnostic.h"


class HandDiagnostic : public QDialog
{
    Q_OBJECT

public:
    HandDiagnostic(QWidget *parent = 0);
    ~HandDiagnostic();
    QLabel* getCaptureLabel(){return ui.label;};

    /**
     * This method returns the skin pixel count of
     * the open hand state.
     */

    double getFrameOpenCount(){return countOpen;};

    /**
     * This method returns the skin pixel count of
     * the close hand state.
     */

    double getFrameClosedCount(){return countClose;};
    int exec();

private:
    Ui::HandDiagnosticClass ui;
    int paso;
    double countClose;
    double countOpen;
private slots:
	void proceder();


};

#endif // HANDDIAGNOSTIC_H
