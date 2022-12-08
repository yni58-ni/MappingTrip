#ifndef MAPDIALOG_H
#define MAPDIALOG_H

#include <QDialog>
#include <QVariant>
#include "dbhelper.h"

#include <QQuickItem>
#include <QMenu>
#include <QAction>
#include <QPixmap>
#include <QMessageBox>
#include <QString>

#include "pointentity.h"
#include "picturedialog.h"
#include "profileentity.h"
#include "profiledialog.h"
#include "profileclicked.h"
#include "pathdialog.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iterator>

namespace Ui {
class MapDialog;
}

class MapDialog : public QDialog
{
    Q_OBJECT
    Q_PROPERTY(std::string p_name READ p_name  NOTIFY p_nameChanged)

public:
    MapDialog();
    explicit MapDialog(int userId, QWidget *parent = nullptr);
    ~MapDialog();

    /**
     * refresh all mark points on map
     * @brief updatePointList
     */
    void updatePointList();
    std::string p_name();

signals:
    /**
     * notify map to add new mark point.
     * @brief doAddPoint
     * @param id
     * @param latitude
     * @param longitude
     */
    void doAddPoint(QVariant id, QVariant latitude, QVariant longitude);
    void clicked();
    void p_nameChanged();

private slots:
    /**
     * invoked by map when add point.
     * @brief addPoint
     * @param latitude
     * @param longitude
     */
    void addPoint(QVariant latitude, QVariant longitude, QVariant name);
    /**
     * invoked by map when mark point clicked.
     * @brief pointClicked
     * @param pointId
     */
    void pointClicked(QVariant pointId);
    void addLocationInformationList();
    void mousePressEvent(QMouseEvent* event);
    void on_GetSetLocation_clicked();
    void on_searchBotton_clicked();
    void on_pathButton_clicked();
    void update_profileImage(QString txt);

private:
    Ui::MapDialog *ui;
    DBHelper helper;
    /**
     * current userId
     * @brief userId
     */
    int userId;
    ProfileClicked *profile;
    std:: string P_name;
};

#endif // MAPDIALOG_H
