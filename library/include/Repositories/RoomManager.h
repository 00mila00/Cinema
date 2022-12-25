//
// Created by student on 12.06.2020.
//

#ifndef LIBRARY_ROOMMANAGER_H
#define LIBRARY_ROOMMANAGER_H


#include <string>
#include <vector>
#include <memory>
#include "Repository.h"
#include "Repositories/typedefrepo.h"
#include "Repositories/typedefrepo.h"
class RoomManager {
    RoomRepoPtr current_room;
public:
    RoomManager();
    virtual ~RoomManager();
    void create_room(const RoomPtr &r);
    void delete_room(const RoomPtr &r);
    unsigned int get_nr_of_rooms() const;
    RoomPtr find_room(unsigned int);


};

#endif //LIBRARY_ROOMMANAGER_H
