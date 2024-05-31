#include "assigntask.h"
#include "ui_assigntask.h"

AssignTask::AssignTask(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AssignTask)
{
    ui->setupUi(this);

}

AssignTask::~AssignTask()
{
    delete ui;
}

void AssignTask::on_done_btn_clicked()
{
    int id = ui->emp_id_spinbox->value();
    QString task = ui->task_lineedit->text();
    QSqlDatabase db5 = QSqlDatabase::addDatabase("QSQLITE");
    db5.setDatabaseName("/home/muhammad-ali/Downloads/EMS.db");
    if (db5.open()){
        QSqlQuery query(db5);
        query.prepare("UPDATE Employee SET current_task = :task WHERE id = :id;");
        query.bindValue(":task", task);
        query.bindValue(":id", id);
        if(query.exec()){
            QMessageBox::about(this, "Success", "Task assigned");
        }
        else{
            QMessageBox::about(this, "Failure", "ID not found");
        }
    }
    db5.close();
    accept();
}

