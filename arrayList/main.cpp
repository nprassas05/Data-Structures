//
//  main.cpp
//  arrayList
//
//  Created by Elena PRASSAS on 12/24/16.
//  Copyright (c) 2016 manhattan college. All rights reserved.
//

#include <iostream>
#include "ArrayList.h"
using namespace std;

int main(int argc, const char * argv[]) {
    ArrayList a;
    
    a.add(5);
    a.add(10);
    a.add(15);
    
    cout << a << endl;
    
    return 0;
}
