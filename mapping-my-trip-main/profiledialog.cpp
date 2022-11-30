#include "profiledialog.h"
#include "ui_profiledialog.h"

#include <iostream>
/**
 * @brief Profile dialog is the ui for users to view their profile and edit it
 * @author Wenlong Zheng
 * @return
 */
ProfileDialog::ProfileDialog(int userID, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProfileDialog),
    userID(userID)
{
    font.setPixelSize(14);
    font.setFamily("Times New Roman");
    font.setCapitalization(QFont::Capitalize);
    ui->setupUi(this);
    Profile = db.getProfile(userID);
    QString create = "Created Since " + Profile.getCreateTime();
    ui->CreateTime ->setFont(font);
    ui->CreateTime->setText(create);
    generate_profile();
    connect(profile_list[0],&ClickableLabel::transmit,this,&ProfileDialog::update_name);
    connect(profile_list[1],&ClickableLabel::transmit,this,&ProfileDialog::update_gender);
    connect(profile_list[2],&ClickableLabel::transmit,this,&ProfileDialog::update_location);
    connect(profile_list[3],&ClickableLabel::transmit,this,&ProfileDialog::update_tagline);
    update();
}

ProfileDialog::~ProfileDialog()
{
    delete ui;
}

void ProfileDialog::update()
{
    db.updateProfile(Profile.getuserID(),Profile.getName(),Profile.getGender(),Profile.getTagline(),Profile.getFileName(),Profile.getLocation());
    QString name = " Name: " + Profile.getName();
    profile_list[0] ->setText(name);
    QString gender = " Gender: " + Profile.getRealGender();
    profile_list[1] ->setText(gender);
    QString Tagline = " Tagline: " + Profile.getTagline();
    QString Location = " Location: " + Profile.getLocation();
    profile_list[2] ->setText(Location);
    profile_list[3] ->setText(Tagline);
    QPixmap pix(Profile.getFileName());
    ui ->Image ->setPixmap(pix);
}

void ProfileDialog::update_name(){
    Profile.newName(profile_list[0]->Content());
    update();
}

void ProfileDialog::update_gender(){
    Profile.newGender(profile_list[1]->Content().toInt());
    update();
}
void ProfileDialog::update_location(){
    Profile.newLocation(profile_list[2]->Content());
    update();
}
void ProfileDialog::update_tagline(){
    Profile.newTagline(profile_list[3]->Content());
    update();
}

void ProfileDialog::generate_profile()
{
    int y = 30;
    for (int i = 0;i<4;++i){
        ClickableLabel * instance = new ClickableLabel(userID, this);
        instance->setFrameStyle(QFrame::NoFrame | QFrame::Plain);
        instance->setFont(font);
        //Here is how to change position:
        instance ->setStyleSheet("background-color:white;");
        instance ->setCursor(Qt::PointingHandCursor);
        instance ->setWordWrap(true);
        instance ->setGeometry(20,y,160,31);
        if (i >1){
            instance ->setGeometry(20,y,350,31);
        }
        if (i == 3){
            instance ->setGeometry(20,y,350,103);
            y = y + 122;
        } else {
            y = y + 70;
        }
        profile_list.append(instance);
    }
}

void ProfileDialog::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Select File", "", "Images(*.png *.jpg)" );
    qDebug()<<fileName;
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(this, "Error", "Open file failed");
        return;
    }
    Profile.newfileName(fileName);
    update();
    emit transmit(fileName);
}

