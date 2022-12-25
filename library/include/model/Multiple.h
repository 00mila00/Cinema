//
// Created by student on 02.06.2020.
//

#ifndef LIBRARY_MULTIPLE_H
#define LIBRARY_MULTIPLE_H

#include "model/Ticket.h"
#include <iostream>
class Multiple : public Ticket {
public:
    Multiple(const unsigned int ticket_id, bool family_card, const unsigned int amount);
    virtual ~Multiple();

    void calc_price() override;
};


#endif //LIBRARY_MULTIPLE_H
