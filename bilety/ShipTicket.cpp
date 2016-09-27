//
// Created by Maciej on 30.01.2016.
//

#include <stdlib.h>
#include "ShipTicket.h"

void ShipTicket::generate() {
    int a = rand() % 7;
    int b = rand() % 7;
    if (b == a) {
        if (b > 0) {
            --b;
        } else {
            ++b;
        }
    }
    beginning = ports[a];
    ending = ports[b];
}

void ShipTicket::showInfo(){
    if(id!=0){
        printf("id: %d ",id);
    }
    printf("from: %s -> ferry -> to :%s\n", beginning.c_str(), ending.c_str());
}
