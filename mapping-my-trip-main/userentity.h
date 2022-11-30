#ifndef USERENTITY_H
#define USERENTITY_H

#include <QString>

class UserEntity
{
public:
    UserEntity();
    UserEntity(int id, const QString &username, const QString &password, long createTime, bool deleted);

    int getId() const;
    const QString &getUsername() const;
    const QString &getPassword() const;
    int getCreateTime() const;
    bool getDeleted() const;

private:
    int id;
    QString username;
    QString password;
    int createTime;
    bool deleted;
};

#endif // USERENTITY_H
