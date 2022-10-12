//
// Created by student on 02.06.2020.
//

#include <boost/test/unit_test.hpp>
#include "model/Show.h"
#include "model/Room.h"
#include "model/Movie.h"
#include "model/typedef.h"
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time.hpp>
#include <string>
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

using namespace std;
using namespace boost::posix_time;

BOOST_AUTO_TEST_SUITE(ShowSuite)

    BOOST_AUTO_TEST_CASE(ConstructorTest){
        time_duration td(1,2,0);
        MoviePtr movie (new Movie(10,"Madagaskar",td));
        RoomPtr room( new Room(1,3,true,30,30));
        ShowPtr show (new Show(1, movie , room,pt::ptime(gr::date(2021,6,20),pt::hours(0)+pt::minutes(0))));

        BOOST_TEST(show->get_show_id()==1);
        BOOST_TEST(show->get_room()==room);
        BOOST_TEST(show->get_movie()==movie);
        BOOST_TEST(show->get_date()==pt::ptime(gr::date(2021,6,20),pt::hours(0)+pt::minutes(0)));
        show->set_date(pt::ptime(gr::date(2020,7,20),pt::hours(0)+pt::minutes(0)));
        BOOST_TEST(show->get_date()==pt::ptime(gr::date(2020,7,20),pt::hours(0)+pt::minutes(0)));
        BOOST_REQUIRE_THROW(show->set_date(pt::ptime(gr::date(2020,4,20),pt::hours(0)+pt::minutes(0))),logic_error);

        RoomPtr room2 (new Room(3,5,true,30,30));
        show->set_room(room2);
        BOOST_TEST(show->get_room()==room2);
        BOOST_REQUIRE_THROW(show->set_room(nullptr),logic_error);
        MoviePtr movie2  (new Movie(11,"Vaiana",td));
        show->set_movie(movie2);
        BOOST_TEST(show->get_movie()==movie2);
        BOOST_REQUIRE_THROW(show->set_movie(nullptr),logic_error);

    }

    BOOST_AUTO_TEST_CASE(TakePlaceTest){

        time_duration td(1,2,0);
        MoviePtr movie (new Movie(10,"Pingwiny z Mandagaskaru",td));
        RoomPtr room( new Room(1,3,true,30,30));
        ShowPtr show (new Show(1, movie , room,pt::ptime(gr::date(2020,6,20),pt::hours(0)+pt::minutes(0))));
        BOOST_TEST(show->take_place(3,4,2));
        BOOST_TEST(show->take_place(4,5,3));
        BOOST_TEST(show->take_place(4,5,4)==false);
        BOOST_TEST(show->take_place(10,90,5)==false);


    }
    BOOST_AUTO_TEST_CASE(WhenEndTest){
        time_duration td(1,2,0);
        MoviePtr movie  (new Movie(10,"Auta",td));
        RoomPtr room (new Room(1,3,true,30,30));
        ShowPtr show (new Show(1,movie,room,pt::ptime(gr::date(2020,6,20),pt::hours(0)+pt::minutes(0))));

        BOOST_TEST(show->when_end(show->get_date(), movie->get_duration())==pt::ptime(gr::date(2020,6,20),pt::hours(1)+pt::minutes(2)));

    }



BOOST_AUTO_TEST_SUITE_END()