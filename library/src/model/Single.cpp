//
// Created by student on 02.06.2020.
//

#include "model/Single.h"
Single::Single(const unsigned int ticket_id, bool family_card, bool discount):Ticket(ticket_id, family_card) , discount(discount) {
    set_amount(1);
    calc_price();
}
Single::~Single(){

}

bool Single::is_discount() const {
    return discount;
}

void Single::calc_price() {
    if(is_discount()){
        set_price(get_base_price()*0.7);
    }
    if(is_family_card()){
        set_price(get_base_price()*0.5);
    }
    if(is_discount()&&is_family_card())
        set_price(get_base_price()*0.5*0.7);
}

void Single::set_discount(bool i) {
    discount=i;
}
