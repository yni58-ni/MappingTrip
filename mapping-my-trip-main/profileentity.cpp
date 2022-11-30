#include "profileentity.h"

ProfileEntity::ProfileEntity()
{

}

ProfileEntity::ProfileEntity(int userID, QString Name, int Gender, QString Tagline, QString fileName, QString Location, int createTime) :userID(userID),
    Name(Name),
    Gender(Gender),
    Tagline(Tagline),
    fileName(fileName),
    Location(Location),
    createTime(createTime)
{}

int ProfileEntity::getuserID() const
{
    return userID;
}

QString ProfileEntity::getName() const
{
    return Name;
}


QString ProfileEntity::getLocation() const
{
    return Location;
}

QString ProfileEntity::getTagline() const
{
    return Tagline;
}

int ProfileEntity::getGender() const
{
    return Gender;
}

const QString &ProfileEntity::getFileName() const
{
    return fileName;
}

int ProfileEntity::getCreateTime() const
{
    return createTime;
}

void ProfileEntity::newGender(int gender)
{
    Gender = gender;
}

void ProfileEntity::newLocation (QString location)
{
    Location = location;
}

void ProfileEntity::newName (QString name)
{
    Name = name;
}

void ProfileEntity::newTagline(QString tagline)
{
    Tagline = tagline;
}

void ProfileEntity::newfileName(QString filename)
{
    fileName = filename;
}
