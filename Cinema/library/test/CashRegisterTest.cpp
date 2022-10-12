//
// Created by student on 13.06.2020.
//
#include "model/CashRegister.h"
#include <iostream>
#include <boost/test/unit_test.hpp>
#include "model/Ticket.h"
#include "model/Multiple.h"
#include "model/Single.h"
using namespace boost::posix_time;
using namespace std;
BOOST_AUTO_TEST_SUITE(CashRegisterSuite)
BOOST_AUTO_TEST_CASE(ConstructorTest){
        time_duration td(2,3,0);
        MoviePtr movie (new Movie(10,"Muminki",td));
        RoomPtr room( new Room(1,3,true,30,30));
        ShowPtr show (new Show(1, movie , room,pt::ptime(gr::date(2020,6,20),pt::hours(0)+pt::minutes(0))));
        CashRegister cr(show);
        BOOST_TEST(cr.get_show()==show);

}
BOOST_AUTO_TEST_CASE(GetTicketTest){
        time_duration td(2,3,0);
        MoviePtr movie (new Movie(10,"Muminki",td));
        RoomPtr room( new Room(1,3,true,30,30));
        ShowPtr show (new Show(1, movie , room,pt::ptime(gr::date(2020,6,20),pt::hours(0)+pt::minutes(0))));
        CashRegister cr(show);
        TicketPtr tic(new Multiple(2,true,4));
        TicketPtr tic2(new Single(3,false,true));
        TicketPtr tic3(new Single(4,true,false));
        TicketPtr tic4(new Single(5,true,false));
        cr.add(tic);
        cr.add(tic2);
        cr.add(tic3);
        BOOST_TEST(cr.get_ticket(2)==tic);
        BOOST_REQUIRE_THROW(cr.get_ticket(5),logic_error);
}
BOOST_AUTO_TEST_CASE(AddTicketTest){
        time_duration td(2,3,0);
        MoviePtr movie (new Movie(10,"Muminki",td));
        RoomPtr room( new Room(1,3,true,30,30));
        ShowPtr show (new Show(1, movie , room,pt::ptime(gr::date(2020,6,20),pt::hours(0)+pt::minutes(0))));
        CashRegister cr(show);
        TicketPtr tic(new Multiple(2,true,4));
        TicketPtr tic2(new Single(3,false,true));
        TicketPtr tic3(new Single(4,true,false));
        TicketPtr tic4(new Single(5,true,false));
        BOOST_TEST(cr.add(tic));
        BOOST_TEST(cr.add(tic2));
        BOOST_TEST(cr.add(tic3));
        tic4 = nullptr;
        BOOST_REQUIRE_THROW(cr.add(tic4),logic_error);

}
BOOST_AUTO_TEST_CASE(ReturnTicketTest){
        time_duration td(2,3,0);
        MoviePtr movie (new Movie(10,"Muminki",td));
        RoomPtr room( new Room(1,3,true,30,30));
        ShowPtr show (new Show(1, movie , room,pt::ptime(gr::date(2020,6,20),pt::hours(0)+pt::minutes(0))));
        CashRegister cr(show);
        TicketPtr tic(new Multiple(2,true,4));
        TicketPtr tic2(new Single(3,false,true));
        TicketPtr tic3(new Single(4,true,false));
        TicketPtr tic4(new Single(5,true,false));
        cr.add(tic);
        cr.add(tic2);
        cr.add(tic3);
        BOOST_TEST(cr.return_ticket(2)==true);
        BOOST_TEST(cr.return_ticket(3)==true);
        BOOST_REQUIRE_THROW(cr.return_ticket(5),logic_error);

}
    BOOST_AUTO_TEST_CASE(FinalPriceTest) {
        time_duration td(2,3,0);
        MoviePtr movie (new Movie(10,"Muminki",td));
        RoomPtr room( new Room(1,3,true,30,30));
        ShowPtr show (new Show(1, movie , room,pt::ptime(gr::date(2020,6,20),pt::hours(0)+pt::minutes(0))));
        CashRegister cr(show);
        TicketPtr tic(new Multiple(2,true,4));
        TicketPtr tic2(new Single(3,false,true));
        TicketPtr tic3(new Single(4,true,false));
        TicketPtr tic4(new Single(5,true,false));
        cr.add(tic);
        cr.add(tic2);
        cr.add(tic3);
        cr.final_price(tic);
        BOOST_TEST(tic->get_price()==156);

    }

BOOST_AUTO_TEST_SUITE_END()