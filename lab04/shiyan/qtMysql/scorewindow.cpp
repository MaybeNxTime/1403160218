#include "scorewindow.h"
#include "ui_scorewindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <QSqlQuery>
#include <QStringList>
#include <QString>
#include <QLabel>
#include <QSqlDatabase>
#include <QSqlError>
#include<QFile>


ScoreWindow::ScoreWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ScoreWindow)
{
    ui->setupUi(this);
    db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setUserName("my");
    db.setPassword("");
    db.setDatabaseName("test");




}

ScoreWindow::~ScoreWindow()
{
    delete ui;
}




void ScoreWindow::queryStudentInfo(const QString querysql)//查询学生信息
{
    QSqlQuery query(querysql);
    while(query.next()){          //填充ui
        ui->lineEditID->setText(query.value(0).toString());
        ui->lineEditName->setText(query.value(1).toString());
        ui->lineEditMajor->setText(query.value(2).toString());
        ui->lineEditClass->setText(query.value(3).toString());
    }
}

QStringList ScoreWindow::queryStudentScore(const QString querysql)//查询学生绩点
{
    QStringList queryResult;
    QSqlQuery query(querysql);
    while(query.next()){
        queryResult.append(query.value(1).toString());
        queryResult.append(query.value(2).toString());
        queryResult.append(query.value(3).toString());
    }
    return queryResult;
}

void ScoreWindow::calculatePoint(const QStringList queryResult)
{
    QStringList courseList;
    QString courseName[7];
    QString courseScore[7];
    QString courseCredit[7];
    QString courseGPA[7];
    for(int j=0;j<7;j++)
    {
        courseList.append(queryResult.at(3*j));
        courseName[j]=queryResult.at(3*j);
        courseScore[j]=queryResult.at(3*j+1);
        courseCredit[j]=queryResult.at(3*j+2);
    }
    float gpa[7];
    for(int i=0;i<7;i++){
        if(courseScore[i]=="优秀") courseGPA[i] = "4.0";
        else if(courseScore[i]=="良好")  courseGPA[i] = "3.0";
        else if(courseScore[i]=="中等")  courseGPA[i] = "2.0";
        else if(courseScore[i]=="及格")  courseGPA[i] = "1.0";
        else if(courseScore[i]=="旷考")  courseGPA[i] = "0";
        else if(courseScore[i]=="缓考")  courseGPA[i] = "0";
        else{
            float score=courseScore[i].toFloat();//转化格式计算
            if(score<60){
                courseGPA[i]="0";
                gpa[i]=0;
            }
            else{
                gpa[i]=(score-50)/10;
                courseGPA[i]=QString("%1").arg(gpa[i]);
            }
        }
    }
    ui->textEdit->clear();//每次清空表
    float avg=0;//计算平均绩点
    float sum=0;
    float creditsum=0;
    for(int i=0;i<7;i++){
        float Credit=courseCredit[i].toFloat();
        creditsum=creditsum+Credit;
        sum=sum+Credit*gpa[i];
    }
    avg=sum/creditsum;
    QString gpaavg=QString::number(avg,'f',2);//转化为两位小数的QString
    QString name=ui->lineEditName->text();
    QString str1 = "<table border='1' cellpadding='10' align=   'center'>"
                   " <tr  bgcolor='white'>   <td align='center' colspan='5'>  "+name+"的成绩表  </td>  </tr>"
                   " <tr>   <td align='center'>编号</td>   <td align='left'>课程名称</td>   <td align='center'>成绩</td>    <td align='center'>学分</td>   <td align='center'>绩点</td> </tr> ";
    for(int i=0;i<7;i++){
        str1.append( " <tr>   <td align='center'> "+QString("%1").arg(i+1)+" </td>   <td align='left'>"+courseName[i]+"</td>   <td align='center'>"+courseScore[i]+"</td>    <td align='center'>"+courseCredit[i]+"</td>   <td align='center'>"+courseGPA[i]+"</td>    </tr> ");
    }
    str1.append(" <tr  bgcolor='white'>   <td align='center' colspan='5'>总绩点为："+gpaavg+"</td>   </tr>"
                                                                                       " </table> ");
    ui->textEdit->insertHtml(str1);
}
void ScoreWindow::on_btnQuery_clicked(){

    if(db.isOpen()){
        db.close();
    }

    if(!db.open()){
        qDebug()<<"数据库连接出错";
        return;
    }
    else
    {QString str;
        if(ui->radioStNumber->isChecked())//学号查找
            str = QString("where sNumber='%1'").arg(ui->edtInput->text());
        else if(ui->radioStName->isChecked())//名字查找
            str = QString("where sName='%1'").arg(ui->edtInput->text());
        QString queryStr = QString("SELECT * FROM t_stud_info %1;").arg(str);
        queryStudentInfo(queryStr);   //查询学生信息
        queryStr = QString("select t_stud_info.sName as '姓名',t_courses.courseName as '课程名称', "
                           "t_stud_course_info.scScores as '成绩',t_courses.courseCredit as '学分' "
                           "from(t_stud_course_info inner join t_courses on t_stud_course_info.scCourseID=t_courses.courseID)"
                           "inner join t_stud_info on t_stud_info.sNumber=t_stud_course_info.scNumber "
                           "%1 "
                           "order by t_stud_course_info.scNumber;").arg(str);
        QStringList queryResult = queryStudentScore(queryStr);  //查询学生成绩
        calculatePoint(queryResult);   //计算绩点  显示结果  QTextEdit + HTML
        db.close();

    }
}
void ScoreWindow::on_actionPL_triggered()
{
    QString path = QFileDialog::getOpenFileName(this, tr("批量导入"), ".", tr("csv Files(*.csv)"));
    if(path.length() == 0) {
        QMessageBox::information(NULL, tr("Info"), tr("You didn't select any files."));
        return;
    } else {
        QMessageBox::information(NULL, tr("Info"), tr("You selected ") + path);
    }

    /*读取文件*/
    QStringList  tempText;
    QFile file(path);
    qDebug()<<path;
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::critical(NULL,tr("错误"),tr("打开文件失败！"));
        return;
    }
    QTextStream out(&file);
    while(!out.atEnd()){
        tempText.append(out.readLine().trimmed());
    }

    file.close();

    /*数据库操作*/
    if(tempText.isEmpty())
        return;
    if(db.isOpen())
    {
        db.close(); //重启db
    }
    if(!db.open())
    {
        qDebug() << "Error: Failed to connect database." << db.lastError();
        return;
    }
    else{
        QString tempdata;
        QStringList singledata;
        QString  select_sql1;
        QString select_sql2;
        QStringList signalcourseID;
        QSqlQuery sql_query;       //数据库操作类

        tempdata=tempText.at(1);
        singledata=tempdata.split(',');
        qDebug()<<singledata;

        for(int i=0;i<4;i++){
            select_sql1 = QString("select courseID from t_courses where courseName='%1';").arg(singledata.at(5+i));


            if(!sql_query.exec(select_sql1))
            {
                qDebug()<<sql_query.lastError();
            }
            else
            {
                while(sql_query.next())
                {
                    signalcourseID<<sql_query.value(0).toString();

                }

            }
        }
        qDebug()<<signalcourseID;

        for(int i=1;i<tempText.size();i++)
        {
            tempdata=tempText.at(i);
            singledata=tempdata.split(',');
            qDebug()<<singledata;
            select_sql2 = QString("insert into t_stud_info value ('%1','%2','%3','%4','','');").arg(singledata.at(1),singledata.at(2),singledata.at(3),singledata.at(4));
            sql_query.exec(select_sql2);
            for(int j=0;j<4;j++){

                select_sql1 = QString("insert into t_stud_course_info value ('','%1','%2','%3','','');").arg(singledata.at(1),signalcourseID.at(j),singledata.at(5+j));
                sql_query.exec(select_sql1);
            }
        }
        QMessageBox::information(NULL, tr("Info"),tr("导入成功"));
    }

}

void ScoreWindow::on_actionAdd_triggered()
{
    mydialog = new MYDialog(this);
    mydialog->show();
}


void ScoreWindow::on_action_triggered()
{   

    ExportDB();
}
void ScoreWindow::ExportDB()
{

        {
                   if(db.isOpen()){
                       db.close();
                   }

                   if(!db.open()){
                       qDebug()<<"连接数据库出错";
                       return;
                   }
                   {
//                       QSqlQuery query;
//                       QString creat=QString("create database out.db;");
//                       query.exec(creat);
//                       QSqlDatabase db_sqlit=QSqlDatabase::addDatabase("QSQLITE");
//                       db_sqlit.setDatabaseName("out.db");
//                       if(!db_sqlit.open()){
//                           qDebug()<<"打开数据库错误！";
//                       }
//                       else{
//                           QSqlQuery query2(db_sqlit);
//                           QSqlQuery query3(db_sqlit);
//                           QSqlQuery query4(db_sqlit);

//                           query2.exec("drop table if exists t_courses;");


//                           query2.exec( "attach database 'target.db' as db_source;");


//                           query2.exec("create table t_courses as select * from db_source.t_courses;");

//                           query3.exec("drop table if exists t_stud_course_info;");


//                           query3.exec( "attach database 'target.db' as db_source;");


//                           query3.exec("create table t_stud_course_info as select * from db_source.t_stud_course_info;");

//                           query4.exec("drop table if exists t_stud_info;");


//                           query4.exec( "attach database 'target.db' as db_source;");


//                           query4.exec("create table t_stud_info as select * from db_source.t_stud_info;");


//                       }


//                       QMessageBox::information(NULL, tr("Info"),tr("导出成功"));
                       QSqlQuery query2(db);
//                       query2.exec("mysqldump -u my -p -hlocalhost test >'C:/Users/m7719/Documents/GitHub/1403160218/lab04/shiyan/build-qtMysql-Desktop_Qt_5_9_6_MinGW_32bit-Debug/new.sql'");

                       query2.exec("select * from test.t_courses into outfile 'C:/Users/m7719/Documents/GitHub/1403160218/lab04/shiyan/build-qtMysql-Desktop_Qt_5_9_6_MinGW_32bit-Debug/t_courses.csv' ;");
                       query2.exec("select * from test.t_stud_course_info into outfile 'C:/Users/m7719/Documents/GitHub/1403160218/lab04/shiyan/build-qtMysql-Desktop_Qt_5_9_6_MinGW_32bit-Debug/t_stud_course_info.csv' ;");
                       query2.exec("select * from test.t_stud_info into outfile 'C:/Users/m7719/Documents/GitHub/1403160218/lab04/shiyan/build-qtMysql-Desktop_Qt_5_9_6_MinGW_32bit-Debug/t_stud_info.csv' ;");
 //                      query2.exec("create database dbout.db;");

//                       QSqlQuery query;
//                       query.exec("create database dbout.db;");
                       QSqlDatabase db_out=QSqlDatabase::addDatabase("QSQLITE");
//                       db_out.setHostName("localhost");
//                       db_out.setPort(3306);
//                       db_out.setUserName("my");
//                       db_out.setPassword("");
                       db_out.setDatabaseName("dbout.db");
                       QFile file1("C:/Users/m7719/Documents/GitHub/1403160218/lab04/shiyan/build-qtMysql-Desktop_Qt_5_9_6_MinGW_32bit-Debug/t_courses.csv");
                     QFile file2("C:/Users/m7719/Documents/GitHub/1403160218/lab04/shiyan/build-qtMysql-Desktop_Qt_5_9_6_MinGW_32bit-Debug/t_stud_course_info.csv");
                     QFile file3("C:/Users/m7719/Documents/GitHub/1403160218/lab04/shiyan/build-qtMysql-Desktop_Qt_5_9_6_MinGW_32bit-Debug/t_stud_info.csv");
                       if(!db_out.open()){
                        qDebug()<<"打开数据库错误！";
                        }else{

                           QSqlQuery query3;
                           query3.exec("create table t_courses(courseID varchar(25) primary key, couseName varchar(25),courseCredit varchar(25),courseType varchar(25))");
                           query3.exec("create table t_stud_course_info(ID varchar(25)primary key,scNumber varchar(25),scCourseID varchar(25),scScores varchar(25),scYear varchar(25),scTerm varchar(25));");
                           query3.exec("create table t_stud_info(sNumber varchar(25) primary key,sName varchar(25),sMajor varchar(25),sClass varchar(25),sEnrolledYear varchar(25),sPhone varchar(25));");


                           QStringList list;
                           list.clear();
                           QTextStream in1(&file1);
                           while(!in1.atEnd()){
                               QString fileLine1=in1.readLine();
                               list=fileLine1.split("\t",QString::SkipEmptyParts);
                               query3.prepare("INSERT INTO t_course (courseID,courseName,courseCredit,courseType)VALUES(:id,:name,:cre,:typ)");
                               query3.bindValue(":id",list.at(0));
                               query3.bindValue(":name",list.at(1));
                               query3.bindValue(":cre",list.at(2));
                               query3.bindValue(":typ",list.at(3));
                               query3.exec();
                           }
                           query3.clear();

                           list.clear();
                           QTextStream in2(&file2) ;
                           while(!in2.atEnd()){
                               QString fileline2=in2.readLine();
                               list=fileline2.split("\t",QString::SkipEmptyParts);
                               query3.prepare("INSERT INTO t_stud_course_info (ID,scNumber,scCourseID,scScores,scYear,scTerm)VALUES(:Id,:num,:cid,:sco,:yea,:ter)");
                               query3.bindValue(":Id",list.at(0));
                               query3.bindValue(":num",list.at(1));
                               query3.bindValue(":cid",list.at(2));
                               query3.bindValue(":sco",list.at(3));
                               query3.bindValue(":yea",list.at(4));
                               query3.bindValue(":ter",list.at(5));
                               query3.exec();
                           }
                           query3.clear();

                           list.clear();
                           QTextStream in3(&file3) ;
                           while(!in3.atEnd()){
                               QString fileline3=in3.readLine();
                               list=fileline3.split("\t",QString::SkipEmptyParts);
                               query3.prepare("INSERT INTO t_stud_course_info (sNumber,sName,sMajor,sClass,sEnrolledYear,sPhone)VALUES(:snum,:sname,:sma,:scl,:sen,:sph)");
                               query3.bindValue(":snum",list.at(0));
                               query3.bindValue(":sname",list.at(1));
                               query3.bindValue(":sma",list.at(2));
                               query3.bindValue(":scl",list.at(3));
                               query3.bindValue(":sen",list.at(4));
                               query3.bindValue(":sph",list.at(5));
                               query3.exec();
                           }
                           query3.clear();
//                        query3.exec("LOAD DATA LOCAL INFILE C:/Users/m7719/Documents/GitHub/1403160218/lab04/shiyan/build-qtMysql-Desktop_Qt_5_9_6_MinGW_32bit-Debug/t_courses.csv INTO TABLE t_courses;");
//                           query3.exec("LOAD DATA LOCAL INFILE C:/Users/m7719/Documents/GitHub/1403160218/lab04/shiyan/build-qtMysql-Desktop_Qt_5_9_6_MinGW_32bit-Debug/t_stud_course_info.csv INTO TABLE t_stud_course_info;");
//                           query3.exec("LOAD DATA LOCAL INFILE C:/Users/m7719/Documents/GitHub/1403160218/lab04/shiyan/build-qtMysql-Desktop_Qt_5_9_6_MinGW_32bit-Debug/t_stud_info.csv INTO TABLE t_stud_info;");

//                           query3.exec("cd C:/Users/m7719/Documents/GitHub/1403160218/lab04/shiyan/build-qtMysql-Desktop_Qt_5_9_6_MinGW_32bit-Debug");
//                           query3.exec("sqlite3 dbout.db");

//                           query3.exec(".import t_courses.csv t_courses ");
//                           query3.exec(".import t_stud_course_info.csv t_stud_course_info ");
//                           query3.exec(".import t_stud_info.csv t_stud_info ");

//                           query2.exec("create table t_courses select * from test.t_courses;");
//                           query2.exec("create table t_stud_course_info select * from test.t_stud_course_info;");
//                           query2.exec("create table t_stud_info select * from test.t_stud_info;");
                            db_out.close();

                       }
                     QMessageBox::information(NULL, tr("Info"),tr("导出成功"));
             }
             }

             }


