//
// Created by student on 02.06.2020.
//

#include "model/CashRegister.h"
#include "model/Show.h"
#include "model/Ticket.h"
#include <iostream>
#include <string>

#include <sstream>
using namespace std;


CashRegister::CashRegister(ShowPtr show):show(show){}

CashRegister::~CashRegister() {}

ShowPtr CashRegister::get_show() const {
    return show;
}

TicketPtr CashRegister::get_ticket(int id) const {
    for(int i=0;i<ticket.size();i++)
    {
        if(ticket[i]->get_ticket_Id()==id)
            return ticket[i];
    }
    __throw_logic_error("Bilet o tym ID nie istnieje");
}
void CashRegister::final_price(TicketPtr t) {
    double price=t->get_price();
    double mod=3*t->get_amount()*get_show()->get_room()->get_room_type();
    if(get_show()->get_room()->is_vip())
        price*=2;
    t->set_price( price+mod);
}

//std::string CashRegister::get_full_info() const {
//    ostringstream sout;
//    sout<<"Show: "<<get_show()->get_show_info()<<endl<<"Price: "<<get_final_price()<< " PLN";
//    return sout.str();
//}

//void CashRegister::buy_ticket() {
//get_ticket()->pay();
//}

bool CashRegister::return_ticket(int id) {
    show->free_place(id);
    for(int i=0;i<ticket.size();i++)
    {
        if(ticket[i]->get_ticket_Id()==id)
        {
            ticket.erase(ticket.begin()+i);
            return true;
        }

    }
    __throw_logic_error("Nie mozna zwrocic biletu, ktory nie istnieje");
}

bool CashRegister::add(TicketPtr t){
    if(t==nullptr){
        __throw_logic_error("Bilet nie moze byc nullptr");
    }
    ticket.push_back(t);
    return true;
}




