#ifndef MANAGEATTENDANCE_H
#define MANAGEATTENDANCE_H

#include <QDialog>
#include "updateattendance.h"

namespace Ui {
class ManageAttendance;
}

class ManageAttendance : public QDialog
{
    Q_OBJECT

public:
    explicit ManageAttendance(QWidget *parent = nullptr);
    ~ManageAttendance();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ManageAttendance *ui;
};

#endif // MANAGEATTENDANCE_H
