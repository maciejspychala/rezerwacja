//
// Created by Maciej on 30.01.2016.
//

#ifndef HELLOWORLD_BILETMIESZANY_H
#define HELLOWORLD_BILETMIESZANY_H


#include "Bilet.h"

class BiletMieszany : public Bilet {
protected:
    string pomiedzy;
    string pierwszyPojazd;
    string drugiPojazd;
public:
    virtual void generuj() override;
    friend ostream& operator<< (ostream &out, BiletMieszany &bilet);
    friend istream& operator>> (istream &in, BiletMieszany &bilet);
    virtual void pokaInfo();
};


#endif //HELLOWORLD_BILETMIESZANY_H
