//
// Created by student on 02.06.2020.
//

#ifndef LIBRARY_CASHREGISTER_H
#define LIBRARY_CASHREGISTER_H

#include <iostream>
#include "typedef.h"
#include <memory>
typedef std::shared_ptr<Show> ShowPtr;
class Show;
class Ticket;

class CashRegister {
public:
    CashRegister(ShowPtr show);
    virtual ~CashRegister();
    ShowPtr get_show() const;
    TicketPtr get_ticket(int id) const;
//    std::string get_full_info() const;

//    void buy_ticket();
    bool return_ticket(int id);
    void final_price(TicketPtr);
    bool add(TicketPtr);
private:
    ShowPtr show;
    std::vector<TicketPtr> ticket;

};


#endif //LIBRARY_CASHREGISTER_H
