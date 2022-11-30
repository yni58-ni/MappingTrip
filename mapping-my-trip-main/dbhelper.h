#ifndef DBHELPER_H
#define DBHELPER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QFileInfo>
#include <QList>
#include "pointentity.h"
#include "pictureentity.h"
#include <string>
#include <QString>
#include "profileentity.h"

class DBHelper : public QObject
{
    Q_OBJECT
public:
    explicit DBHelper(QObject *parent = nullptr);

    /**
     * open database connection
     * @brief open
     * @return
     */
    bool open();


    /**
     * close database connection
     * @brief close
     */
    void close();


    /**
     * register new user
     * @brief addUser
     * @param username
     * @param password
     * @return
     */
    int addUser(QString username, QString password);


    /**
     * find user and return id
     *
     * @brief checkUser
     * @param username
     * @param password
     * @return userId
     */
    int checkUser(QString username, QString password);


    /**
     * add new mark point
     * @brief addPoint
     * @param userId
     * @param latitude
     * @param longitude
     * @return
     */
    int addPoint(int userId, double latitude, double longitude, QString name);


    /**
     * get point list by userId
     * @brief getPointList
     * @param userId
     * @return
     */

    QString getName(int pointId);


    QList<PointEntity> getPointList(int userId);


    /**
     * add picture data by pointId
     * @brief addPicture
     * @param pointId
     * @param fileName
     * @param fileData
     * @return
     */
    int addPicture(int pointId, QString fileName, QByteArray fileData);


    /**
     * get picture list by pointId
     * @brief getPictureList
     * @param pointId
     * @return
     */
    QList<PictureEntity> getPictureList(int pointId);


    /**
     * Add user post by pointId
     * @brief addPost
     * @param pointId
     * @param userId
     * @param postText
     * @return
     */
    int addPost(int userId,int pointId, QString postText);


    /**
     * logical delete picture by id
     * @brief deletePicture
     * @param id
     * @return
     */
    bool deletePicture(int id);

    int addProfile(int userID, QString name, int Gender, QString Tagline, QString fileName, QString Location);

    int checkProfile(int userID);

    int updateProfile(int userID, QString name, int Gender, QString Tagline, QString fileName, QString Location);

    ProfileEntity getProfile(int userID);
signals:

private:
    /**
     * if database not exist, create new database and init tables.
     * @brief initData
     */
    void initData();

    QSqlDatabase db;
    /**
     * database filename, default is 'data.db'
     * @brief fileName
     */
    QString fileName;

};

#endif // DBHELPER_H
