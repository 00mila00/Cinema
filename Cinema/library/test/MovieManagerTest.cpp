//
// Created by student on 13.06.2020.
//

#include <boost/test/unit_test.hpp>
#include "model/Movie.h"
#include "Repositories/MovieManager.h"
#include "model/typedef.h"
#include <string>
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

using namespace std;
using namespace boost::posix_time;

BOOST_AUTO_TEST_SUITE(MovieManagerSuite)
    BOOST_AUTO_TEST_CASE(CreateMovieTest){
        MovieManager man;
        time_duration t(3,0,0);
        time_duration t2(2,30,0);
        MoviePtr movie(new Movie(2,"Titanic",t));
        MoviePtr movie2(new Movie(4,"Krol Lew",t));
        man.create_movie(movie);
        man.create_movie(movie2);
        BOOST_TEST(man.get_nr_of_movies()==2);


    }
    BOOST_AUTO_TEST_CASE(DeleteMovieTest){
        MovieManager man;
        time_duration t(3,0,0);
        time_duration t2(2,30,0);
        MoviePtr movie(new Movie(2,"Titanic",t));
        MoviePtr movie2(new Movie(4,"Krol Lew",t));
        man.create_movie(movie);
        man.create_movie(movie2);
        man.delete_movie(movie);
        BOOST_TEST(man.get_nr_of_movies()==1);
    }

BOOST_AUTO_TEST_SUITE_END()