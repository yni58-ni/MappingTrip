#include "map.h"
#include "ui_map.h"

#include <QQmlContext>

map::map(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::map)
{
    ui->setupUi(this);
    ui->quickWidget->rootContext()->setContextProperty("pinModel",&modfl);
    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/map.qml")));          //Show map in London ON
    ui->quickWidget->show();
}

map::~map()
{
    delete ui;
}
