//
// Created by Maciej on 30.01.2016.
//

#ifndef HELLOWORLD_BILETMORSKI_H
#define HELLOWORLD_BILETMORSKI_H


#include <stdio.h>
#include "Ticket.h"

class ShipTicket : public Ticket {

public:
    virtual void generate() override;

    virtual void showInfo() override;
};


#endif //HELLOWORLD_BILETMORSKI_H
