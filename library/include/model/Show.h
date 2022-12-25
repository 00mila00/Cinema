//
// Created by student on 02.06.2020.
//

#ifndef CINEMA_SHOW_H
#define CINEMA_SHOW_H

#include <iostream>
#include <string>
#include <boost/date_time.hpp>
#include "typedef.h"
#include <memory>
class Movie;
class Room;
namespace pt = boost::posix_time;
typedef std::shared_ptr<Room> RoomPtr;
typedef std::shared_ptr<Movie> MoviePtr;
class Show {
public:
    Show(unsigned int show_id, MoviePtr movie, RoomPtr room, pt::ptime date);
    virtual ~Show();
    const unsigned int &get_show_id() const;
    const MoviePtr get_movie() const;
    const RoomPtr get_room() const;
    const pt::ptime &get_date() const;
    std::string get_show_info() const;

    void set_show_id(const unsigned int &number);
    void set_movie(MoviePtr name);
    void set_room(RoomPtr name);
    void set_date(const pt::ptime &time);
    void free_place(int id);
    bool take_place(unsigned int x, unsigned int y,int id);
    int is_taken(unsigned int x, unsigned int y);
    pt::ptime when_end(pt::ptime start, boost::posix_time::time_duration dura);
    const pt::ptime &get_end() const;
private:
    unsigned int show_id;
    pt::ptime date = pt::not_a_date_time;
    pt::ptime end_show = pt::not_a_date_time;
    RoomPtr room;
    MoviePtr movie;
    int * seats=new int[room->get_rows()*room->get_columns()];

};



#endif //CINEMA_SHOW_H



