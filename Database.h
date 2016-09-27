//
// Created by Maciej on 31.01.2016.
//

#ifndef HELLOWORLD_BAZADANYCH_H
#define HELLOWORLD_BAZADANYCH_H

#include <iostream>
#include <vector>
#include "bilety/Ticket.h"

using namespace std;
template <class T>
class Database {
public:
    int size(){
        return list.size();
    };
    void operator += (T bilet)
    {
        list.push_back(bilet);
    }
    void operator -= (int id)
    {
        for(int i = 0; i<list.size();i++){
            if(((T)list[i]).getId() == id){
                list.erase(list.begin() + i);
                break;
            }
        }
    }
    void pokaInfo(){
        for(int i = 0; i < size(); i++){
            list[i].showInfo();
        }
    }
    T get(int i){
        return list[i];
    }
private:
    vector<T> list;

};


#endif //HELLOWORLD_BAZADANYCH_H
