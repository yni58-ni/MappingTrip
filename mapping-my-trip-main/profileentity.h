#ifndef PROFILEENTITY_H
#define PROFILEENTITY_H

#include <QString>
#include <QBitArray>

/**
 * @brief It is the class for gathering every information of the a profile
 * @author Wenlong Zheng
 * @return
 */

class ProfileEntity
{
public:
    ProfileEntity();
    ProfileEntity(int userID, QString Name, int Gender, QString Tagline, QString fileName, QString Location, QString createTime);

    /**
     * @brief return userID
     * @author Wenlong Zheng
     * @return
     */
    int getuserID() const;
    /**
     * @brief return name
     * @author Wenlong Zheng
     * @return
     */
    QString getName() const;
    /**
     * @brief return location
     * @author Wenlong Zheng
     * @return
     */
    QString getLocation() const;
    /**
     * @brief return tagline
     * @author Wenlong Zheng
     * @return
     */
    QString getTagline() const;

    /**
     * @brief return gender
     * @author Wenlong Zheng
     * @return
     */
    int getGender() const;
    /**
     * @brief return fileName for the profile image
     * @author Wenlong Zheng
     * @return
     */
    const QString &getFileName() const;
    /**
     * @brief return create time
     * @author Wenlong Zheng
     * @return
     */
    QString getCreateTime() const;
    /**
     * @brief translate the gender from int to the string
     * @author Wenlong Zheng
     * @return
     */
    QString getRealGender() const;
    /**
     * @brief update name
     * @author Wenlong Zheng
     * @return
     */
    void newName(QString);
    /**
     * @brief update location
     * @author Wenlong Zheng
     * @return
     */
    void newLocation(QString);
    /**
     * @brief update tagline
     * @author Wenlong Zheng
     * @return
     */
    void newTagline(QString);
    /**
     * @brief update gender
     * @author Wenlong Zheng
     * @return
     */
    void newGender(int);
    /**
     * @brief update fileName
     * @author Wenlong Zheng
     * @return
     */
    void newfileName(QString);

private:
    int userID;
    QString Name;
    int Gender;
    QString Tagline;
    QString fileName;
    QString Location;
    QString createTime;
};

#endif // PROFILEENTITY_H
