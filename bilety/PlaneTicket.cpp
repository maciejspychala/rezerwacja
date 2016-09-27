//
// Created by Maciej on 30.01.2016.
//

#include <stdlib.h>
#include <stdio.h>
#include "PlaneTicket.h"

void PlaneTicket::generate() {
    int a = rand() % 7;
    int b = rand() % 7;
    if (b == a) {
        if (b > 0) {
            --b;
        } else {
            ++b;
        }
    }
    beginning = airports[a];
    ending = airports[b];
}

void PlaneTicket::showInfo() {
    if(id!=0){
        printf("id: %d ",id);
    }
    printf("from: %s -> airplane -> to: %s\n", beginning.c_str(), ending.c_str());

}
