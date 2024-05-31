#ifndef ADMINDASHBOARD_H
#define ADMINDASHBOARD_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include "employee.h"
#include "newemployee.h"
#include "removeemployee.h"
#include "assigntask.h"
#include "manageattendance.h"

namespace Ui {
class AdminDashboard;
}

class AdminDashboard : public QDialog
{
    Q_OBJECT

public:
    explicit AdminDashboard(QWidget *parent = nullptr);
    ~AdminDashboard();

private slots:
    void on_logout_btn_clicked();

    void on_add_new_employee_btn_clicked();

    void on_remove_employee_btn_clicked();

    void on_asign_task_btn_clicked();

    void on_manage_attendance_btn_clicked();

private:
    Ui::AdminDashboard *ui;
    Employee *employees;
};

#endif // ADMINDASHBOARD_H
