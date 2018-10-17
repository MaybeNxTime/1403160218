#include <QDebug>
#include <QTextStream>
#include <QFile>
#include<QCoreApplication>

namespace SK {
enum SortKind{
    col01    =   0x00000001<<0,         //!< 第1列
    col02    =   0x00000001<<1,         //!< 第2列
    col03    =   0x00000001<<2,         //!< 第3列
    col04    =   0x00000001<<3,         //!< 第4列
    col05    =   0x00000001<<4,         //!< 第5列
    col06    =   0x00000001<<5,         //!< 第6列
    col07    =   0x00000001<<6,         //!< 第7列
    col08    =   0x00000001<<7,         //!< 第8列
    col09    =   0x00000001<<8,         //!< 第9列
    col10    =   0x00000001<<9,         //!< 第10列
    col11    =   0x00000001<<10,        //!< 第11列
    col12    =   0x00000001<<11,        //!< 第12列
    col13    =   0x00000001<<12,        //!< 第13列
    col14    =   0x00000001<<13,        //!< 第14列
    col15    =   0x00000001<<14,        //!< 第15列
    col16    =   0x00000001<<15,        //!< 第16列
    col17    =   0x00000001<<16,        //!< 第17列
    col18    =   0x00000001<<17,        //!< 第18列
    col19    =   0x00000001<<18,        //!< 第19列
    col20    =   0x00000001<<19,        //!< 第20列
    col21    =   0x00000001<<20,        //!< 第21列
    col22    =   0x00000001<<21,        //!< 第22列
    col23    =   0x00000001<<22,        //!< 第23列
    col24    =   0x00000001<<23,        //!< 第24列
    col25    =   0x00000001<<24,        //!< 第25列
    col26    =   0x00000001<<25,        //!< 第26列
    col27    =   0x00000001<<26,        //!< 第27列
    col28    =   0x00000001<<27,        //!< 第28列
    col29    =   0x00000001<<28,        //!< 第29列
    col30    =   0x00000001<<29,        //!< 第30列
    col31    =   0x00000001<<30,        //!< 第31列
    col32    =   0x00000001<<31,        //!< 第32列
};
}

//#define myCmp(a) ((d1.stu_data.at(a-1)>=d2.stu_data.at(a-1))? 1:0
//只用一个Qlist;
typedef struct{
    QList<QString> student;
} studData;



//运算符重载函数。可以直接输出studData结构;
//参考资料：zhuanlan.zhihu.com/p/32637822
QDebug operator << (QDebug d, const studData &data) {

    for(int i=0;i<data.student.size();i++)
        {
           d.noquote().nospace()<<QString(data.student.at(i))<<"\t";
        }

    return d;
}

// 比较类，用于生成std::sort第三个参数
class myCmp {
public:
    myCmp(int selectedColumn) { this->currentColumn = selectedColumn; }
    bool operator() (const studData& d1,const studData& d2) ;
private:
    int currentColumn;
};

bool myCmp::operator()(const studData &d1, const studData &d2)
{
   return (d1.student.at(currentColumn+1)>d2.student.at(currentColumn+1));


}

//排序类
class ScoreSorter
{
public:
    ScoreSorter(QString dataFile);
    void readfile();
    void dsort();
private:
    QString tfile;
    QList<studData> data;
    studData title;
    void outfile(qint8 column);

};

// 构造函数
ScoreSorter::ScoreSorter(QString dataFile){
    this->tfile=dataFile;
}
//函数体
void ScoreSorter::readfile(){
    QFile file(this->tfile);                               /* 以只读方式打开文本*/
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        qDebug()<<"[ERROR]:Cannot open the file!"<<endl;
//        return -1;
    }
    QString tittle(file.readLine());
    this->title.student=tittle.split(" ",QString::SkipEmptyParts);//按空格(" ")分割表头。


    studData perdata;
    while(!file.atEnd()){
        QByteArray line = file.readLine();
        QString str(line);
        perdata.student=str.split(" ",QString::SkipEmptyParts);//按空格(" ")分割数据。参考资料：https://blog.csdn.net/jack_bro/article/details/70160718
        this->data.append(perdata);
    }
    file.close();
}

void ScoreSorter::dsort(){
    for(int i=1;i<title.student.size();i++){
        /*参考资料：https://blog.csdn.net/maverick1990/article/details/37738601   声明比较规则类*/
        myCmp thiscmp(i-1);//初始化
        std::sort(this->data.begin(),this->data.end() , myCmp::operator()) ;
        qDebug()<<"当前按照第"<<i+1<<"列排序："<<endl;
        qDebug()<<(this->title); //qDebug重载后输出
        for(int i=0;i<this->data.size();i++)
            qDebug()<<this->data.at(i);
        qDebug()<<"**************************************************************\n";
        this->outfile(i+1); //当前排序方法，结果输出至文件
    }

}
//输出至文件的函数体
void ScoreSorter::outfile(qint8 column){
    QFile file("sorted_"+ this->tfile);
    file.open(QIODevice::ReadWrite|QIODevice::Append);/*读写与append方式打开文件;*/
    QTextStream stream(&file);
     /*参考资料：https://blog.csdn.net/bladeandmaster88/article/details/54868654   codec setting*/
    stream.setCodec("UTF-8");   //  设置编码方式
    stream<<QString("排序后输出，当前按照第")<<column<<QString("列排序")<<"\r\n";
    stream<<"\t";
    for(int i=0;i<this->title.student.size();i++)
        stream<<this->title.student.at(i)<<"\t";/*输出表头*/
    stream<<"\r\n";

    for(int j=0;j<this->data.size();j++){
        for(int k=0;k<this->title.student.size();k++)/*输出数据*/
            stream<<this->data.at(k).student.at(j)<<"\t";
        stream<<"\r\n";
    }
    stream<<"*******************************************************************"<<"\r\n\r\n";
    file.close();

}

//void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
//{
//    // 自定义qDebug
//}

int main(int argc,char *argv[])
{
//    qInstallMessageHandler(myMessageOutput);
    QCoreApplication a(argc,argv);
    QString datafile = "data.txt";

    // 如果排序后文件已存在，则删除之
    QFile f("sorted_"+datafile);
    if (f.exists()){
        f.remove();
    }

    ScoreSorter s(datafile);
    s.readfile();
    s.dsort();
    return a.exec();
}
