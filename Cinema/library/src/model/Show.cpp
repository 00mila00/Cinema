//
// Created by student on 02.06.2020.
//

#include "model/Show.h"
#include <iostream>
#include "model/Room.h"
#include "model/Movie.h"
#include <boost/date_time.hpp>
#include <sstream>
namespace pt = boost::posix_time;

using namespace std;
Show::Show(unsigned int show_id, MoviePtr movie, RoomPtr room, pt::ptime date): show_id(show_id), movie(movie), room(room), date(date){
    for(int i=0;i<(room->get_rows());i++){
        for(int j=0;j<(room->get_columns());j++)
        {
            seats[i*j]=0;
        }
    }
    end_show=when_end(date,movie->get_duration());
}

Show::~Show() = default;

const unsigned int &Show::get_show_id() const {
    return show_id;
}

const MoviePtr Show::get_movie() const {
    return movie;
}

const RoomPtr Show::get_room() const {
    return room;
}

const pt::ptime &Show::get_date() const {
    return date;
}

std::string Show::get_show_info() const {
    ostringstream sout;
    sout<<"show ID: "<<get_show_id()<<", "<<get_movie()->get_movie_information()<<", "<<get_room()->get_room_information()<<", Date: "<<get_date()<<endl;
    return sout.str();
}
void Show::set_show_id(const unsigned int &number) {
    if(number==0)
        __throw_logic_error("ID nie moze byc rowne zero");
    show_id=number;
}

void Show::set_movie(MoviePtr name) {
    if(name==nullptr)
        __throw_logic_error("Film nie moze byc nullptr");
    movie=name;
}

void Show::set_room(RoomPtr name) {
    if(name==nullptr)
        __throw_logic_error("Pokoj nie moze byc nullptr");
    room=name;
}

void Show::set_date(const pt::ptime &time) {
    if(time==pt::not_a_date_time || time<pt::second_clock::local_time())
        __throw_logic_error("Podano nie poprawny wymiar daty");
    date=time;

}

pt::ptime Show::when_end(pt::ptime start, boost::posix_time::time_duration dura) {

    end_show = start + dura;
    return end_show;
}

int Show::is_taken(unsigned int x, unsigned int y) {
    return seats[x*y];
}

const pt::ptime &Show::get_end() const {
    return end_show;
}

bool Show::take_place(unsigned int x, unsigned int y, int id) {
    if(!is_taken(x,y))
    {
        seats[x*y]=id;
        return true;
    }
    return false;
}

void Show::free_place(int id) {
    for(int i=0;i<(room->get_rows());i++)
    {
        for(int j=0;j<(room->get_columns());j++)
        {
            if(seats[i*j]==id);
                seats[i*j]=0;
        }
    }
}



