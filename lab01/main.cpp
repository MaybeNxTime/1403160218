#include <QCoreApplication>
#include<QDebug>
#include<QList>
#include<QString>
#include<stdlib.h>


typedef struct list{
    int num;
    QString name;
    int grade1;
    int grade2;

}student;


/*void sortStudentGrade1(QList *score){
    qSort(score.begin(),score.end(),compareStudentGrade1);
}
void sortStudentGrade2(QList *score){
    qSort(score.begin(),score.end(),compareStudentGrade2);
}
void sortStudentName(QList *score){
    qSort(score.begin(),score.end(),compareStudentName);
}*/

bool compareStudentGrade1(const student &student1,const student &student2){     //关于成绩1比较
    if(student1.grade1>student2.grade1){
        return true;
    }
    else if(student1.grade1<student2.grade1){
        return false;
    }

}

bool compareStudentGrade2(const student &student1,const student &student2){     //关于成绩2比较
    if(student1.grade2>student2.grade2){
        return true;
    }
    else if(student1.grade2<student2.grade2){
        return false;
    }

}

bool compareStudentName(const student &student1,const student &student2){       //关于姓名比较
    if(student1.name>student2.name){
        return true;
    }
    else if(student1.name<student2.name){
        return false;
    }

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    student stu1,stu2,stu3,stu4;
    stu1.num=1403130209;
    stu1.name="lzs鲁智深";
    stu1.grade1=80;
    stu1.grade2=72;
    stu2.num=1403140101;
    stu2.name="lc林冲";
    stu2.grade1=82;
    stu2.grade2=76;
    stu3.num=1403140102;
    stu3.name="sj宋江";
    stu3.grade1=76;
    stu3.grade2=85;
    stu4.num=1403140103;
    stu4.name="ws武松";
    stu4.grade1=88;
    stu4.grade2=80;
    QList<student> score;
    score<<stu1<<stu2<<stu3<<stu4;
    qDebug()<<"学号\t\t"<<"姓名\t\t"<<"成绩1\t"<<"成绩2"<<endl;
    qSort(score.begin(),score.end(),compareStudentGrade1);
    for(int i=0;i<4;i++){
        qDebug()<<score.at(i).num<<"\t"<<score.at(i).name<<"\t"<<score.at(i).grade1<<"\t"<<score.at(i).grade2<<endl;
    }
    qDebug()<<"********************************************"<<endl;
    qDebug()<<"学号\t\t"<<"姓名\t\t"<<"成绩1\t"<<"成绩2"<<endl;
    qSort(score.begin(),score.end(),compareStudentGrade2);
    for(int i=0;i<4;i++){
        qDebug()<<score.at(i).num<<"\t"<<score.at(i).name<<"\t"<<score.at(i).grade1<<"\t"<<score.at(i).grade2<<endl;
    }
    qDebug()<<"********************************************"<<endl;
    qDebug()<<"学号\t\t"<<"姓名\t\t"<<"成绩1\t"<<"成绩2"<<endl;
    qSort(score.begin(),score.end(),compareStudentName);
    for(int i=0;i<4;i++){
        qDebug()<<score.at(i).num<<"\t"<<score.at(i).name<<"\t"<<score.at(i).grade1<<"\t"<<score.at(i).grade2<<endl;
    }

    return a.exec();
}
