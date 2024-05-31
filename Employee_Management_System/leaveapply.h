#ifndef LEAVEAPPLY_H
#define LEAVEAPPLY_H

#include <QDialog>
#include <QMessageBox>
#include "employee.h"
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include "dashboard.h"

namespace Ui {
class LeaveApply;
}

class LeaveApply : public QDialog
{
    Q_OBJECT

public:
    explicit LeaveApply(Employee& obj, QWidget *parent = nullptr);
    ~LeaveApply();

private slots:
    void on_pushButton_clicked();

private:
    Ui::LeaveApply *ui;
};

#endif // LEAVEAPPLY_H
