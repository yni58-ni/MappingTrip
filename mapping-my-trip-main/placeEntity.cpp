#include <iostream>
#include <stdlib.h>
#include <placeEntity.h>



placeEntity::placeEntity(){

}

placeEntity::placeEntity(int id, const QString &name, const QString &information, bool visited){
    id(id);
    name(name);
    information(information);
    visited(visited);
}

int placeEntity::getID() const{
    return id;
}

const QString &placeEntity::getName() const
{
    return name;
}

const QString &placeEntity::getInfor() const
{
    return information;
}

bool &placeEntity::getVisited() const
{
    return visited;
}


