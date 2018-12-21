#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class MYDialog;
}

class MYDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MYDialog(QWidget *parent = 0);
    ~MYDialog();
    QStringList setstudentinfo();

protected:
    QStringList querycourseID(const QStringList courseName);

private slots:
    void on_buttonBox_clicked();


private:
    Ui::MYDialog *ui;
    QSqlDatabase db;
};

#endif // MYDIALOG_H
