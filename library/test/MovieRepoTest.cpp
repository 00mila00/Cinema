//
// Created by student on 13.06.2020.
//

#include <boost/test/unit_test.hpp>
#include "Repositories/MovieRepository.h"
#include "model/Movie.h"
using namespace std;
using namespace boost::posix_time;
BOOST_AUTO_TEST_SUITE(MovieRepoSuite)

    BOOST_AUTO_TEST_CASE(AddMovieTest){
        time_duration td(1,2,3);
        MoviePtr mov(new Movie(2,"Iluzja",td));
        MoviePtr mov2 (new Movie(3,"Iluzja 2",td));
        MovieRepository rep;
        BOOST_TEST(rep.add(mov));
        BOOST_TEST(rep.add(mov2));
        BOOST_TEST(rep.size()==2);
        ////////////TO SAMO ID//////////////
        MoviePtr mov3 (new Movie(3,"Podroznicy",td));
        BOOST_REQUIRE_THROW(rep.add(mov3),logic_error);
        BOOST_TEST(rep.size()==2);
        /////ALE MOZE BYC TEN SAM TYTUL/////
        MoviePtr mov4 (new Movie(4,"Iluzja",td));
        BOOST_TEST(rep.add(mov4)==true);
        //////////KIEDY JEST NULLPTR/////////
        MoviePtr mov5 (new Movie(5,"Nerve",td));
        mov5 = nullptr;
        BOOST_REQUIRE_THROW(rep.add(mov5),logic_error);

    }
    BOOST_AUTO_TEST_CASE(RemoveMovieTest){
        time_duration td(1,2,3);
        MoviePtr mov(new Movie(2,"Iluzja",td));
        MoviePtr mov2 (new Movie(3,"Czarna Wdowa",td));
        MoviePtr mov3 (new Movie(4,"Mulan",td));
        MoviePtr mov4 (new Movie(5,"Iluzja 2",td));
        MoviePtr mov5 (new Movie(6,"Piekna i bestia",td));
        MovieRepository rep;
        rep.add(mov);
        rep.add(mov2);
        rep.add(mov3);
        rep.add(mov4);
        BOOST_TEST(rep.size()==4);
        BOOST_TEST(rep.remove(mov));
        BOOST_TEST(rep.remove(mov2));
        BOOST_TEST(rep.size()==2);
        BOOST_REQUIRE_THROW(rep.remove(mov5),logic_error);


    }

    BOOST_AUTO_TEST_CASE(SizeMovieTest){
        time_duration td(1,2,3);
        MoviePtr mov(new Movie(2,"Iluzja",td));
        MoviePtr mov2 (new Movie(3,"Czarna Wdowa",td));
        MoviePtr mov3 (new Movie(4,"Mulan",td));
        MoviePtr mov4 (new Movie(5,"Iluzja 2",td));
        MovieRepository rep;
        rep.add(mov);
        rep.add(mov2);
        rep.add(mov3);
        rep.add(mov4);
        BOOST_TEST(rep.size()==4);

    }
    BOOST_AUTO_TEST_CASE(SearchMovieTest){
        time_duration td(1,2,3);
        MoviePtr mov(new Movie(2,"Iluzja",td));
        MoviePtr mov2 (new Movie(3,"Czarna Wdowa",td));
        MoviePtr mov3 (new Movie(4,"Mulan",td));
        MoviePtr mov4 (new Movie(5,"Iluzja 2",td));
        MovieRepository rep;
        rep.add(mov);
        rep.add(mov2);
        rep.add(mov3);
        BOOST_TEST(rep.search(2)==mov);
        BOOST_TEST(rep.search(3)==mov2);
        BOOST_REQUIRE_THROW(rep.search(5),logic_error);


    }
BOOST_AUTO_TEST_SUITE_END()