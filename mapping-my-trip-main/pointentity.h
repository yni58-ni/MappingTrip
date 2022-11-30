#ifndef POINTENTITY_H
#define POINTENTITY_H
#include <QString>

class PointEntity
{
public:
    PointEntity();
    PointEntity(int id, int userId, double latitude, double longitude,  long createTime, bool deleted, QString name);

    int getId() const;
    int getUserId() const;
    double getLatitude() const;
    double getLongitude() const;
    int getCreateTime() const;
    bool getDeleted() const;
    QString getName() const;

private:
    int id;
    /**
     * reference to UserEntity id
     * @brief userId
     */
    int userId;
    double latitude;
    double longitude;
    long createTime;
    bool deleted;
    QString name;
};

#endif // POINTENTITY_H
