#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->forgot_label->setFocusPolicy(Qt::NoFocus);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}


void LoginWindow::on_employee_login_btn_clicked()
{
    QString username = ui->username_input->text();
    QString password = ui->password_input->text();
    QSqlDatabase db1 = QSqlDatabase::addDatabase("QSQLITE");
    db1.setDatabaseName("/home/muhammad-ali/Downloads/EMS.db");
    if (db1.open()){
        QSqlQuery query1(db1);
        query1.prepare("SELECT * FROM Employee_login WHERE username = :username AND password = :password;");
        query1.bindValue(":username", username);
        query1.bindValue(":password", password);
        if(query1.exec() && query1.next()){
            QMessageBox::about(this, "Success", "Correct Password");
            QSqlQuery query2(db1);
            query2.prepare("SELECT * FROM Employee WHERE username = :username");
            query2.bindValue(":username", username);
            if(query2.exec() && query2.next()){
                // Declaring necessary variables to retrieve data from Database
                QString name, gender, department, email, mobile, cnic, experienceInYears, currentTask;
                int id, age, salary, totalLeaves, approvedLeaves, rejectedLeaves, pendingLeaves;
                id = query2.value("id").toInt();
                name = query2.value("name").toString();
                age = query2.value("age").toInt();
                gender = query2.value("gender").toString();
                department = query2.value("department").toString();
                email = query2.value("email").toString();
                mobile = query2.value("mobile").toString();
                cnic = query2.value("cnic").toString();
                salary = query2.value("salary").toInt();
                experienceInYears = query2.value("experience").toString();
                totalLeaves = query2.value("total_leaves").toInt();
                approvedLeaves = query2.value("approved_leaves").toInt();
                rejectedLeaves = query2.value("rejected_leaves").toInt();
                pendingLeaves = query2.value("pending_leaves").toInt();
                currentTask = query2.value("current_task").toString();
                // Calling parameterized Employee constructor to create object
                Employee emp(username, id, name, age, gender, department, email, mobile, cnic,
                             salary, experienceInYears, totalLeaves, approvedLeaves, rejectedLeaves, pendingLeaves, currentTask);
                db1.close();
                Dashboard dash(emp);
                this->hide();
                dash.setModal(true);
                dash.setWindowState(windowState() | Qt::WindowFullScreen);
                dash.exec();
            }
        }
        else{
          QMessageBox::critical(this, "Failure", "Incorrect Password");
        }
    }
    else{
        QMessageBox::critical(this, "Connection Error", "Unable to connect database :(");
    }
}

void LoginWindow::on_admin_login_btn_clicked()
{
    QString username = ui->username_input->text();
    QString password = ui->password_input->text();
    QSqlDatabase db1 = QSqlDatabase::addDatabase("QSQLITE");
    db1.setDatabaseName("/home/muhammad-ali/Downloads/EMS.db");
    if (db1.open()){
        QSqlQuery query(db1);
        query.prepare("SELECT * FROM Admin_login WHERE username = :username AND password = :password;");
        query.bindValue(":username", username);
        query.bindValue(":password", password);
        if(query.exec() && query.next()){
            QMessageBox::about(this, "Success", "Correct Password");
            AdminDashboard dash;
            this->hide();
            db1.close();
            dash.setModal(true);
            dash.setWindowTitle("Admin Dashboard");
            dash.setWindowState(windowState() | Qt::WindowFullScreen);
            dash.exec();
        }
        else{
            QMessageBox::critical(this, "Failure", "Incorrect Password");
        }
        }
    else{
        QMessageBox::critical(this, "Connection Error", "Unable to connect database");
    }
}

void LoginWindow::on_checkBox_clicked()
{
   ui->password_input->setEchoMode(ui->checkBox->checkState() == Qt::Checked ? QLineEdit::Normal : QLineEdit::Password );
}

