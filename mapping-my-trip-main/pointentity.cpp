#include "pointentity.h"
#include <QString>

PointEntity::PointEntity()
{

}

int PointEntity::getId() const
{
    return id;
}

int PointEntity::getUserId() const
{
    return userId;
}

double PointEntity::getLatitude() const
{
    return latitude;
}


double PointEntity::getLongitude() const
{
    return longitude;
}

int PointEntity::getCreateTime() const
{
    return createTime;
}

bool PointEntity::getDeleted() const
{
    return deleted;
}

QString PointEntity::getName() const
{
    return name;
}

PointEntity::PointEntity(int id, int userId, double latitude, double longitude,  long createTime, bool deleted, QString name) : id(id),
    userId(userId),
    latitude(latitude),
    longitude(longitude),
    createTime(createTime),
    deleted(deleted),
    name(name)
{}
