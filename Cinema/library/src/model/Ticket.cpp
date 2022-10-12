//
// Created by student on 02.06.2020.
//

#include "model/Ticket.h"
#include <iostream>
using namespace std;
Ticket::Ticket(const unsigned int ticket_id, bool family_card) : ticket_id(ticket_id), family_card(family_card){
    price=base_price;
}
Ticket::~Ticket() {

}
const unsigned int &Ticket::get_ticket_id() {
    return ticket_id;
}

bool Ticket::is_family_card() const {
    return family_card;
}

void Ticket::set_family_card(bool familyCard) {
    family_card = familyCard;
}

unsigned int Ticket::get_ticket_Id() const {
    return ticket_id;
}


double Ticket::get_base_price() const {
    return base_price;
}

void Ticket::set_base_price(double basePrice) {
    base_price = basePrice;
}
double Ticket::get_price() const {
    return price;
}

void Ticket::set_price(double value) {
    price = value;
}

void Ticket::pay() {
    is_paid = true;
}

void Ticket::set_amount(unsigned int amon) {
    amount=amon;
}

unsigned int Ticket::get_amount() const {
    return amount;
}

//Show * Ticket::get_show() {
//    return show;
//}




