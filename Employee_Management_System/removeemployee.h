#ifndef REMOVEEMPLOYEE_H
#define REMOVEEMPLOYEE_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class RemoveEmployee;
}

class RemoveEmployee : public QDialog
{
    Q_OBJECT

public:
    explicit RemoveEmployee(QWidget *parent = nullptr);
    ~RemoveEmployee();

private slots:
    void on_done_btn_clicked();

private:
    Ui::RemoveEmployee *ui;
};

#endif // REMOVEEMPLOYEE_H
