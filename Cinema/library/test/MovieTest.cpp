//
// Created by student on 13.06.2020.
//
#include <boost/test/unit_test.hpp>
#include "model/Movie.h"
#include "model/typedef.h"
#include <string>
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

using namespace std;
using namespace boost::posix_time;

BOOST_AUTO_TEST_SUITE(MovieSuite)
    BOOST_AUTO_TEST_CASE(ConstructorTest){
    time_duration td(1,0,0);
    MoviePtr movie (new Movie(1,"Johny Deep i pogromca smoków",td));
    BOOST_TEST(movie->get_duration()==td);
    BOOST_TEST(movie->get_movie_Id()==1);
    BOOST_TEST(movie->get_title()=="Johny Deep i pogromca smoków");
    time_duration td2(1,2,0);
    movie->set_duration(td2);
    BOOST_TEST(movie->get_duration()==td2);
    time_duration td3(0,0,0);
    BOOST_REQUIRE_THROW(movie->set_duration(td3),logic_error);
    BOOST_TEST(movie->get_duration()==td2);
    BOOST_REQUIRE_THROW(movie->set_title(""),logic_error);
    BOOST_TEST(movie->get_title()=="Johny Deep i pogromca smoków");
    movie->set_title("Smerfy");
    BOOST_TEST(movie->get_title()=="Smerfy");

    }


BOOST_AUTO_TEST_SUITE_END()