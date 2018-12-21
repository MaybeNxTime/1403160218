#include "mydialog.h"
#include "ui_mydialog.h"
#include <QDebug>
#include <QMessageBox>
#include <QStringList>
#include <QSqlQuery>

QStringList MYDialog::setstudentinfo(){
    QStringList StudentList;//输入学生信息
    StudentList.append(ui->edtName->text());
    StudentList.append(ui->edtID->text());
    StudentList.append(ui->cbMajor->currentText());
    StudentList.append(ui->cbClass->currentText());
    StudentList.append(ui->cbYear->currentText());
    StudentList.append(ui->edtPhone->text());
    StudentList.append(ui->score1->text());
    StudentList.append(ui->score2->text());
    StudentList.append(ui->cbscore1->currentText());
    StudentList.append(ui->cbscore2->currentText());
    return StudentList;
}

MYDialog::MYDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MYDialog)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QMYSQL");//打开数据库
    db.setHostName("localhost");
    db.setDatabaseName("test");
    db.setPort(3306);
    db.setUserName("my");
    db.setPassword("");

    ui->cbClass->addItem("通信1601");
    ui->cbClass->addItem("通信1602");

}

MYDialog::~MYDialog()
{
    delete ui;
}



void MYDialog::on_buttonBox_clicked(){
    QStringList a=setstudentinfo();
    qDebug()<<a.at(1);
    if(db.isOpen()){
        db.close();
    }
    QString str;
    if(!db.open()){
        qDebug()<<"数据库连接出错";
        return;
    }
    else {
        QSqlQuery query;//插入数据
        QString querystr=QString("insert into t_stud_info value('%1','%2','%3','%4','%5','%6');").arg(a.at(1),a.at(0),a.at(2),a.at(3),a.at(4),a.at(5));
        query.prepare(querystr);
        bool i=query.exec();
        if(i==true){
            QMessageBox::about(NULL,"提示","数据插入成功");
        }
        else{
            QMessageBox::about(NULL,"提示","数据插入失败");
        }
        QStringList courseID;
        courseID<<"14040402"<<"14040421"<<"14040271"<<"14040781";
        querystr = QString("insert into t_stud_course_info value('','%1','%2','%3','','');").arg(ui->edtID->text(),courseID.at(0),ui->score1->text());
        query.prepare(querystr);
        query.exec();
        querystr = QString("insert into t_stud_course_info value('','%1','%2','%3','','');").arg(ui->edtID->text(),courseID.at(1),ui->score2->text());
        query.prepare(querystr);
        query.exec();
        querystr = QString("insert into t_stud_course_info value('','%1','%2','%3','','');").arg(ui->edtID->text(),courseID.at(2),ui->cbscore1->currentText());
        query.prepare(querystr);
        query.exec();
        querystr = QString("insert into t_stud_course_info value('','%1','%2','%3','','');").arg(ui->edtID->text(),courseID.at(3),ui->cbscore2->currentText());
        query.prepare(querystr);
        query.exec();


    db.close();
    }
}
