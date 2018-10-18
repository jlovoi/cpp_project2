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
    vector<list<T>*>* vect = new vector<list<T>*>(0);
public:
    HashTable(int n);
    int hashInt(T input);
    list<T>* createLinkedList(T input);
    void insert(T input);
};

template<class T>
HashTable<T>::HashTable(int n) {
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

template<class T>
void HashTable<T>::insert(T input) {
    int hashInt = HashTable::hashInt(input);
    list<T>* linkedList = HashTable::createLinkedList(input);
    
    cout << "NEW HASH: " << hashInt <<endl;
    int i = hashInt;
    while (true) {
        // If hashInt is greater than the capacity of the vector, resize the vector to hashInt and insert the linkedlist at hashInt
        if (i >= vect->size()) {
            vect->resize(i, NULL);
            (*vect).push_back(linkedList);
            cout << "Added " << input << " to vect from if at " << i << endl;
            break;
        }
        // If the space at it is taken, increment it and go through loop again
        else if ((*vect)[i] != NULL) {
            i++;
            cout << "inc i to " << i << endl;
            continue;
        }
        // If it is null, then insert at that position
        if ((*vect)[i] == NULL) {
            (*vect)[i] = linkedList;
            cout << "Added " << input << " list to vect from else at " << i << endl;
            i++;
            break;
        }
    }
}
