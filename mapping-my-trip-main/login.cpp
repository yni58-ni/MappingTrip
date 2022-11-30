#include "login.h"
#include "ui_login.h"
#include <QApplication>
#include <QMessageBox>
#include <map.h>

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

                                                                                                    //CHECK USERNAME AND PASSWORD CORRECT
    if (username == "admin" && password=="admin") {
        hide();
        QMessageBox::information(this,"Login","Loggin successfully \nPress enter to continue");
        map = new class map(this);                                                                  //OPEN MAP in map.cpp
        map->show();
    } else {
        QMessageBox::warning(this,"Login","Username or password is wrong");
    }
}

