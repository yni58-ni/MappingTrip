#include "profiledialog.h"
#include "ui_profiledialog.h"

#include <iostream>

ProfileDialog::ProfileDialog(int userID, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProfileDialog),
    userID(userID)
{
    ui->setupUi(this);
    Profile = db.getProfile(userID);
    update();
}

ProfileDialog::~ProfileDialog()
{
    delete ui;
}

void ProfileDialog::update()
{
    db.updateProfile(Profile.getuserID(),Profile.getName(),Profile.getGender(),Profile.getTagline(),Profile.getFileName(),Profile.getLocation());
    QString name = "Name111: " + Profile.getName();
    ui->Name->setText(name);
}
