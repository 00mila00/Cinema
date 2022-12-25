//
// Created by student on 12.06.2020.
//

#ifndef LIBRARY_ROOMREPOSITORY_H
#define LIBRARY_ROOMREPOSITORY_H
#include <string>
#include <vector>
#include <memory>
#include "Repository.h"
#include "model/typedef.h"
#include "model/Room.h"
class Room;
class RoomManager;

class RoomRepository : Repository <Room> {

std::vector<RoomPtr> rooms;
public:
    bool add(const RoomPtr& room) override ;
    bool remove(const RoomPtr& room) override ;
    std::string report() const override;
    unsigned int size() override;
    RoomPtr search(unsigned int id) override;



};


#endif //LIBRARY_ROOMREPOSITORY_H
