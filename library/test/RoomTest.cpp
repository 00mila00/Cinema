//
// Created by student on 13.06.2020.
//

#include <boost/test/unit_test.hpp>
#include "model/Room.h"
#include <iostream>
#include <model/Show.h>
#include <model/typedef.h>

using namespace std;
BOOST_AUTO_TEST_SUITE(RoomSuite)
    BOOST_AUTO_TEST_CASE(ConstructorTest){
        RoomPtr room (new Room(1,3,true,30,30));
        BOOST_TEST(room->get_room_nr()==1);
        BOOST_TEST(room->get_room_type()==3);
        BOOST_TEST(room->is_vip());
        BOOST_TEST(room->get_rows()==30);
        BOOST_TEST(room->get_columns()==30);
        room->set_rows(40);
        BOOST_TEST(room->get_rows()==40);
        BOOST_REQUIRE_THROW(room->set_rows(0),logic_error);
        BOOST_TEST(room->get_rows()==40);
        room->set_columns(40);
        BOOST_TEST(room->get_columns()==40);
        BOOST_REQUIRE_THROW(room->set_columns(0),logic_error);
        BOOST_TEST(room->get_columns()==40);
        room->set_vip(false);
        BOOST_TEST(room->is_vip() == 0);
        BOOST_REQUIRE_THROW(room->set_room_type(8),logic_error);
        room->set_room_type(4);
        BOOST_TEST(room->get_room_type()==4);

    }

BOOST_AUTO_TEST_SUITE_END()