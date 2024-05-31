#include "admindashboard.h"
#include "ui_admindashboard.h"

int initialTotalEmployees, finalTotalEmployees;

AdminDashboard::AdminDashboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminDashboard)
{
    ui->setupUi(this);

    // Setting navigation bar icons
    QIcon logout("/home/muhammad-ali/icons/logout.png");
    ui->logout_btn->setIcon(logout);
    ui->logout_btn->setIconSize(QSize(25, 25));
    ui->logout_btn->setFixedSize(QSize(25, 25));
    ui->logout_btn->setFocusPolicy(Qt::NoFocus);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/muhammad-ali/Downloads/EMS.db");
    if (db.open()){
        QSqlQuery query1(db);
           query1.prepare("SELECT COUNT(*) FROM Employee;");
            if (!query1.exec()) {
                qDebug() << "Error executing query:" << query1.lastError().text();
            }
            // Fetch the result
            if (query1.next()) {
                initialTotalEmployees = query1.value(0).toInt();
                ui->total_employees_label->setText(QString::number(initialTotalEmployees));
                QSqlQuery query2;
                query2.prepare("SELECT * FROM Employee;");
                if (!query2.exec()) {
                    qDebug() << "Error executing query:" << query2.lastError().text();
                    return;
                }
                while (query2.next()) {
                    // Retrieve data from each column of the current row
                    QString id = query2.value(1).toString();
                    QString name = query2.value(2).toString();
                    QString department = query2.value(5).toString();
                    ui->id_listwidget->addItem(id);
                    ui->id_listwidget->setStyleSheet("QListWidget { border: none; }");
                    ui->name_listwidget->addItem(name);
                    ui->name_listwidget->setStyleSheet("QListWidget { border: none; }");
                    ui->department_listwidget->addItem(department);
                    ui->department_listwidget->setStyleSheet("QListWidget { border: none; }");

                }
            } else {
                qDebug() << "No result fetched!";
            }
        }
    else{
        QMessageBox::critical(this, "Failure", "Unable to connect database :(");
    }
}

AdminDashboard::~AdminDashboard()
{
    delete ui;
}

void AdminDashboard::on_add_new_employee_btn_clicked()
{
    NewEmployee newEmp;
    newEmp.setModal(true);
    newEmp.setWindowTitle("New Employee");
    newEmp.exec();
    QSqlDatabase db4 = QSqlDatabase::addDatabase("QSQLITE");
    db4.setDatabaseName("/home/muhammad-ali/Downloads/EMS.db");
    if(db4.open()){
        QSqlQuery query1(db4);
        query1.prepare("SELECT COUNT(*) FROM Employee;");
        if(query1.exec() && query1.next()){
            finalTotalEmployees = query1.value(0).toInt();
            int newEmployees = finalTotalEmployees - initialTotalEmployees;
            ui->total_employees_label->setText(QString::number(finalTotalEmployees));
            ui->newemployees_label->setText(QString::number(newEmployees));
        }
        QSqlQuery query2(db4);
        query2.prepare("SELECT * FROM Employee ORDER BY id DESC LIMIT 1;");
            if(query2.exec()){
                if(query2.next()){
                    QString id = query2.value(1).toString();
                    QString name = query2.value(2).toString();
                    QString department = query2.value(5).toString();
                    ui->id_listwidget->addItem(id);
                    ui->id_listwidget->setStyleSheet("QListWidget { border: none; }");
                    ui->name_listwidget->addItem(name);
                    ui->name_listwidget->setStyleSheet("QListWidget { border: none; }");
                    ui->department_listwidget->addItem(department);
                    ui->department_listwidget->setStyleSheet("QListWidget { border: none; }");
                }
            }
    }
    db4.close();
}

void AdminDashboard::on_remove_employee_btn_clicked()
{
    RemoveEmployee remEmp;
    remEmp.setModal(true);
    remEmp.setWindowTitle("Remove Employee");
    remEmp.exec();
}

void AdminDashboard::on_asign_task_btn_clicked()
{
    AssignTask task;
    task.setModal(true);
    task.setWindowTitle("Assign Task");
    task.exec();
}

void AdminDashboard::on_manage_attendance_btn_clicked()
{
    ManageAttendance atd;
    atd.setModal(true);
    atd.exec();
}

void AdminDashboard::on_logout_btn_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Quit?", "Are you sure you want to quit?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
      QMessageBox::about(this, "Logged Out", "You are successfully logged out");
      this->close();
      QApplication::quit();
    }
}


