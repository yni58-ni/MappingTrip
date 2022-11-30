#ifndef PLACEENTITY_H
#define PLACEENTITY_H

#include <QDialog>
#include <QVariant>
#include <QString>
#include "dbhelper.h"


class placeEntity{
public:
    placeEntity();
    placeEntity(int id, const QString &name, const QString &information, bool visited);

    int getPid() const;
    const QString &getPname() const;
    const QString &getInfor() const;
    bool getVisited() const;

private:
    int id;
    QString name;
    QString information;
    bool visited;
};

#endif
