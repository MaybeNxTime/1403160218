#include <QCoreApplication>
#include<QDebug>
#include<QList>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))

#define hhi(xxx) ((qint8)((qint32)(xxx)>>24))
#define lhi(xxx) ((qint8)(((qint32)(xxx)>>16)&255))
#define hlo(xxx) ((qint8)(((qint32)(xxx)>>8)&255))
#define llo(xxx) ((qint8)((qint32)(xxx)&255))
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qint32 i=0x12345678,j;
    qDebug()<<"initial number:"<<QString("0x%2").arg(i,0,16,QLatin1Char(' '))<<"=="<<
i;
    qDebug()<<QString("0x%2").arg(hhi(i),4,16,QLatin1Char(' '))<<"=="<<hhi(i); /*HHI8*/
    qDebug()<<QString("0x%2").arg(lhi(i),4,16,QLatin1Char(' '))<<"=="<<lhi(i); /*LHI8*/
    qDebug()<<QString("0x%2").arg(hlo(i),4,16,QLatin1Char(' '))<<"=="<<hlo(i); /*HLO8*/
    qDebug()<<QString("0x%2").arg(llo(i),4,16,QLatin1Char(' '))<<"=="<<llo(i); /*LLO8*/

    QList<quint8> values;
    values <<hhi(i)<<lhi(i)<<hlo(i)<<llo(i);                                      /*将结果存入QList<quint8>对象values中*/
    qDebug()<<"最高8位和次高8位的最大值:"<<Max(QString("0x%2").arg(hhi(i),4,16,QLatin1Char(' ')),QString("0x%2").arg(lhi(i),4,16,QLatin1Char(' ')))<<Max(hhi(i),lhi(i));
    qDebug()<<"次低8位和最低8位的最小值:"<<Min(QString("0x%2").arg(hlo(i),4,16,QLatin1Char(' ')),QString("0x%2").arg(llo(i),4,16,QLatin1Char(' ')))<<Min(hlo(i),llo(i));
    j=(hhi(i)<<16)+lhi(i)+(hlo(i)<<24)+(llo(i)<<8);
    qDebug()<<"重新组合后数值:"<<QString("0x%2").arg(j,4,16,QLatin1Char(' '))<<"=="<<j;
    qDebug()<<"排序前为:"<<values;                                                 //将values中的数字输出
    std::sort(values.begin(),values.end(),std::greater<quint8>());                //将values中的数字按从大到小排序
    qDebug()<<"排序后为:"<<values;
    return a.exec();
}
