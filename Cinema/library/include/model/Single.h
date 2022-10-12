//
// Created by student on 02.06.2020.
//

#ifndef LIBRARY_SINGLE_H
#define LIBRARY_SINGLE_H

#include "model/Ticket.h"

class Single : public Ticket{
public:
    Single(const unsigned int ticket_id, bool family_card,  bool is_discount);
    virtual ~Single();

    bool is_discount() const;
    void set_discount(bool i);
    void calc_price() override;

private:
    bool discount = false;
};


#endif //LIBRARY_SINGLE_H
