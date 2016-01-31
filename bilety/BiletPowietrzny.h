//
// Created by Maciej on 30.01.2016.
//

#ifndef HELLOWORLD_BILETPOWIETRZNY_H
#define HELLOWORLD_BILETPOWIETRZNY_H

#include "Bilet.h"

class BiletPowietrzny : public Bilet {

public:
    virtual void generuj() override;

    virtual void pokaInfo() override;
};


#endif //HELLOWORLD_BILETPOWIETRZNY_H
