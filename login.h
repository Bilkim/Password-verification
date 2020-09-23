#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QDialog>
#include <QDebug>
#include <QtSql>
#include <QFileInfo>
#include "employeeinfo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT
public:
    QSqlDatabase mydb;
    void connClose(){
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen()
    {
            mydb=QSqlDatabase::addDatabase("QSQLITE");
            mydb.setDatabaseName("/home/bill/Documents/Databases/newdatabase.db");

            if(!mydb.open()){
                qDebug()<<("Failed to open database");
                return false;
            }
            else{
                qDebug()<<("Connected.....");
                return  true;
            }
    }

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Login *ui;
    

    
    
};
#endif // LOGIN_H
