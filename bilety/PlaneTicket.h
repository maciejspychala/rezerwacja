//
// Created by Maciej on 30.01.2016.
//

#ifndef HELLOWORLD_BILETPOWIETRZNY_H
#define HELLOWORLD_BILETPOWIETRZNY_H

#include "Ticket.h"

class PlaneTicket : public Ticket {

public:
    virtual void generate() override;

    virtual void showInfo() override;
};


#endif //HELLOWORLD_BILETPOWIETRZNY_H
