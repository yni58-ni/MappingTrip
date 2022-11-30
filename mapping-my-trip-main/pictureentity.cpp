#include "pictureentity.h"

PictureEntity::PictureEntity()
{

}

int PictureEntity::getId() const
{
    return id;
}

int PictureEntity::getPointId() const
{
    return pointId;
}

const QString &PictureEntity::getFileName() const
{
    return fileName;
}

const QByteArray &PictureEntity::getFileData() const
{
    return fileData;
}

int PictureEntity::getCreateTime() const
{
    return createTime;
}

bool PictureEntity::getDeleted() const
{
    return deleted;
}

PictureEntity::PictureEntity(int id, int pointId, const QString &fileName, const QByteArray &fileData, int createTime, bool deleted) : id(id),
    pointId(pointId),
    fileName(fileName),
    fileData(fileData),
    createTime(createTime),
    deleted(deleted)
{}
