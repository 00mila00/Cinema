//
// Created by student on 02.06.2020.
//

#ifndef CINEMA_MOVIE_H
#define CINEMA_MOVIE_H
#include <string>
#include <iostream>
#include <boost/date_time/posix_time/posix_time_config.hpp>
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;
class Movie {

public:
    Movie(unsigned int movie_id, std::string title, pt::time_duration &duration);
    virtual ~Movie();
    const std::string &get_title() const;
    const pt::time_duration &get_duration() const;
    void set_title(const std::string &name);
    void set_duration(boost::posix_time::time_duration &number);
    std::string get_movie_information() const;
    unsigned int get_movie_Id() const;

private:
    pt::time_duration(duration) ;
    std::string title;
    unsigned int movie_id;

};


#endif //CINEMA_MOVIE_H
