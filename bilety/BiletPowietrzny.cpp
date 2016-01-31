//
// Created by Maciej on 30.01.2016.
//

#include <stdlib.h>
#include <stdio.h>
#include "BiletPowietrzny.h"

void BiletPowietrzny::generuj() {
    int a = rand() % 7;
    int b = rand() % 7;
    if (b == a) {
        if (b > 0) {
            --b;
        } else {
            ++b;
        }
    }
    poczatek = lotniska[a];
    koniec = lotniska[b];
}

void BiletPowietrzny::pokaInfo() {
    if(id!=0){
        printf("id: %d ",id);
    }
    printf("z: %s -> samolot -> do: %s\n", poczatek.c_str(), koniec.c_str());

}
