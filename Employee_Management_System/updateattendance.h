#ifndef UPDATEATTENDANCE_H
#define UPDATEATTENDANCE_H

#include <QDialog>
#include "employee.h"
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QMessageBox>

namespace Ui {
class UpdateAttendance;
}

class UpdateAttendance : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateAttendance(int& id, QWidget *parent = nullptr);
    ~UpdateAttendance();

private slots:
    void on_pushButton_clicked();

private:
    Ui::UpdateAttendance *ui;
};

#endif // UPDATEATTENDANCE_H
