//
//  main.cpp
//  Project2
//
//  Created by Joseph Lovoi on 10/17/18.
//  Copyright © 2018 Joseph Lovoi. All rights reserved.
//

#include "HashTable.cpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    HashTable<char*>* ht = new HashTable<char*>(20);
    
    std::list<char*>* name = ht->createLinkedList("Joseph");
}
