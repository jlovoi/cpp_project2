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
        "Daniel Fauchier", "Dawn Smith", "Yarda Varda", "Yami Jacob", "Yester Louis", "Yukon Oklahoma",
        "Zandi Rich", "Zea John", "Zelby Leon", "Ziert Paul", "Zanola Helen"};
    int i;
    myHashTable = new HashTable<char*>(25);
    for (i=0; i < 25; i++) {
        (*myHashTable).insert(Names[i]);
    }
    std::cout << "Printing the hash table after inserting...." << std::endl;
    std::cout << myHashTable << std::endl;
    if ((*myHashTable).find("Zanola Helen")) {
        std::cout << "Zanola Helen is in the list" << std::endl;
    }
    else {
        std::cout << "Zanola Helen is not in the list" << std::endl;
    }
    if ((*myHashTable).find("Zanola Helen")) {
        std::cout << "Zanola Helen is in the list" << std::endl;
    }
    else {
        std::cout << "Zanola Helen is not in the list" << std::endl;
    }
    (*myHashTable).remove("Zea John");
    if ((*myHashTable).find("Zea John")) {
        std::cout << "Zea John is in the list" << std::endl;
    }
    else {
        std::cout << "Zea John is not in the list" << std::endl;
    }
    
    for (i=0; i < 33; i++) {
        (*myHashTable).split(i, 2);
    }
    std::cout << "Printing the hash table after splitting...." << std::endl;
    std::cout << myHashTable << std::endl;
   
    
}
