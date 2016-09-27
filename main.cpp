#include <iostream>
#include <fstream>
#include "bilety/MixedTicket.h"
#include "bilety/ShipTicket.h"
#include "Database.h"
#include "bilety/PlaneTicket.h"


using namespace std;
Database<PlaneTicket> planeData;
Database<ShipTicket> shipData;
Database<MixedTicket> mixedData;
int id = 236235;

void book();

void save();

void load();

void showMenu();

void save() {
    fstream file("save.xd", ios::out);
    if (file.good()) {
        file << id << endl;
        file << planeData.size() << '\n';
        for (int j = 0; j < planeData.size(); j++) {
            PlaneTicket c = planeData.get(j);
            file << c;
        }
        file << shipData.size() << '\n';
        for (int j = 0; j < shipData.size(); j++) {
            ShipTicket c = shipData.get(j);
            file << c;
        }
        file << mixedData.size() << '\n';
        for (int j = 0; j < mixedData.size(); j++) {
            MixedTicket c = mixedData.get(j);
            file << c;
        }

    }
    file.close();
}

void showMenu() {
    printf("[B]ook travel\n");
    printf("[C]ancel reservation\n");
    printf("[S]how all reservation\n");
    printf("[E]nd\n");
    char a;
    cin >> a;
    switch (a) {
        case 'b' :
        case 'B' :
            book();
            save();
            showMenu();
            break;
        case 'c' :
        case 'C' :
            cout << "Write id you want to erase: ";
            int erase;
            cin >> erase;
            planeData -= erase;
            shipData -= erase;
            mixedData -= erase;
            cout << endl;
            save();
            showMenu();
            break;
        case 's' :
        case 'S' :
            planeData.pokaInfo();
            shipData.pokaInfo();
            mixedData.pokaInfo();
            showMenu();
            break;
        case 'e' :
        case 'E' :
            break;
        default:
            printf("Wrong letter\n");
            showMenu();
            break;
    }
}

void book() {
    vector<PlaneTicket> air;
    vector<ShipTicket> sea;
    vector<MixedTicket> mixed;
    int j = 1;
    for (int i = 0; i < 3; i++) {
        PlaneTicket a;
        ShipTicket b;
        MixedTicket c;
        a.generate();
        b.generate();
        c.generate();
        cout << i + j++ << ". ";
        a.showInfo();
        cout << i + j++ << ". ";
        b.showInfo();
        cout << i + j << ". ";
        c.showInfo();
        air.push_back(a);
        sea.push_back(b);
        mixed.push_back(c);
    }
    cout << "which id you want to book: ";
    int c;
    cin >> c;
    while (c > 9 || c < 1) {
        cout << "wrong id, write once again: ";
        cin >> c;
    }
    --c;
    switch (c % 3) {
        case 0 :
            air[c / 3].setId(id++);
            planeData += air[c / 3];
            break;
        case 1 :
            sea[c / 3].setId(id++);
            shipData += sea[c / 3];
            break;
        case 2 :
            mixed[c / 3].setId(id++);
            mixedData += mixed[c / 3];
            break;

        default:
            break;
    }
    save();
    cout << endl;
}

void load() {
    PlaneTicket planeTi;
    ShipTicket shipTicket;
    MixedTicket mixedTicket;
    fstream file("save.xd", ios::in);
    int i = 0;
    if (file.good()) {
        file >> id;
        file >> i;
        for (int j = 0; j < i; j++) {
            file >> planeTi;
            planeData += planeTi;
        }
        file >> i;
        for (int j = 0; j < i; j++) {
            file >> shipTicket;
            shipData += shipTicket;
        }
        file >> i;
        for (int j = 0; j < i; j++) {
            file >> mixedTicket;
            mixedData += mixedTicket;
        }

    }
    file.close();
}


int main() {
    srand(time(NULL));
    load();
    showMenu();
    return 0;
}