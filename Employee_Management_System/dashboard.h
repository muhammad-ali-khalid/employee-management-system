#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QDialog>
#include <QDebug>
#include <QString>
#include <QPixmap>
#include <QLabel>
#include <QMessageBox>
#include <QIcon>
#include <QSize>
#include "employee.h"
#include "leaveapply.h"



namespace Ui {
class Dashboard;
}

class Dashboard : public QDialog
{
    Q_OBJECT

public:
    explicit Dashboard(Employee &employee,QWidget *parent = nullptr);
    ~Dashboard();
private slots:
    void on_logout_btn_clicked();

    void on_salary_btn_clicked();

    void on_attendance_btn_clicked();

    void on_performance_btn_clicked();

    void on_home_btn_clicked();

    void on_leave_btn_clicked();

private:
    Ui::Dashboard *ui;
    Employee emp;
};

#endif // DASHBOARD_H
