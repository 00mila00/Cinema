//
// Created by student on 12.06.2020.
//

#include "Repositories/RoomRepository.h"
#include <sstream>
#include <string>
#include <iostream>
using namespace std;
bool RoomRepository::add(const RoomPtr &room) {
if (room==nullptr)
    __throw_logic_error("Pokoj nie moze byc nullptr");
for(int i=0; i<rooms.size(); i++) {
    if (room == rooms[i] )
        __throw_logic_error("Ten pokoj juz zostal dodany");
    else if(room->get_room_nr()==rooms[i]->get_room_nr())
        __throw_logic_error("Pokoj o tym ID juz istnieje");

}
rooms.push_back(room);
return true;
}
bool RoomRepository::remove(const RoomPtr &room) {
for(int i= 0; i<rooms.size(); i++){
    if(rooms[i]==room)
        rooms[i]=nullptr;
        rooms.erase(rooms.begin()+i);
        return true;
}
__throw_logic_error("Nie mozna usunac pokoju, ktory nie istnieje");
}
std::string RoomRepository::report() const {
    ostringstream sout;
    for(int i=0;i<rooms.size(); i++)
        sout<<rooms[i]->get_room_information();
    return sout.str();
}

unsigned int RoomRepository::size() {
    return rooms.size();
}

RoomPtr RoomRepository::search(unsigned int id) {
    for(int i = 0; i<size(); i++){
        if(id == rooms[i]->get_room_nr())
            return rooms[i];
    }
    __throw_logic_error("Nie ma pokoju o takim id");
}



