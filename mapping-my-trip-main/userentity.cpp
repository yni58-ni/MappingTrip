#include "userentity.h"

UserEntity::UserEntity()
{

}

UserEntity::UserEntity(int id, const QString &username, const QString &password, long createTime, bool deleted) : id(id),
    username(username),
    password(password),
    createTime(createTime),
    deleted(deleted)
{}

int UserEntity::getId() const
{
    return id;
}

const QString &UserEntity::getUsername() const
{
    return username;
}

const QString &UserEntity::getPassword() const
{
    return password;
}

int UserEntity::getCreateTime() const
{
    return createTime;
}

bool UserEntity::getDeleted() const
{
    return deleted;
}
