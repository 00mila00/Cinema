//
// Created by student on 02.06.2020.
//

#include "model/Multiple.h"
Multiple::Multiple(const unsigned int ticket_id, bool family_card, const unsigned int amount):Ticket(ticket_id, family_card) {
    set_amount(amount);
    calc_price();
}

Multiple::~Multiple() {

}


void Multiple::calc_price() {
    if(is_family_card()){
        set_price(get_amount()*get_base_price()*0.5);
    }
}

