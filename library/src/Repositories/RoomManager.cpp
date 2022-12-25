//
// Created by student on 12.06.2020.
//

#include "Repositories/RoomManager.h"

RoomManager::RoomManager():current_room(new RoomRepository) {}

RoomManager::~RoomManager() {}

void RoomManager::delete_room(const RoomPtr &r) {
current_room->remove(r);
r->Room::~Room();
}

void RoomManager::create_room(const RoomPtr &r) {

    current_room->add(r);

}

unsigned int RoomManager::get_nr_of_rooms() const {
    return current_room->size();
}

RoomPtr RoomManager::find_room(unsigned int id) {
    return current_room->search(id);
}


