//
// Created by Maciej on 30.01.2016.
//

#ifndef HELLOWORLD_BILETMORSKI_H
#define HELLOWORLD_BILETMORSKI_H


#include <stdio.h>
#include "Bilet.h"

class BiletMorski : public Bilet {

public:
    virtual void generuj() override;

    virtual void pokaInfo() override;
};


#endif //HELLOWORLD_BILETMORSKI_H
