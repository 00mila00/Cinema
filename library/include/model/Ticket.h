//
// Created by student on 02.06.2020.
//

#ifndef CINEMA_TICKET_H
#define CINEMA_TICKET_H
#include <iostream>
#include <string>
class Show;
class Ticket {
public:
    Ticket(const unsigned int ticket_id, bool family_card);

    virtual ~Ticket();
    const unsigned int &get_ticket_id();

    virtual void calc_price() = 0;
    void pay();
    bool is_family_card() const;
    void set_family_card(bool familyCard);
    unsigned int get_ticket_Id() const;
    double get_base_price() const;
    void set_base_price( double basePrice);
    double get_price() const;
    void set_price(double price);
    void set_amount(unsigned int amon);
    unsigned int get_amount() const;

private:
    double base_price=30.0;
    bool family_card;
    double price;
    unsigned int ticket_id;
    bool is_paid=false;
    unsigned int amount;

};


#endif //CINEMA_TICKET_H
