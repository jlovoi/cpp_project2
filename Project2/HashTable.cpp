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
    vector<list<char>*>* vect = new vector<list<char>*>(0);
public:
    HashTable(int n);
    int hashInt(T input);
    list<char>* createLinkedList(char* input);
    void insert(T input);
    bool find(T str);
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
list<char>* HashTable<T>::createLinkedList(char* name) {
    list<char>* nameList = new list<char>();
    
    // insert each element of the char array into the linked list
    for (int i = 0; i < char_traits<char>::length(name); i++) {
        nameList->push_back(name[i]);
    }
    
    return nameList;
}

template<class T>
void HashTable<T>::insert(T input) {
    int hashInt = HashTable::hashInt(input);
    list<char>* linkedList = HashTable::createLinkedList(input);
    
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

template<class T>
bool HashTable<T>::find(T str) {
    int hashInt = HashTable::hashInt(str);
    list<char>* toFind = HashTable::createLinkedList(str);
    
//    auto it = toFind->begin();
//    for (auto it = toFind->begin(); it != toFind->end();) {
//        cout << *it << " " << sizeof(it) << endl;
//        advance(it, 1);
//    }
    
    int i = hashInt;
    while (i < vect->size()) {
        cout << "Checking at " << i << endl;
        if (toFind == (*vect)[i]) {
            return true;
        }
        else {
            i++;
            continue;
        }
    }
    
    for (int i = 0; i < char_traits<char>::length(str); i++) {
        cout << "TEST: " << toFind->front() << endl;
        cout << "TEST: " << (*vect)[32]->front() << endl;
        toFind->pop_front();
        (*vect)[32]->pop_front();
    }
    return false;
}
