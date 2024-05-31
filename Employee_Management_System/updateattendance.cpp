#include "updateattendance.h"
#include "ui_updateattendance.h"

int pendLeaves;
UpdateAttendance::UpdateAttendance(int& id,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateAttendance)
{
    QSqlDatabase db1 = QSqlDatabase::addDatabase("QSQLITE");
    db1.setDatabaseName("/home/muhammad-ali/Downloads/EMS.db");
    if (db1.open()){
        QSqlQuery query(db1);
        query.prepare("SELECT pending_leaves FROM Employee WHERE id = :id;");
        query.bindValue(":id", id);
        query.exec();
        pendLeaves = query.value("pending_leaves").toInt();
    }
    ui->setupUi(this);
    ui->pending_leaves->setText(QString::number(pendLeaves));
}

UpdateAttendance::~UpdateAttendance()
{
    delete ui;
}

void UpdateAttendance::on_pushButton_clicked()
{
    accept();
}

