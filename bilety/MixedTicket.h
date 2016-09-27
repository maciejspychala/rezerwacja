//
// Created by Maciej on 30.01.2016.
//

#ifndef HELLOWORLD_BILETMIESZANY_H
#define HELLOWORLD_BILETMIESZANY_H


#include "Ticket.h"

class MixedTicket : public Ticket {
protected:
    string through;
    string firstVehicle;
    string secondVehicle;
public:
    virtual void generate() override;
    friend ostream& operator<< (ostream &out, MixedTicket &bilet);
    friend istream& operator>> (istream &in, MixedTicket &bilet);
    virtual void showInfo();
};


#endif //HELLOWORLD_BILETMIESZANY_H
