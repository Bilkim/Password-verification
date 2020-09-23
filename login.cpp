#include "login.h"
#include "ui_login.h"
#include <QMessageBox>


Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    
    if(!connOpen())
        ui->label->setText("Failed to open database");
    else
        ui->label->setText("Connected.....");
    
    
}

Login::~Login()
{
    delete ui;
}


void Login::on_pushButton_clicked()
{
    QString username,password;
    username = ui->lineEdit->text();
    password = ui->lineEdit_2->text();

    if(!connOpen()){
        qDebug()<<("Failed to open database");
        return;
    }

    connOpen();
    QSqlQuery qry;
    qry.prepare("select * from secdialog where Username='"+username+"'and Password='"+password+"'");

    if(qry.exec())
    {
        int count=0;
        while(qry.next()){
            count++;
        }
        if(count==1){
            ui->label->setText("Username and password is correct");
            connClose();
            this->hide();
            EmployeeInfo employeeinfo;
            employeeinfo.setModal(true);
            employeeinfo.exec();

        }
        if(count>1)
            ui->label->setText("Duplicate username and password");
        if(count<1)
            ui->label->setText("Username and password is incorrect");
    }


}

void Login::on_pushButton_2_clicked()
{
    this->hide();
    EmployeeInfo employeeinfo;
    employeeinfo.setModal(true);
    employeeinfo.exec();
}
