#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <QString>
using namespace std;


class Employee
{
private:
    QString username = "";
    int id = 0;
    QString name = "";
    int age = 18;
    QString gender = "";
    QString department = "";
    QString email = "";
    QString mobile = "";
    QString cnic = "";
    int salary = 0;
    QString experienceInYears = "0";
    int totalLeaves = 0;
    int approvedLeaves = 0;
    int rejectedLeaves = 0;
    int pendingLeaves = 0;
    QString currentTask = "";

public:
    // Constructors
    Employee(){}
    Employee(QString username, int id, QString name, int age, QString gender, QString department,
             QString email, QString mobile, QString cnic, int salary, QString experinceInYears,
             int totalLeaves, int approvedLeaves, int rejectedLeaves, int pendingLeaves, QString currentTask);
    // Destructors
    ~Employee(){};
    // Setters
    void setUsername(QString userName);
    void setId(int id);
    void setName(QString name);
    void setAge(int age);
    void setGender(QString gender);
    void setDepartment(QString department);
    void setEmail(QString email);
    void setMobile(QString mobile);
    void setCnic(QString cnic);
    void setSalary(int salary);
    void setExperienceInYears(QString experience);
    void setTotalLeaves(int totalLeaves);
    void setApprovedLeaves(int approvedLeaves);
    void setRejectedLeaves(int rejectedLeaves);
    void setPendingLeaves(int pendingLeaves);
    void setCurrentTask(QString currentTask);
    // Getters
    QString getUsername();
    int getId();
    QString getName();
    int getAge();
    QString getGender();
    QString getDepartment();
    QString getEmail();
    QString getMobile();
    QString getCnic();
    int getSalary();
    QString getExperienceInYears();
    int getTotalLeaves();
    int getApprovedLeaves();
    int getRejectedLeaves();
    int getPendingLeaves();
    QString getCurrentTask();
};

#endif // EMPLOYEE_H
