#include "manageattendance.h"
#include "ui_manageattendance.h"

ManageAttendance::ManageAttendance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageAttendance)
{
    ui->setupUi(this);
}

ManageAttendance::~ManageAttendance()
{
    delete ui;
}

void ManageAttendance::on_pushButton_clicked()
{
    int empID = ui->spinBox->value();
    UpdateAttendance obj(empID);
    obj.setModal(true);
    obj.setWindowTitle("Manange leaves");
    obj.exec();
    accept();
}

