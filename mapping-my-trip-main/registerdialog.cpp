#include "registerdialog.h"
#include "ui_registerdialog.h"

#include <QMessageBox>
#include "dbhelper.h"

/**
 * @brief a class to register new user
 * @author Nicole Ni
 * @param parent
 */

RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

QString RegisterDialog::getUserName()
{
    return ui->userNameLineEdit->text();
}

QString RegisterDialog::getPassword()
{
    return ui->passwordLineEdit->text();
}

/**
 * @brief register user by click the botton
 */
void RegisterDialog::on_acceptButton_clicked()
{
    DBHelper helper;
    helper.open();
    int userId= helper.checkUser(ui->userNameLineEdit->text(), ui->passwordLineEdit->text());
    if(userId<0) {
        helper.addUser(ui->userNameLineEdit->text(), ui->passwordLineEdit->text());
        helper.addProfile(helper.checkUser(ui->userNameLineEdit->text(), ui->passwordLineEdit->text()),ui->userNameLineEdit->text(),0,"",":/Profile_image.png","");
        helper.close();
        accept();
    } else {
        QMessageBox::information(this, "Error", "User exists");
        helper.close();
    }
}


void RegisterDialog::on_cancelButton_clicked()
{
    reject();
}

