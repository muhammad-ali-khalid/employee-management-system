#include "newemployee.h"
#include "ui_newemployee.h"

QString username, password, name, age, gender, department, email, mobile, cnic,
        experienceInYears, currentTask;
int id, salary, totalLeaves, approvedLeaves, rejectedLeaves, pendingLeaves;

NewEmployee::NewEmployee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewEmployee)
{
    ui->setupUi(this);

}

NewEmployee::~NewEmployee()
{
    delete ui;
}

void NewEmployee::on_pushButton_clicked()
{
    username = ui->username_input->text();
    password = ui->password_input->text();
    id = (ui->id_input->text()).toInt();
    name = ui->name_input->text();
    age = QString::number(ui->age_spinbox->value());
    gender = ui->gender_combobox->currentText();
    department = ui->department_input->text();
    email = ui->email_input->text();
    mobile = ui->mobile_input->text();
    cnic = ui->cnic_input->text();
    salary = ui->salary_input->text().toInt();
    experienceInYears = QString::number(ui->experience_spinbox->value());

    QSqlDatabase db4 = QSqlDatabase::addDatabase("QSQLITE");
        db4.setDatabaseName("/home/muhammad-ali/Downloads/EMS.db");
        if (db4.open()){
            QSqlQuery query1(db4);
            query1.prepare("INSERT INTO Employee_login (username, password, id) VALUES (:username, :password, :id);");
            query1.bindValue(":username", username);
            query1.bindValue(":password", password);
            query1.bindValue(":id", id);
            query1.exec();
            QSqlQuery query2(db4);
            query2.prepare("INSERT INTO Employee (username, id, name, age, gender, department, email, mobile, cnic, salary, experience, total_leaves, approved_leaves, rejected_leaves, pending_leaves, current_task) VALUES (:username, :id, :name, :age, :gender, :department, :email, :mobile, :cnic, :salary, :experience, :total_leaves, :approved_leaves, :rejected_leaves, :pending_leaves, :current_task);");
                    query2.bindValue(":username", username);
                    query2.bindValue(":id", id);
                    query2.bindValue(":name", name);
                    query2.bindValue(":age", age);
                    query2.bindValue(":gender", gender);
                    query2.bindValue(":department", department);
                    query2.bindValue(":email", email);
                    query2.bindValue(":mobile", mobile);
                    query2.bindValue(":cnic", cnic);
                    query2.bindValue(":salary", salary);
                    query2.bindValue(":experience", experienceInYears);
                    query2.bindValue(":total_leaves", totalLeaves);
                    query2.bindValue(":approved_leaves", approvedLeaves);
                    query2.bindValue(":rejected_leaves", rejectedLeaves);
                    query2.bindValue(":pending_leaves", pendingLeaves);
                    query2.bindValue(":current_task", currentTask);
                    query2.exec();
            }
            else{
                qDebug() << "Cannot open Databse";
            }
        db4.close();
        QMessageBox::about(this, "Success", "Employee Added");
        accept();
}

