#ifndef PICTUREENTITY_H
#define PICTUREENTITY_H

#include <QString>
#include <QBitArray>

class PictureEntity
{
public:
    PictureEntity();
    PictureEntity(int id, int pointId, const QString &fileName, const QByteArray &fileData, int createTime, bool deleted);

    int getId() const;
    int getPointId() const;
    const QString &getFileName() const;
    const QByteArray &getFileData() const;
    int getCreateTime() const;
    bool getDeleted() const;

private:
    int id;
    /**
     * reference to PointEntity id
     * @brief pointId
     */
    int pointId;
    /**
     * picture file name
     * @brief fileName
     */
    QString fileName;
    /**
     * picture row data
     * @brief fileData
     */
    QByteArray fileData;
    int createTime;
    bool deleted;
};

#endif // PICTUREENTITY_H
