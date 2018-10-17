//
//  HashTable.cpp
//  Project2
//
//  Created by Joseph Lovoi on 10/17/18.
//  Copyright © 2018 Joseph Lovoi. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

template<class T>
class HashTable {
protected:
    vector<T> vect;
public:
    HashTable(int n);
    int hashInt(T input);
    list<T>* createLinkedList(T input);
};

template<class T>
HashTable<T>::HashTable(int n) {
    vect.reserve(n);
}

template<class T>
int HashTable<T>::hashInt(T input) {
    int val = input[0] - 'A';
    return val;
}

template<class T>
list<T>* HashTable<T>::createLinkedList(T input) {
    list<T>* nameList = new list<T>();
    
    // insert each element of the char array into the linked list
    int i = 0;
    while (input[i] != '\0') {
        nameList->push_back(&input[i]);
        ++i;
    }
    return nameList;
}
