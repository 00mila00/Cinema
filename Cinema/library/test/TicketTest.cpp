//
// Created by student on 13.06.2020.
//
#include <boost/test/unit_test.hpp>
#include <model/typedef.h>
#include <model/Single.h>
#include <model/Multiple.h>
#include "model/Ticket.h"
using namespace std;
BOOST_AUTO_TEST_SUITE(TicketSuite)


    BOOST_AUTO_TEST_CASE(SingleTicketTest) {
        SinglePtr tic(new Single(2, true, false));
        BOOST_TEST(tic->get_ticket_Id() == 2);
        BOOST_TEST(tic->get_base_price() == 30);
        BOOST_TEST(tic->is_family_card() == true);
        BOOST_TEST(tic->is_discount() == false);
        tic->set_base_price(10.0);
        BOOST_TEST(tic->get_base_price()==10.0);
        tic->calc_price();
        BOOST_TEST(tic->get_price()==5.0);
        SinglePtr tic2(new Single(2, true, true));
        tic2->set_base_price(10.0);
        tic2->calc_price();
        BOOST_TEST(tic2->get_price()==3.5);

    }

    BOOST_AUTO_TEST_CASE(MultipleTicketTest) {
        MultiplePtr tic(new Multiple(2,true, 4));
        BOOST_TEST(tic->get_ticket_Id()==2);
        BOOST_TEST(tic->is_family_card());
        BOOST_TEST(tic->get_amount()==4);
        tic->set_amount(10);
        tic->calc_price();
        BOOST_TEST(tic->get_price()==150);
        tic->set_family_card(false);
        BOOST_TEST(tic->is_family_card()==false);

    }

BOOST_AUTO_TEST_SUITE_END()