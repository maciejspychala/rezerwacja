//
// Created by Maciej on 30.01.2016.
//


#ifndef HELLOWORLD_BILET_H
#define HELLOWORLD_BILET_H

#include <iostream>

using namespace std;


class Ticket {
public:

    Ticket();

    static string airports[7];
    static string  ports[7];
    virtual void generate() = 0;
    virtual void showInfo() = 0;
    friend ostream& operator<< (ostream &out, Ticket &bilet);
    friend istream& operator>> (istream &in, Ticket &bilet);
    void setId(int i);
    int getId();

protected:
    string beginning;
    string ending;
    int id;

};


#endif //HELLOWORLD_BILET_H
