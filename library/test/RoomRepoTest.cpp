//
// Created by student on 13.06.2020.
//
#include <boost/test/unit_test.hpp>
#include "Repositories/RoomRepository.h"
#include "model/Room.h"
using namespace std;
BOOST_AUTO_TEST_SUITE(RoomRepoSuite)

    BOOST_AUTO_TEST_CASE(AddRoomTest){
        RoomPtr r (new Room(2,3,true,30,25));
        RoomPtr r2 (new Room(3,3,false,30,25));
        RoomRepository rep;
        BOOST_TEST(rep.add(r)== true);
        BOOST_TEST(rep.add(r2)== true);
        BOOST_TEST(rep.size()==2);
        RoomPtr r3 (new Room(3,4,false,35,25));
        BOOST_REQUIRE_THROW(rep.add(r3),logic_error);
        BOOST_TEST(rep.size()==2);
        RoomPtr r4 (new Room(4,5,false,35,25));
        r4=nullptr;
        BOOST_REQUIRE_THROW(rep.add(r4),logic_error);


    }
    BOOST_AUTO_TEST_CASE(RemoveRoomTest){
        RoomPtr r (new Room(2,3,true,30,25));
        RoomPtr r2 (new Room(3,3,false,30,25));
        RoomPtr r3 (new Room(4,3,false,30,25));
        RoomRepository rep;
        rep.add(r);
        rep.add(r2);
        BOOST_TEST(rep.size()==2);
        BOOST_TEST(rep.remove(r));
        BOOST_TEST(rep.size()==1);
        rep.remove(r2);
        BOOST_TEST(rep.size()==0);
        BOOST_REQUIRE_THROW(rep.remove(r3),logic_error);

    }

    BOOST_AUTO_TEST_CASE(SizeRoomTest){
        RoomPtr r (new Room(2,3,true,30,25));
        RoomPtr r2 (new Room(3,3,false,30,25));
        RoomPtr r3 (new Room(4,3,false,30,25));
        RoomPtr r4 (new Room(5,3,false,30,25));
        RoomPtr r5 (new Room(6,3,false,30,25));
        RoomRepository rep;
        rep.add(r);
        rep.add(r2);
        rep.add(r3);
        rep.add(r4);
        rep.add(r5);
        BOOST_TEST(rep.size()==5);

    }
    BOOST_AUTO_TEST_CASE(SearchRoomTest){
        RoomPtr r (new Room(2,3,true,30,25));
        RoomPtr r2 (new Room(3,4,false,30,25));
        RoomPtr r3 (new Room(4,3,false,50,25));
        RoomPtr r4 (new Room(5,2,true,40,20));
        RoomPtr r5 (new Room(6,3,false,30,25));
        RoomPtr r6 (new Room(7,3,false,30,25));
        RoomRepository rep;
        rep.add(r);
        rep.add(r2);
        rep.add(r3);
        rep.add(r4);
        rep.add(r5);
        BOOST_TEST(rep.search(3)==r2);
        BOOST_TEST(rep.search(6)==r5);
        BOOST_REQUIRE_THROW(rep.search(7),logic_error);



    }
BOOST_AUTO_TEST_SUITE_END()