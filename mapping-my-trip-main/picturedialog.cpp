#include "picturedialog.h"
#include "ui_picturedialog.h"
#include "pointentity.h"

#include <QFileDialog>
#include <QDebug>
#include <QFile>
#include <QMessageBox>
#include <QPixmap>
#include <QStringListModel>
#include <iostream>



PictureDialog::PictureDialog(int pointId, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PictureDialog),
    pointId(pointId)
{
    ui->setupUi(this);
    label = new QLabel(this);




    QString name = helper.getName(pointId);
   ui->label_location_name->setText(name);


    ui->scrollArea->setWidget(label);

    updateList();

}

PictureDialog::~PictureDialog()
{
    delete ui;
}

void PictureDialog::updateList()
{
    list = helper.getPictureList(pointId);

    QStringList nameList;
    for(PictureEntity entity : list) {
        nameList.append(entity.getFileName());
    }
    QStringListModel *listModel = new QStringListModel(nameList);
    ui->listView->setModel(listModel);
    label->clear();
}

void PictureDialog::on_addButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Select File", "", "Images(*.png, *.jpg)");
    qDebug()<<fileName;
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(this, "Error", "Open file failed");
        return;
    }
    helper.addPicture(pointId, file.fileName(), file.readAll());
    updateList();
}


void PictureDialog::on_deleteButton_clicked()
{
    if(list.size()>0) {
        PictureEntity entity = list.at(ui->listView->currentIndex().row());
        qDebug()<<"delete picture"<<helper.deletePicture(entity.getId());
        updateList();
    }
}


void PictureDialog::on_listView_clicked(const QModelIndex &index)
{
    PictureEntity entity = list.at(index.row());
    QPixmap pixmap;
    pixmap.loadFromData(entity.getFileData());
    label->setPixmap(pixmap.scaled(300,300,Qt::KeepAspectRatio));
    label->resize(pixmap.size());
    //label -> setCursor(Qt::PointingHandCursor);

//    ui->scrollArea->widget()->adjustSize();
}


