#ifndef ASSIGNTASK_H
#define ASSIGNTASK_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class AssignTask;
}

class AssignTask : public QDialog
{
    Q_OBJECT

public:
    explicit AssignTask(QWidget *parent = nullptr);
    ~AssignTask();

private slots:
    void on_done_btn_clicked();

private:
    Ui::AssignTask *ui;
};

#endif // ASSIGNTASK_H
