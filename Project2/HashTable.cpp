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
    int findIndex(T str);
    void remove(T str);
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
    bool booly = false;
  
// I wrote this mess because the '==' operator for lists did not seem to be working with my lists.
// I tested compared the size of each list in addition to corresponding elements in each list, all of which returned true
// However the '==' operator always returned false, so I decided to just make it myself
    int i = hashInt;
    while (i < vect->size() && booly == false && (*vect)[i] != NULL) {
        if (toFind->size() == (*vect)[i]->size()) {
            list<char>* tempList = new list<char>(*(*vect)[i]);
            for (int x = 0; x < char_traits<char>::length(str); x++) {
                char find = toFind->front();
                char v = tempList->front();
                if (find == v) {
                    booly = true;
                    toFind->pop_front();
                    tempList->pop_front();
                    continue;
                }
                else {
                    booly = false;
                    i++;
                    break;
                }
            }
        }
        else {
            i++;
            continue;
        }
    }
    return booly;
}
 // this is the same as the find() method, but returns the index of the vect, for ease of removal
template<class T>
int HashTable<T>::findIndex(T str) {
    int hashInt = HashTable::hashInt(str);
    list<char>* toFind = HashTable::createLinkedList(str);
    bool booly = false;
    int retVal = -1;
    
    int i = hashInt;
    while (i < vect->size() && booly == false) {
        if (toFind->size() == (*vect)[i]->size()) {
            list<char>* tempList = new list<char>(*(*vect)[i]);
            for (int x = 0; x < char_traits<char>::length(str); x++) {
                char find = toFind->front();
                char v = tempList->front();
                if (find == v) {
                    booly = true;
                    retVal = i;
                    toFind->pop_front();
                    tempList->pop_front();
                    continue;
                }
                else {
                    retVal = -1;
                    booly = false;
                    i++;
                    break;
                }
            }
        }
        else {
            i++;
            continue;
        }
    }
    return retVal;
}

template<class T>
void HashTable<T>::remove(T str) {
    bool isListed = HashTable::find(str);
    int pos = HashTable::findIndex(str);
    
    if (isListed) {
        cout << "removing " << str << " from position " << pos << endl;
        delete ((*vect)[pos - 1]);
        (*vect)[pos - 1] = NULL;
    }
}
