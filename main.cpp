#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include "bilety/BiletMieszany.h"
#include "bilety/BiletMorski.h"
#include "BazaDanych.h"
#include "bilety/BiletPowietrzny.h"


using namespace std;
BazaDanych<BiletPowietrzny> bazaPowietrzna;
BazaDanych<BiletMorski> bazaMorska;
BazaDanych<BiletMieszany> bazaMieszana;
int id = 236235;

void rezerwuj();

void zapisz();

void wczytaj();

void pokaMenu();

void zapisz() {
    fstream plik("save.xd", ios::out);
    if (plik.good()) {
        plik << id << endl;
        plik << bazaPowietrzna.size() << '\n';
        for (int j = 0; j < bazaPowietrzna.size(); j++) {
            BiletPowietrzny c = bazaPowietrzna.get(j);
            plik << c;
        }
        plik << bazaMorska.size() << '\n';
        for (int j = 0; j < bazaMorska.size(); j++) {
            BiletMorski c = bazaMorska.get(j);
            plik << c;
        }
        plik << bazaMieszana.size() << '\n';
        for (int j = 0; j < bazaMieszana.size(); j++) {
            BiletMieszany c = bazaMieszana.get(j);
            plik << c;
        }

    }
    plik.close();
}

void pokaMenu() {
    printf("[Z]arezerwuj podroz\n");
    printf("[A]nuluj rezerwacje\n");
    printf("[W]yswietl wszystkie rezerwacje\n");
    printf("[K]oniec\n");
    char a;
    cin >> a;
    switch (a) {
        case 'z' :
        case 'Z' :
            rezerwuj();
            zapisz();
            pokaMenu();
            break;
        case 'a' :
        case 'A' :
            cout<<"Napisz id rezerwacji, ktora chcesz usunac: ";
            int erase;
            cin >> erase;
            bazaPowietrzna -= erase;
            bazaMorska -= erase;
            bazaMieszana -= erase;
            cout << endl;
            zapisz();
            pokaMenu();
            break;
        case 'w' :
        case 'W' :
            bazaPowietrzna.pokaInfo();
            bazaMorska.pokaInfo();
            bazaMieszana.pokaInfo();
            pokaMenu();
            break;
        case 'k' :
        case 'K' :
            break;
        default:
            printf("zla litera\n");
            pokaMenu();
            break;
    }
}

void rezerwuj() {
    vector<BiletPowietrzny> powietrze;
    vector<BiletMorski> woda;
    vector<BiletMieszany> wszystko;
    int j = 1;
    for (int i = 0; i < 3; i++) {
        BiletPowietrzny a;
        BiletMorski b;
        BiletMieszany c;
        a.generuj();
        b.generuj();
        c.generuj();
        cout << i + j++ << ". ";
        a.pokaInfo();
        cout << i + j++ << ". ";
        b.pokaInfo();
        cout << i + j << ". ";
        c.pokaInfo();
        powietrze.push_back(a);
        woda.push_back(b);
        wszystko.push_back(c);
    }
    cout << "podaj numer, ktory chcesz zarezerwowac: ";
    int c;
    cin >> c;
    while (c > 9 || c < 1) {
        cout << "podales zly numer, podaj jeszcze raz : ";
        cin >> c;
    }
    --c;
    switch (c % 3) {
        case 0 :
            powietrze[c / 3].setId(id++);
            bazaPowietrzna += powietrze[c / 3];
            break;
        case 1 :
            woda[c / 3].setId(id++);
            bazaMorska += woda[c / 3];
            break;
        case 2 :
            wszystko[c / 3].setId(id++);
            bazaMieszana += wszystko[c / 3];
            break;

        default:
            break;
    }
    zapisz();
    cout << endl;
}

void wczytaj() {
    BiletPowietrzny biletPowietrzny;
    BiletMorski biletMorski;
    BiletMieszany biletMieszany;
    fstream plik("save.xd", ios::in);
    int i = 0;
    if (plik.good()) {
        plik >> id;
        plik >> i;
        for (int j = 0; j < i; j++) {
            plik >> biletPowietrzny;
            bazaPowietrzna += biletPowietrzny;
        }
        plik >> i;
        for (int j = 0; j < i; j++) {
            plik >> biletMorski;
            bazaMorska += biletMorski;
        }
        plik >> i;
        for (int j = 0; j < i; j++) {
            plik >> biletMieszany;
            bazaMieszana += biletMieszany;
        }

    }
    plik.close();
}


int main() {
    srand(time(NULL));
    wczytaj();
    pokaMenu();
    return 0;
}