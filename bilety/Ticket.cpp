//
// Created by Maciej on 30.01.2016.
//

#include <sstream>
#include "Ticket.h"

string Ticket::airports[] = {"Amsterdam", "Tokyo", "New York", "Barcelona", "Warsaw", "Berlin", "Oslo"};
string Ticket::ports[] = {"London", "Stambul", "Gdansk", "Hamburg", "Malaga", "Valencia", "Dublin"};

Ticket::Ticket() {
    id = 0;
}

istream &operator>>(istream &in, Ticket &bilet) {
    in >> bilet.beginning;
    in >> bilet.ending;
    in >> bilet.id;
    return in;
}

ostream &operator<<(ostream &out, Ticket &bilet) {
    out << bilet.beginning << '\n' << bilet.ending << '\n' << bilet.id << '\n';
    return out;
}


void Ticket::setId(int i) {
    id = i;
}

int Ticket::getId() {
    return id;
}
