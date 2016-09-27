//
// Created by Maciej on 30.01.2016.
//

#include <stdlib.h>
#include <stdio.h>
#include "MixedTicket.h"

void MixedTicket::generate() {
    int a = rand() % 7;
    int b = rand() % 7;
    int c = rand() % 7;
    if (b == a) {
        if (b > 0) {
            --b;
        } else {
            ++b;
        }
    }
    if (b == c) {
        if (c > 0) {
            --c;
        } else {
            ++c;
        }
    }
    if (c - b % 2 == 0) {
        beginning = ports[a];
        through = ports[b];
        ending = airports[c];
        firstVehicle = "prom";
        secondVehicle = "plane";
    } else {
        beginning = airports[a];
        through = airports[b];
        ending = ports[c];
        firstVehicle = "plane";
        secondVehicle = "prom";
    }

}

void MixedTicket::showInfo() {
    if(id!=0){
        printf("id: %d ",id);
    }
    printf("from: %s -> %s -> through: %s -> %s -> to: %s\n", beginning.c_str(), firstVehicle.c_str(),
           through.c_str(), secondVehicle.c_str(), ending.c_str());
}

ostream &operator<<(ostream &out, MixedTicket &ticket) {
    out << ticket.beginning << '\n' << ticket.through << '\n' << ticket.ending << '\n' << ticket.firstVehicle << '\n' <<
    ticket.secondVehicle << '\n' << ticket.id << '\n';
    return out;
}

istream &operator>>(istream &in, MixedTicket &ticket) {
    in >> ticket.beginning;
    in >> ticket.through;
    in >> ticket.ending;
    in >> ticket.firstVehicle;
    in >> ticket.secondVehicle;
    in >> ticket.id;
    return in;
}

