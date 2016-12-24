//
//  main.cpp
//  avgFile
//
//  Created by Elena PRASSAS on 12/23/16.
//  Copyright (c) 2016 manhattan college. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void averageValueInFile(string filename, double& result);


int main(int argc, const char * argv[]) {
    double avg;
    averageValueInFile("/Users/ELENA/Documents/avgFile/avgFile/data.txt", avg);
    cout << "Average value in file: " << avg << endl;
    
    return 0;
}

void averageValueInFile(string filename, double& result)
{
    /* Keep track of how many values were read from the file */
    int count = 0;
    
    /* Initialize the result to 0 before any values are read */
    result = 0.0;
    
    /* Read every value in the file */
    double d;
    ifstream input;
    input.open(filename);
    
    while (input >> d) {
        count++;
        result += d;
    }
    result = result / count;
    
}
