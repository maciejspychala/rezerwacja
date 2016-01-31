//
// Created by Maciej on 31.01.2016.
//

#ifndef HELLOWORLD_BAZADANYCH_H
#define HELLOWORLD_BAZADANYCH_H

#include <iostream>
#include <vector>
#include "bilety/Bilet.h"

using namespace std;
template <class T>
class BazaDanych {
public:
    int size(){
        return lista.size();
    };
    void operator += (T bilet)
    {
        lista.push_back(bilet);
    }
    void operator -= (int id)
    {
        for(int i = 0; i<lista.size();i++){
            if(((T)lista[i]).getId() == id){
                lista.erase(lista.begin() + i);
                break;
            }
        }
    }
    void pokaInfo(){
        for(int i = 0; i < size(); i++){
            lista[i].pokaInfo();
        }
    }
    T get(int i){
        return lista[i];
    }
private:
    vector<T> lista;

};


#endif //HELLOWORLD_BAZADANYCH_H
