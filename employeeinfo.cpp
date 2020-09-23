#include "employeeinfo.h"
#include "ui_employeeinfo.h"
#include <QMessageBox>

EmployeeInfo::EmployeeInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployeeInfo)
{
    ui->setupUi(this);
    Login conn;
        if(!conn.connOpen())
            ui->label->setText("Failed to open database");
        else
            ui->label->setText("Connected.....");
}

EmployeeInfo::~EmployeeInfo()
{
    delete ui;
}

void EmployeeInfo::on_pushButton_clicked()
{
    Login conn;
    QString username,password,email;

    username = ui->lineEdit->text();
    password = ui->lineEdit_2->text();
    email = ui->lineEdit_email->text();

    if(!conn.connOpen()){
        qDebug()<<("Failed to open database");
        return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into secdialog (Username,Password,Email) values( '"+username+"', '"+password+"', '"+email+"')");

    if(qry.exec())
    {
        QMessageBox:: critical(this,tr("Save"),tr("Saved"));
        conn.connClose();
    }
    else {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
}

void EmployeeInfo::on_pushButton_2_clicked()
{


    QMessageBox::critical(this,tr("Message"),tr("Welcome"));

}
