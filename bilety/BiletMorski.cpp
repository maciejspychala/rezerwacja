//
// Created by Maciej on 30.01.2016.
//

#include <stdlib.h>
#include "BiletMorski.h"

void BiletMorski::generuj() {
    int a = rand() % 7;
    int b = rand() % 7;
    if (b == a) {
        if (b > 0) {
            --b;
        } else {
            ++b;
        }
    }
    poczatek = porty[a];
    koniec = porty[b];
}

void BiletMorski::pokaInfo() {
    if(id!=0){
        printf("id: %d ",id);
    }
    printf("z: %s -> prom -> do:%s\n", poczatek.c_str(), koniec.c_str());
}
