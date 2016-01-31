//
// Created by Maciej on 30.01.2016.
//


#ifndef HELLOWORLD_BILET_H
#define HELLOWORLD_BILET_H

#include <iostream>

using namespace std;


class Bilet {
public:

    Bilet();

    static string lotniska[7];
    static string  porty[7];
    virtual void generuj() = 0;
    virtual void pokaInfo() = 0;
    friend ostream& operator<< (ostream &out, Bilet &bilet);
    friend istream& operator>> (istream &in, Bilet &bilet);
    void setId(int i);
    int getId();

protected:
    string poczatek;
    string koniec;
    int id;

};


#endif //HELLOWORLD_BILET_H
