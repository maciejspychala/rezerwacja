//
// Created by Maciej on 30.01.2016.
//

#include <stdlib.h>
#include <stdio.h>
#include "BiletMieszany.h"

void BiletMieszany::generuj() {
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
        poczatek = porty[a];
        pomiedzy = porty[b];
        koniec = lotniska[c];
        pierwszyPojazd = "prom";
        drugiPojazd = "samolot";
    } else {
        poczatek = lotniska[a];
        pomiedzy = lotniska[b];
        koniec = porty[c];
        pierwszyPojazd = "samolot";
        drugiPojazd = "prom";
    }

}

void BiletMieszany::pokaInfo() {
    if(id!=0){
        printf("id: %d ",id);
    }
    printf("z: %s -> %s -> przez: %s -> %s -> do: %s\n", poczatek.c_str(), pierwszyPojazd.c_str(),
           pomiedzy.c_str(), drugiPojazd.c_str(), koniec.c_str());
}

ostream &operator<<(ostream &out, BiletMieszany &bilet) {
    out << bilet.poczatek << '\n' << bilet.pomiedzy << '\n' << bilet.koniec << '\n' << bilet.pierwszyPojazd << '\n' <<
    bilet.drugiPojazd << '\n' << bilet.id << '\n';
    return out;
}

istream &operator>>(istream &in, BiletMieszany &bilet) {
    in >> bilet.poczatek;
    in >> bilet.pomiedzy;
    in >> bilet.koniec;
    in >> bilet.pierwszyPojazd;
    in >> bilet.drugiPojazd;
    in >> bilet.id;
    return in;
}

