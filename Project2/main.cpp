//
//  main.cpp
//  Project2
//
//  Created by Joseph Lovoi on 10/17/18.
//  Copyright © 2018 Joseph Lovoi. All rights reserved.
//

#include "HashTable.cpp"
#include <iostream>

int main() {
    HashTable<char*>* myHashTable;
    char* Names[25] = {"Andy B", "Amy Dean", "Antonio G", "Andy Roberts",
        "Brian W","Bob Macy", "Brent James", "Buck Muck",
        "Cannon James", "Cart Wright", "Catherine Zeta", "Carl Lewis", "David Johnson", "Dowd Peter",
        "Daniel Fauchier", "Dawn Smith" "Yarda Varda", "Yami Jacob", "Yester Louis", "Yukon Oklahoma",
        "Zandi Rich", "Zea John", "Zelby Leon", "Ziert Paul", "Zanola Helen"};
    int i;
    myHashTable = new HashTable<char*>(26);
    for (i=0; i < 24; i++) {
        (*myHashTable).insert(Names[i]);
    }
    cout << "Printing the hash table after inserting...." << endl;
    cout << myHashTable << endl;
    if ((*myHashTable).find("Zandi Rich")) {
        cout << "Zandi Rich is in the list" << endl;
    }
    else {
        cout << "Zandi Rich is not in the list" << endl;
    }
    return 0;
}
