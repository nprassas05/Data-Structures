//
//  ArrayList.h
//  
//
//  Created by Elena PRASSAS on 12/24/16.
//
//

#ifndef _ArrayList_
#define _ArrayList_

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class ArrayList {
private:
    int* myElements;
    int mySize;
    int myCapacity;
    void checkResize();
    
public:
    // constructor
    ArrayList();
    
    //destructor
    ~ArrayList();
    
    // member functions
    void add(int value);
    //void clear();
    int get(int index) const;
    void insert(int index, int value);
    bool isEmpty() const;
    void remove(int index);
    void set(int index, int value);
    int size() const;
    //void debug() const;    
    
    
};

// overloaded operators
ostream& operator <<(ostream& out, ArrayList& list);


#endif
