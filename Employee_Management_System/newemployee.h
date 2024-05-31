#ifndef NEWEMPLOYEE_H
#define NEWEMPLOYEE_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QString>

namespace Ui {
class NewEmployee;
}

class NewEmployee : public QDialog
{
    Q_OBJECT

public:
    explicit NewEmployee(QWidget *parent = nullptr);
    ~NewEmployee();

private slots:
    void on_pushButton_clicked();

private:
    Ui::NewEmployee *ui;
};

#endif // NEWEMPLOYEE_H
