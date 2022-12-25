//
// Created by student on 02.06.2020.
//

#include <model/Movie.h>
#include <iostream>
#include <string>
#include <utility>
#include <sstream>
#include <string>
#include <boost/date_time/special_defs.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time.hpp>

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;
using namespace std;
using namespace boost::posix_time;
Movie::Movie( unsigned int movie_id, string title, pt::time_duration &duration) : movie_id(movie_id) {
set_duration(duration);
set_title(title);
}
Movie::~Movie() {
}

const string &Movie::get_title() const {
    return title;
}
const time_duration &Movie::get_duration() const {
    return duration;
}

void Movie::set_title(const std::string &name) {
    if(name.empty())
        __throw_logic_error("Tytul nie moze byc pusty");

    title=name;
}

void Movie::set_duration(boost::posix_time::time_duration &number) {
    time_duration td (0,0,0);
    if(number == td)
      __throw_logic_error("Czas nie moze byc zerowy");
        //return;
    duration=number;
}

    string Movie::get_movie_information() const {
    ostringstream sout;
    sout<<"Movie "<<get_movie_Id()<<". "<<get_title()<<" duration "<<to_simple_string(get_duration());
    return sout.str();
}

unsigned int Movie::get_movie_Id() const {
    return movie_id;
}









