//
// Created by student on 13.06.2020.
//

#include <boost/test/unit_test.hpp>
#include "model/Movie.h"
#include "model/Room.h"
#include "model/Show.h"
#include "Repositories/ShowRepository.h"

using namespace std;
using namespace boost::posix_time;
BOOST_AUTO_TEST_SUITE(ShowRepoSuite)

    BOOST_AUTO_TEST_CASE(AddShowTest){
        time_duration td(2,3,0);
        MoviePtr movie (new Movie(1,"Johny Deep i pogromca smoków",td));
        RoomPtr room (new Room(2,3,true,30,30));
        ShowPtr show (new Show (1,movie, room, pt::ptime(gr::date(2020,8,20),pt::hours(8)+pt::minutes(0))));
        ShowPtr show2 (new Show (2,movie, room, pt::ptime(gr::date(2020,9,20),pt::hours(16)+pt::minutes(0))));
        ShowPtr show3 (new Show (3,movie, room, pt::ptime(gr::date(2020,10,20),pt::hours(20)+pt::minutes(0))));
        ShowRepository rep;
        BOOST_TEST(rep.add(show));
        BOOST_TEST(rep.add(show2));
        BOOST_TEST(rep.add(show3));
        MoviePtr movie2 (new Movie(1,"Alicja w krainie czarow",td));
        ShowPtr show4 (new Show (3,movie2, room, pt::ptime(gr::date(2020,10,20),pt::hours(21)+pt::minutes(0))));
        BOOST_REQUIRE_THROW(rep.add(show4),logic_error);
        BOOST_REQUIRE_THROW(rep.add(show),logic_error);

    }
    BOOST_AUTO_TEST_CASE(RemoveShowTest){
        time_duration td(2,3,0);
        MoviePtr movie (new Movie(1,"Johny Deep i pogromca smoków",td));
        RoomPtr room (new Room(2,3,true,30,30));
        ShowPtr show (new Show (1,movie, room, pt::ptime(gr::date(2020,8,20),pt::hours(8)+pt::minutes(0))));
        ShowPtr show2 (new Show (2,movie, room, pt::ptime(gr::date(2020,9,20),pt::hours(16)+pt::minutes(0))));
        ShowPtr show3 (new Show (3,movie, room, pt::ptime(gr::date(2020,10,20),pt::hours(20)+pt::minutes(0))));
        ShowRepository rep;
        rep.add(show);
        rep.add(show2);
        BOOST_TEST(rep.remove(show));
        BOOST_TEST(rep.remove(show2));
        BOOST_REQUIRE_THROW(rep.remove(show3),logic_error);
    }

    BOOST_AUTO_TEST_CASE(SizeShowTest){

        time_duration td(2,3,0);
        MoviePtr movie (new Movie(1,"Johny Deep i pogromca smoków",td));
        RoomPtr room (new Room(2,3,true,30,30));
        ShowPtr show (new Show (1,movie, room, pt::ptime(gr::date(2020,8,20),pt::hours(8)+pt::minutes(0))));
        ShowPtr show2 (new Show (2,movie, room, pt::ptime(gr::date(2020,9,20),pt::hours(16)+pt::minutes(0))));
        ShowPtr show3 (new Show (3,movie, room, pt::ptime(gr::date(2020,10,20),pt::hours(20)+pt::minutes(0))));
        ShowRepository rep;
        rep.add(show);
        rep.add(show2);
        rep.add(show3);
        BOOST_TEST(rep.size()==3);

    }
    BOOST_AUTO_TEST_CASE(SearchShowTest){
        time_duration td(2,3,0);
        MoviePtr movie (new Movie(1,"Johny Deep i pogromca smoków",td));
        RoomPtr room (new Room(2,3,true,30,30));
        ShowPtr show (new Show (1,movie, room, pt::ptime(gr::date(2020,8,20),pt::hours(8)+pt::minutes(0))));
        ShowPtr show2 (new Show (2,movie, room, pt::ptime(gr::date(2020,9,20),pt::hours(16)+pt::minutes(0))));
        ShowPtr show3 (new Show (3,movie, room, pt::ptime(gr::date(2020,10,20),pt::hours(20)+pt::minutes(0))));
        ShowRepository rep;
        rep.add(show);
        rep.add(show2);

        BOOST_TEST(rep.search(1)==show);
        BOOST_TEST(rep.search(2)==show2);
        BOOST_REQUIRE_THROW(rep.search(3),logic_error);


    }
BOOST_AUTO_TEST_SUITE_END()