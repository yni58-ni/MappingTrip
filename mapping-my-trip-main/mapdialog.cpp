#include "mapdialog.h"
#include "ui_mapdialog.h"
#include <QString>


using namespace std;

/**
 * @brief A window to display the map
 * @author Nicole Ni  Ruiqing Sun
 * @param userId
 * @param parent
 */

MapDialog::MapDialog(){

}

MapDialog::MapDialog( int userId, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MapDialog),
    userId(userId)
{
    ui->setupUi(this);
    QPixmap pix(":/information.png");
    ui->label_info->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));

    helper.open();

    QQuickItem *root = ui->quickWidget->rootObject();

    connect(root, SIGNAL(onAddPoint(QVariant, QVariant,QVariant)), this, SLOT(addPoint(QVariant, QVariant,QVariant)));
    connect(root, SIGNAL(onPointClicked(QVariant)), this, SLOT(pointClicked(QVariant)));
    connect(this, SIGNAL(doAddPoint(QVariant, QVariant, QVariant)), root, SLOT(doAddPoint(QVariant, QVariant, QVariant)));

    ProfileEntity p = helper.getProfile(userId);
    profile = new ProfileClicked(userId, this);
    profile->setFrameStyle(QFrame::NoFrame | QFrame::Plain);
    profile->setText("first line\nsecond line");
    profile->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    //Here is how to change position:
    QPixmap image(p.getFileName());
    profile ->setPixmap(image);
    profile ->setCursor(Qt::PointingHandCursor);
    profile ->setScaledContents(true);
    profile ->setGeometry(920,40,61,61);

    connect(profile,&ProfileClicked::transmit,this,&MapDialog::update_profileImage);


    updatePointList();

    P_name = "Toronto";


}


MapDialog::~MapDialog()
{
    delete ui;
    helper.open();
}

/**
 * @brief add marks to the list
 */
void MapDialog::updatePointList()
{
    QList<PointEntity> list = helper.getPointList(userId);
    for(PointEntity entity : list) {
        emit doAddPoint(entity.getId(), entity.getLatitude(), entity.getLongitude());
    }
}

/**
 * @brief add marks on the map
 * @param latitude
 * @param longitude
 * @param name
 */

void MapDialog::addPoint(QVariant latitude, QVariant longitude, QVariant name)
{

    int pointId = helper.addPoint(userId, latitude.toDouble(), longitude.toDouble(), name.toString());
    PictureDialog dialog(pointId);
    dialog.setModal(true);
    //dialog.exec();

    emit doAddPoint(pointId, latitude, longitude);


}


/**
 * @brief event to click on the map
 * @param pointId
 */
void MapDialog::pointClicked(QVariant pointId)
{
    PictureDialog dialog(pointId.toInt());
    dialog.setModal(true);
    dialog.exec();
}

/**
 * @brief update the list contains location information
 */

void MapDialog::addLocationInformationList(){
    QFile readFile(":/LocationInformationList.txt");
    if (!readFile.open(QIODevice::ReadOnly)){
        QMessageBox::information (0, "error", readFile.errorString());
    }

    QTextStream in(&readFile);

    while (!in.atEnd()){
        QString line = in.readLine();

        QStringList locationElement = line.split(u',');
        QString name=locationElement[0];
        QString lat=locationElement[1];
        QString longt=locationElement[2];
        addPoint(lat,longt,name);
    }
    readFile.close();
}

void MapDialog::mousePressEvent(QMouseEvent *event)
{
    emit clicked();
}

/**
 * @brief search the input place on the map once search botton is clicked
 */

void MapDialog::on_searchBotton_clicked() // search place on a map
{
    P_name = ui ->searchBox ->text().toStdString();
    cout<< "curren place name is :" << P_name;
    emit p_nameChanged();

}

string MapDialog::p_name(){
    return P_name;
}


void MapDialog::on_GetSetLocation_clicked()
{
    addLocationInformationList();
}

void MapDialog::update_profileImage(QString txt){
    QPixmap pixmap(txt);
    profile ->setPixmap(pixmap);
}

