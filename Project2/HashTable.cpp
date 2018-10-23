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


template<class T>
class HashTable {
protected:
    std::vector<std::list<char>*>* vect = new std::vector<std::list<char>*>(0);
public:
    HashTable();
    HashTable(int n);
    int hashInt(T input);
    std::list<char>* createLinkedList(char* input);
    void insert(T input);
    bool find(T str);
    int findIndex(T str);
    void remove(T str);
    void split(int vInd, int lInd);
    ~HashTable();
};

template<class T>
HashTable<T>::HashTable() {
}

template<class T>
HashTable<T>::HashTable(int n) {
}

template<class T>
int HashTable<T>::hashInt(T input) {
    int val = input[0] - 'A';
    return val;
}

template<class T>
std::list<char>* HashTable<T>::createLinkedList(char* name) {
    std::list<char>* nameList = new std::list<char>();
    
    // insert each element of the char array into the linked list
    for (int i = 0; i < std::char_traits<char>::length(name); i++) {
        nameList->push_back(name[i]);
    }
    
    return nameList;
}

template<class T>
void HashTable<T>::insert(T input) {
    int hashInt = HashTable::hashInt(input);
    std::list<char>* linkedList = HashTable::createLinkedList(input);
    
    int i = hashInt;
    while (true) {
        // If hashInt is greater than the capacity of the vector, resize the vector to hashInt and insert the linkedlist at hashInt
        if (i >= vect->size()) {
            vect->resize(i, NULL);
            (*vect).push_back(linkedList);
            std::cout << "Added " << input << " to vect from if at " << i << std::endl;
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
            std::cout << "Added " << input << " list to vect from else at " << i << std::endl;
            i++;
            break;
        }
    }
}

template<class T>
bool HashTable<T>::find(T str) {
    int hashInt = HashTable::hashInt(str);
    std::list<char>* toFind = HashTable::createLinkedList(str);
    bool booly = false;
  
// I wrote this mess because the '==' operator for lists did not seem to be working with my lists.
// I tested compared the size of each list in addition to corresponding elements in each list, all of which returned true
// However the '==' operator always returned false, so I decided to just make it myself
    int i = hashInt;
    while (i < vect->size() && booly == false && (*vect)[i] != NULL) {
        if (toFind->size() == (*vect)[i]->size()) {
            std::list<char>* tempList = new std::list<char>(*(*vect)[i]);
            for (int x = 0; x < std::char_traits<char>::length(str); x++) {
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
    std::list<char>* toFind = HashTable::createLinkedList(str);
    bool booly = false;
    int retVal = -1;
    
    int i = hashInt;
    while (i < vect->size() && booly == false) {
        if (toFind->size() == (*vect)[i]->size()) {
            std::list<char>* tempList = new std::list<char>(*(*vect)[i]);
            for (int x = 0; x < std::char_traits<char>::length(str); x++) {
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
        std::cout << "removing " << str << " from position " << pos << std::endl;
        delete ((*vect)[pos - 1]);
        (*vect)[pos - 1] = NULL;
    }
}

template<class T>
void HashTable<T>::split(int vInd, int lInd) {
    std::cout << "Splitting " << vInd << std::endl;
    if ((*vect)[vInd] == NULL) {
        return;
    }
    std::list<char>* toSplit = (*vect)[vInd];
    std::list<char>* split = new std::list<char>();
    auto it = toSplit->begin();
    advance(it, lInd);
    
    (*split).splice((*split).begin(), (*toSplit), it, toSplit->end());
    (*vect)[vInd]->resize(lInd);
    
    vInd++;
    while ((*split).size() > 0) {
        // If vInd is greater than the capacity of the vector, resize the vector to vInd
        if (vInd > vect->size()) {
            std::cout << vInd << " >= " << vect->size() << std::endl;
            vect->resize(vInd, NULL);
            continue;
        }
        if ((*vect)[vInd] == NULL) {
            (*vect)[vInd] = new std::list<char>();
            (*vect)[vInd]->push_front((*split).front());
            std::cout << "1:Just added " << (*split).front() << " at " << vInd << std::endl;
            (*split).pop_front();
            continue;
        }
        // If this space contains less than lInd elements, add a char
        else if ((*vect)[vInd]->size() < lInd) {
            (*vect)[vInd]->push_front((*split).front());
            std::cout << "2:Just added " << (*split).front() << " at " << vInd << std::endl;
            (*split).pop_front();
            continue;
        }
        else {
            vInd++;
        }
    }
}

template<class T>
HashTable<T>::~HashTable<T>() {
    for (int i = 0; i < vect->capacity(); i++) {
        delete (*vect)[i];
    }
    delete vect;
}
