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
#include "clickablelabel.h"
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

public:
    explicit MapDialog(int userId, QWidget *parent = nullptr);
    ~MapDialog();

    /**
     * refresh all mark points on map
     * @brief updatePointList
     */
    void updatePointList();

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

    void on_searchBotton_clicked();

private:
    Ui::MapDialog *ui;
    DBHelper helper;
    /**
     * current userId
     * @brief userId
     */
    int userId;
};

#endif // MAPDIALOG_H
