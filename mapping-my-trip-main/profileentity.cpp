#include "profileentity.h"

/**
 * @brief Profile dialog is the ui for users to view their profile and edit it
 * @author Wenlong Zheng
 * @return
 */

ProfileEntity::ProfileEntity()
{

}

ProfileEntity::ProfileEntity(int userID, QString Name, int Gender, QString Tagline, QString fileName, QString Location, QString createTime) :userID(userID),
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

QString ProfileEntity::getCreateTime() const
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

QString ProfileEntity::getRealGender() const
{
    int g = Gender;
    if (g == 0){
        return "Unkown";
    } else if (g == 1){
        return "Male";
    } else if (g == 2){
        return "Female";
    } else {
        return "Other";
    }
}
