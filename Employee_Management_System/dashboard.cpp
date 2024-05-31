#include "dashboard.h"
#include "ui_dashboard.h"

Dashboard::Dashboard(Employee &employee,QWidget *parent):
    QDialog(parent),
    ui(new Ui::Dashboard)
{
    emp = employee;
    ui->setupUi(this);

    // ##############SIDE_NAVIGATION_BAR######################
    QIcon home("/home/muhammad-ali/icons/home.png");
    ui->home_btn->setIcon(home);
    ui->home_btn->setIconSize(QSize(25, 25));
    ui->home_btn->setFixedSize(QSize(25, 25));
    ui->home_btn->setFocusPolicy(Qt::NoFocus);

    QIcon salary("/home/muhammad-ali/icons/salary.png");
    ui->salary_btn->setIcon(salary);
    ui->salary_btn->setIconSize(QSize(25, 25));
    ui->salary_btn->setFixedSize(QSize(25, 25));
    ui->salary_btn->setFocusPolicy(Qt::NoFocus);

    QIcon attendance("/home/muhammad-ali/icons/attendance.png");
    ui->attendance_btn->setIcon(attendance);
    ui->attendance_btn->setIconSize(QSize(25, 25));
    ui->attendance_btn->setFixedSize(QSize(25, 25));
    ui->attendance_btn->setFocusPolicy(Qt::NoFocus);

    QIcon performance("/home/muhammad-ali/icons/performance.png");
    ui->performance_btn->setIcon(performance);
    ui->performance_btn->setIconSize(QSize(25, 25));
    ui->performance_btn->setFixedSize(QSize(25, 25));
    ui->performance_btn->setFocusPolicy(Qt::NoFocus);

    QIcon logout("/home/muhammad-ali/icons/logout.png");
    ui->logout_btn->setIcon(logout);
    ui->logout_btn->setIconSize(QSize(25, 25));
    ui->logout_btn->setFixedSize(QSize(25, 25));
    ui->logout_btn->setFocusPolicy(Qt::NoFocus);

    //#######################HOME_PAGE#######################
    ui->welcome_label->setText("Welcome Back " + emp.getName() + "!");
    QPixmap female_pic("/home/muhammad-ali/Downloads/female_profile.png");
    QPixmap male_pic("/home/muhammad-ali/Downloads/male_profile.png");
    if (emp.getGender() == "female"){
        ui->profile_img_1->setPixmap(female_pic);
        ui->profile_img_2->setPixmap(female_pic);
        ui->profile_img_3->setPixmap(female_pic);
        ui->profile_img_4->setPixmap(female_pic);
    }
    else{
         ui->profile_img_1->setPixmap(male_pic);
         ui->profile_img_2->setPixmap(male_pic);
         ui->profile_img_3->setPixmap(male_pic);
         ui->profile_img_4->setPixmap(male_pic);
    }

    // Displaying employee's information
    ui->empID_label->setText("Employee ID: " + QString::number(emp.getId()));
    ui->empName_label->setText("Name: " + emp.getName());
    ui->empAge_label->setText("Age: " + QString::number(emp.getAge()) + "years");
    ui->empGender_label->setText("Gender: " + emp.getGender());
    ui->empDept_label->setText("Department: " + emp.getDepartment());
    ui->empEmail_label->setText("Email: " + emp.getEmail());
    ui->empMobile_label->setText("Mobile number: " + emp.getMobile());
    ui->empCnic_label->setText("CNIC: " + emp.getCnic());
    ui->empExp_label->setText("Experience: " + emp.getExperienceInYears()+ "years");
    if(emp.getCurrentTask() != ""){
        ui->task_label->setText("Current task: " + emp.getCurrentTask());
    }
    else{
        ui->task_label->setText("Current task:    -");
    }
    //#######################SALARY_PAGE#######################
    ui->salary_label->setText(QString::number(emp.getSalary()) + "  rupees per month");
    ui->tax_label->setText("Tax: " + QString::number((5 * emp.getSalary()) / 100));
    ui->bonus_label->setText("Bonus: "+QString::number((10 * emp.getSalary()) / 100));

    //####################ATTENDANCE_PAGE####################
    ui->total_leaves_label->setText(QString::number(emp.getTotalLeaves()));
    ui->approved_leaves_label->setText(QString::number(emp.getApprovedLeaves()));
    ui->rejected_leaves_label->setText(QString::number(emp.getRejectedLeaves()));
    ui->pending_leaves_label->setText(QString::number(emp.getPendingLeaves()));

    //####################PERFORMANCE_PAGE####################

}

// Destructor
Dashboard::~Dashboard()
{
    delete ui;
}

// Managing different windows in dashboard
void Dashboard::on_home_btn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->home_page);
}

void Dashboard::on_salary_btn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->salary_page);
}


void Dashboard::on_attendance_btn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->attendance_page);
}


void Dashboard::on_performance_btn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->performance_page);
}

void Dashboard::on_leave_btn_clicked()
{
    LeaveApply leave(emp);
    leave.setModal(true);
    leave.setWindowTitle("Apply for leave");
    leave.exec();
    QSqlDatabase db2 = QSqlDatabase::addDatabase("QSQLITE");
    db2.setDatabaseName("/home/muhammad-ali/Downloads/EMS.db");
    if(db2.open()){
        QSqlQuery query(db2);
        query.prepare("SELECT total_leaves, pending_leaves FROM Employee WHERE id = :empId;");
        query.bindValue(":empId", emp.getId());
        if(query.exec() && query.next()){
            int totalLeaves = query.value("total_leaves").toInt();
            int pendingLeaves = query.value("pending_leaves").toInt();
            ui->total_leaves_label->setText(QString::number(totalLeaves));
            ui->pending_leaves_label->setText(QString::number(pendingLeaves));
            db2.close();
        }
    }
}

void Dashboard::on_logout_btn_clicked()
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
