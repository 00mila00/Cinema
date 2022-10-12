//
// Created by student on 02.06.2020.
//

#include "model/Room.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

Room::Room(const unsigned int &room_number, const unsigned int &room_typein,const bool &vip, const unsigned int &rows, const unsigned int &columns):room_number(room_number), vip(vip) {
    if(room_typein<2 || room_typein>7)
    {
        room_type=2;
    }
    else room_type=room_typein;
    set_rows(rows);
    set_columns(columns);
}



Room::~Room() {

}
const unsigned int &Room::get_room_nr() const {
    return room_number;
}

const unsigned int &Room::get_room_type() const {
    return room_type;
}
const bool &Room::is_vip() const {
    return vip;
}
const int &Room::get_rows() const {
    return rows;
}
const int &Room::get_columns() const {
    return columns;
}

std::string Room::get_room_information() const {
    ostringstream sout;
    sout<<"Room number: "<<get_room_nr()<<", room type "<<get_room_type()<<",  "<<vip_info()<<" rows: "<<get_rows()<<" columns: "<<get_columns();
    return sout.str();
}
void Room::set_vip(bool vi) {
    Room::vip = vi;
}

void Room::set_room_type(const unsigned int &dimension) {
    if(dimension<2 || dimension>7)
        __throw_logic_error("Wymiar musi byc z przedzialu <2,7>");
    room_type=dimension;

}

void Room::set_rows(const unsigned int &quant){
    if(quant==0)
        __throw_logic_error("Nie moze byc zerowej liczby rzedow");
    rows=quant;
}

void Room::set_columns(const unsigned int &quant) {
    if(quant==0)
        __throw_logic_error("Nie moze byc zerowej liczby kolumn");
    columns=quant;

}

std::string Room::vip_info() const{
    ostringstream sout;
    if(is_vip())
         sout<<"Typ: VIP   ";
    else sout<<"Typ: Normal";
    return sout.str();
}










