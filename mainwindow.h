#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_actionopen_triggered();//open image from meun

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);//open image from list

private:
    Ui::MainWindow *ui;
};
QStringList GetDirNameList(const QString &strDirpath);
QStringList GetDirPathList(const QString &strDirpath);
QStringList GetFileNameList(const QString &strDirpath);
QStringList GetFilePathList(const QString &strDirpath);

#endif // MAINWINDOW_H
