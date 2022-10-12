//
// Created by student on 13.06.2020.
//

#include <boost/test/unit_test.hpp>
#include "Repositories/ShowManager.h"
#include "model/Show.h"
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time.hpp>
#include <string>
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

using namespace boost::posix_time;
using namespace std;
BOOST_AUTO_TEST_SUITE(ShowManagerSuite)
    BOOST_AUTO_TEST_CASE(CreateShowTest){
        time_duration td(1,2,0);
        MoviePtr movie  (new Movie(10,"Shrek ",td));
        RoomPtr room (new Room(1,3,true,30,30));
        ShowPtr show( new Show(1,movie,room,pt::ptime(gr::date(2020,6,20),pt::hours(0)+pt::minutes(0))));
        time_duration td2(3,2,0);
        MoviePtr movie2 (new Movie(10,"Shrek 2",td2));
        RoomPtr room2 (new Room(3,3,true,30,30));
        ShowPtr show2 (new Show(2,movie,room,pt::ptime(gr::date(2020,6,25),pt::hours(16)+pt::minutes(0))));
        ShowManager man;
        man.create_show(show);
        man.create_show(show2);
        //BOOST_TEST(man.get_nr_of_shows()==2);
        ///////sprawdzamy czy mozemy utworzyc seans o pokrywajacej sie dacie do tej samej sali///////
        ShowPtr show3 (new Show(4,movie2,room,pt::ptime(gr::date(2020,6,25),pt::hours(16)+pt::minutes(30))));

        BOOST_REQUIRE_THROW(man.create_show(show3),logic_error);
        BOOST_TEST(man.get_nr_of_shows()==2);
        //////////////////sprawdzamy czy mozemy utworzyc seans o tym samym indeksie//////////////////
        ShowPtr show4 (new Show(2,movie2,room,pt::ptime(gr::date(2020,6,25),pt::hours(19)+pt::minutes(30))));
        BOOST_REQUIRE_THROW(man.create_show(show4),logic_error);
        BOOST_TEST(man.get_nr_of_shows()==2);

    }
    BOOST_AUTO_TEST_CASE(DeleteShowTest){
        time_duration td(1,2,0);
        MoviePtr movie  (new Movie(10,"Batman",td));
        RoomPtr room (new Room(1,3,true,30,30));
        ShowPtr show (new Show(2,movie,room,pt::ptime(gr::date(2020,8,20),pt::hours(0)+pt::minutes(0))));
        ShowPtr show2 (new Show(3,movie,room,pt::ptime(gr::date(2020,7,23),pt::hours(10)+pt::minutes(0))));
        ShowPtr show3 (new Show(4,movie,room,pt::ptime(gr::date(2020,7,25),pt::hours(11)+pt::minutes(0))));
        ShowManager man;
        man.create_show(show);
        man.create_show(show2);
        man.create_show(show3);
        BOOST_TEST(man.get_nr_of_shows()==3);
        man.delete_show(show);
        BOOST_TEST(man.get_nr_of_shows()==2);

    }

BOOST_AUTO_TEST_SUITE_END()