#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include "employee.h"
#include "dashboard.h"
#include "admindashboard.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_employee_login_btn_clicked();

    void on_admin_login_btn_clicked();

    void on_checkBox_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // LOGINWINDOW_H
