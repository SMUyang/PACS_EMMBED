#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <QFileDialog>
#include <QString>
#include <QImage>
#include <QMessageBox>
#include <QStatusBar>
#include <QDir>
#include <QDateTime>

QStringList GetDirNameList(const QString &strDirpath)//获取文件夹名
{
    QDir dir(strDirpath);
    QFileInfoList Info_list = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
    QListIterator<QFileInfo> Iterator(Info_list);
    QStringList strDirNameList;
    QFileInfo Info;
    while (Iterator.hasNext())
    {
        Info = Iterator.next();
        if (Info.isDir())
        {
            strDirNameList << QDir(Info.absoluteFilePath()).dirName();
        }
    }
    return strDirNameList;


}

//获取文件名
QStringList GetDirPathList(const QString &strDirpath)
{

        QDir dir(strDirpath);
        QFileInfoList Info_list = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
        QListIterator<QFileInfo> Iterator(Info_list);
        QStringList strDirPathList;
        QFileInfo Info;
        while (Iterator.hasNext())
        {
            Info = Iterator.next();
            if (Info.isDir())
            {
                strDirPathList << Info.absoluteFilePath();
            }
        }
        return strDirPathList;
}

//获取文件列表
QStringList GetFileNameList(const QString &strDirpath)
{
        QDir dir(strDirpath);
        QFileInfoList Info_list = dir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot);
        QListIterator<QFileInfo> Iterator(Info_list);
        QStringList strFileNameList;
        QFileInfo Info;
        while (Iterator.hasNext())
        {
            Info = Iterator.next();
            if (Info.isFile())
            {
                strFileNameList << Info.fileName();
            }
        }
        return strFileNameList;

}

//获取文件夹列表
QStringList GetFilePathList(const QString &strDirpath)
{
    QDir dir(strDirpath);
    QFileInfoList Info_list = dir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot);
    QListIterator<QFileInfo> Iterator(Info_list);
    QStringList strFilePathList;
    QFileInfo Info;
    while (Iterator.hasNext())
    {
        Info = Iterator.next();
        if (Info.isFile())
        {
            strFilePathList << Info.filePath();
        }
    }
    return strFilePathList;
}


QString Mainfile = "H:\\03【日常】第三卷\\";
QStringList listcontent;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
   ui->setupUi(this);
  listcontent << GetFileNameList(Mainfile);
   ui->listWidget->addItems(listcontent);
   //ui->label->setScaledContents(true);
    ui->statusbar->setSizeGripEnabled(false);


}
MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_actionopen_triggered()
{
 QString filename;
 filename =  QFileDialog::getOpenFileName(this,"open an image:","H:\\03【日常】第三卷\\","Image(*.jpg *.png)");
 if(!filename.isEmpty())
 {
     QImage* im = new QImage;
     if(!( im->load(filename) ) ) //加载图像
         {
             QMessageBox::information(this,
                                      tr("打开图像失败"),
                                      tr("打开图像失败!"));
             delete im;
         }
     else
     {
        QFileInfo inffile(filename);
        int wi,hi;
        int height = ui->label->height();
        int width = ui->label->width();
        float precent;
        wi = im->width();
        hi = im->height();
        qDebug()<<hi<<wi<<height<<width;

        if(hi >=height && wi<=width)
        {
            precent = (float)height/(float)hi;
            wi = (int)(wi * precent);
            hi = (int)(hi * precent);
            qDebug()<<hi<<wi;
        }
        else
           {
            if(hi <= height && wi>= width)
            {
                precent = (float)width/(float)wi;
                wi = (int)(wi * precent);
                hi = (int)(hi * precent);
                qDebug()<<hi<<wi;
            }
            else
                if(hi >height && wi > width)
                {
                    float pre1, pre2;
                    pre1 = (float)hi/(float)height;
                    pre2 = (float)wi/(float)width ;
                    qDebug()<<pre1<<pre2;
                    precent = qMax(pre1,pre2);
                     qDebug()<<precent;
                    wi = (int)(wi / precent)-70;
                    hi = (int)(hi / precent)-70;
                    qDebug()<<hi<<wi;
                }
        }
        qDebug()<<hi<<wi;
        *im = im->scaled(wi,hi,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
        ui->label->setPixmap(QPixmap::fromImage(*im));
        ui->statusbar->showMessage(filename,2000);
        QDateTime dt = inffile.created();

        ui->label_2->setText(dt.toString());

        delete im;
     }
 }

}





void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QString dir = item->text();
    dir = Mainfile + dir;
    qDebug()<<dir;
    if(!dir.isEmpty())
    {
        QImage* im = new QImage;
        if(!( im->load(dir) ) ) //加载图像
        {
            QMessageBox::information(this,
                                     tr("打开图像失败"),
                                     tr("打开图像失败!"));
            delete im;
        }
        else
        {
            QFileInfo inffile(dir);
            int wi,hi;
            int height = ui->label->height();
            int width = ui->label->width();
            float precent;
            wi = im->width();
            hi = im->height();
            qDebug()<<hi<<wi<<height<<width;

            if(hi >=height && wi<=width)
            {
                precent = (float)height/(float)hi;
                wi = (int)(wi * precent);
                hi = (int)(hi * precent);
                qDebug()<<hi<<wi;
            }
            else
            {
                if(hi <= height && wi>= width)
                {
                    precent = (float)width/(float)wi;
                    wi = (int)(wi * precent);
                    hi = (int)(hi * precent);
                    qDebug()<<hi<<wi;
                }
                else
                    if(hi >height && wi > width)
                    {
                        float pre1, pre2;
                        pre1 = (float)hi/(float)height;
                        pre2 = (float)wi/(float)width ;
                        qDebug()<<pre1<<pre2;
                        precent = qMax(pre1,pre2);
                        qDebug()<<precent;
                        wi = (int)(wi / precent)-70;
                        hi = (int)(hi / precent)-70;
                        qDebug()<<hi<<wi;
                    }
            }
            qDebug()<<hi<<wi;
            *im = im->scaled(wi,hi,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
            ui->label->setPixmap(QPixmap::fromImage(*im));
            QDateTime dt = inffile.created();
            ui->label_2->setText(dt.toString());
            ui->statusbar->showMessage(dir,2000);

            delete im;
        }
    }

}
