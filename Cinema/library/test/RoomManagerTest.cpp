//
// Created by student on 13.06.2020.
//

#include <boost/test/unit_test.hpp>
#include "Repositories/RoomManager.h"
#include "model/Room.h"
using namespace std;
BOOST_AUTO_TEST_SUITE(RoomManagerSuite)
    BOOST_AUTO_TEST_CASE(CreateRoomManagerTest){
        RoomPtr r (new Room(2,3,true,20,20));
        RoomPtr r2 (new Room(1,3,true,30,50));
        RoomPtr r3 (new Room(3,2,false,50,30));
        RoomPtr r4 (new Room(5,5,false,40,30));
        RoomManager m;
        m.create_room(r);
        m.create_room(r2);
        m.create_room(r3);
        BOOST_TEST(m.get_nr_of_rooms()==3);
    }
    BOOST_AUTO_TEST_CASE(DeleteRoomManagerTest){
        RoomPtr r (new Room(2,3,true,20,20));
        RoomPtr r2 (new Room(1,3,true,30,50));
        RoomPtr r3 (new Room(3,2,false,50,30));
        RoomManager m;
        m.create_room(r);
        m.create_room(r2);
        m.create_room(r3);
        m.delete_room(r);
        BOOST_TEST(m.get_nr_of_rooms()==2);
        RoomManager m2;
        RoomPtr r5 (new Room(10,5,false,20,20));
        m2.create_room(r5);
        m2.delete_room(r5);
        BOOST_TEST(m.get_nr_of_rooms()==2);
    }

BOOST_AUTO_TEST_SUITE_END()