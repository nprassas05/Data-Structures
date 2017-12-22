//
//  ArrayList.cpp
//  
//

#include "ArrayList.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ArrayList::ArrayList() {
    myElements = new int[10]();
    mySize = 0;
    myCapacity = 10;
}

ArrayList::~ArrayList() {
    delete[] myElements;
}

void ArrayList::add(int value) {
    checkResize();
    myElements[mySize] = value;
    mySize++;
}

void ArrayList::insert(int index, int value) {
    checkResize();
    for (int i = mySize; i > index; i--) {
        myElements[i] = myElements[i - 1];
    }
    
    myElements[index] = value;
    mySize++;
}

void ArrayList::remove(int index) {
    for (int i = index; i < mySize; i++) {
        myElements[i] = myElements[i + 1];
    }
}

void ArrayList::set(int index, int value)
{
    myElements[index] = value;
}

int ArrayList::size() const {
    return mySize;
}

bool ArrayList::isEmpty() const {
    return mySize == 0;
}

int ArrayList::get(int index) const {
    return myElements[index];
}

void ArrayList::checkResize() {
    if (mySize == myCapacity) {
        int* bigger = new int[2 * myCapacity];
        for (int i = 0; i < mySize; i++) {
            bigger[i] = myElements[i];
        }
        delete[] myElements;
        myElements = bigger;
    }
}

ostream& operator <<(ostream& out, ArrayList& list)
{
    out << "{";
    
    for (int i = 0; i < list.size(); i++) {
        out << list.get(i) << ", ";
    }
    
    out << "}";
    return out;
}
