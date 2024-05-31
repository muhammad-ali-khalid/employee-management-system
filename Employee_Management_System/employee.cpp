#include "employee.h"
using namespace std;
Employee::Employee(QString username, int id, QString name, int age, QString gender,
                   QString department, QString email, QString mobile, QString cnic, int salary,
                   QString experienceInYears, int totalLeaves, int approvedLeaves, int rejectedLeaves, int pendingLeaves, QString currentTask){
    setUsername(username);
    setId(id);
    setName(name);
    setAge(age);
    setGender(gender);
    setDepartment(department);
    setEmail(email);
    setMobile(mobile);
    setCnic(cnic);
    setSalary(salary);
    setExperienceInYears(experienceInYears);
    setTotalLeaves(totalLeaves);
    setApprovedLeaves(approvedLeaves);
    setRejectedLeaves(rejectedLeaves);
    setPendingLeaves(pendingLeaves);
    setCurrentTask(currentTask);

}
// Setters
void Employee::setUsername(QString userName){
    this->username = userName;
}
void Employee::setId(int id){
    this->id = id;
}
void Employee::setName(QString name){
    this->name = name;
}
void Employee::setAge(int age){
    if(age >= 18)
        this->age = age;
}
void Employee::setGender(QString gender){
    if(gender == "male" || gender == "female")
        this->gender = gender;
}
void Employee::setDepartment(QString department){
    this->department = department;
}
void Employee::setEmail(QString email){
    this->email = email;
}
void Employee::setMobile(QString mobile){
    if (mobile.length() == 11)
        this->mobile = mobile;
}
void Employee::setCnic(QString cnic){
    if(cnic.length() == 13)
        this->cnic = cnic;
}
void Employee::setSalary(int salary){
    if(salary > 0)
        this->salary = salary;
}
void Employee::setExperienceInYears(QString experienceInYears){
    this->experienceInYears = experienceInYears;
}
void Employee::setTotalLeaves(int totalLeaves){
    if(totalLeaves >= 0 && totalLeaves <= 20)
        this->totalLeaves = totalLeaves;
}
void Employee::setApprovedLeaves(int approvedLeaves){
    if(approvedLeaves <= totalLeaves)
        this->approvedLeaves = approvedLeaves;
}
void Employee::setRejectedLeaves(int rejectedLeaves){
    if(rejectedLeaves <= totalLeaves)
        this->rejectedLeaves = rejectedLeaves;
}
void Employee::setPendingLeaves(int pendingLeaves){
    this->pendingLeaves = pendingLeaves;
}
void Employee::setCurrentTask(QString currentTask){
    this->currentTask = currentTask;
}
// Getters
QString Employee::getUsername(){
    return this->username;
}
int Employee::getId(){
    return this->id;
}
QString Employee::getName(){
    return this->name;
}
int Employee::getAge(){
    return this->age;
}
QString Employee::getGender(){
    return this->gender;
}
QString Employee::getDepartment(){
    return this->department;
}
QString Employee::getEmail(){
    return this->email;
}
QString Employee::getMobile(){
    return this->mobile;
}
QString Employee::getCnic(){
    return this->cnic;
}
int Employee::getSalary(){
    return this->salary;
}
QString Employee::getExperienceInYears(){
    return this->experienceInYears;
}
int Employee::getTotalLeaves(){
    return this->totalLeaves;
}
int Employee::getApprovedLeaves(){
    return this->approvedLeaves;
}
int Employee::getRejectedLeaves(){
    return this->rejectedLeaves;
}
int Employee::getPendingLeaves(){
    return pendingLeaves;
}
QString Employee::getCurrentTask(){
    return this->currentTask;
}
