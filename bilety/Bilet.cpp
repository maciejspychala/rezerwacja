//
// Created by Maciej on 30.01.2016.
//

#include <sstream>
#include "Bilet.h"

string Bilet::lotniska[] = {"Amsterdam", "Tokyo", "Kruszwica", "Suwalki", "Radom", "Krosno", "Mielec"};
string Bilet::porty[] = {"Warna", "Stambul", "Gdansk", "Trypolis", "Malaga", "Walencja", "Chalupy"};

Bilet::Bilet() {
    id = 0;
}

istream &operator>>(istream &in, Bilet &bilet) {
    in >> bilet.poczatek;
    in >> bilet.koniec;
    in >> bilet.id;
    return in;
}

ostream &operator<<(ostream &out, Bilet &bilet) {
    out << bilet.poczatek << '\n' << bilet.koniec << '\n' << bilet.id << '\n';
    return out;
}


void Bilet::setId(int i) {
    id = i;
}

int Bilet::getId() {
    return id;
}
