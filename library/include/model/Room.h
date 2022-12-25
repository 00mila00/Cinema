//
// Created by student on 02.06.2020.
//

#ifndef CINEMA_ROOM_H
#define CINEMA_ROOM_H
#include <iostream>


class Room {
public:
    Room(const unsigned int &room_number,const unsigned int &room_type,const bool &vip,const unsigned int &rows,const unsigned int &columns);
    virtual ~Room();
    std::string get_room_information() const;
    std::string vip_info()const;
    const unsigned int &get_room_nr() const;
    const unsigned int &get_room_type() const;
    const bool &is_vip() const;
    const int &get_rows() const;
    const int &get_columns() const;
    void set_room_type(const unsigned int &dimension);
    void set_rows(const unsigned int &quant);
    void set_columns(const unsigned int &quant);

    void set_vip(bool vip);


private:
   unsigned int room_number{};
   unsigned int room_type{};
   bool vip{false};
   int rows{};
   int columns{};

};


#endif //CINEMA_ROOM_H
