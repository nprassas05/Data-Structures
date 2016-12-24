//
//  main.cpp
//  permutation
//
//  Created by Niko PRASSAS on 12/23/16.
//  Copyright (c) 2016 manhattan college. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

void permute(string);
void permuteHelper(string, string);

int main(int argc, const char * argv[]) {
    
    permute("ab");
    return 0;
}

void permuteHelper(string s, string chosen)
{
    if (s == "")
        cout << chosen << endl;
    else {
        // loop over the letters in s
        for (int i = 0; i < s.length(); i++) {
            // choose
            char c = s[i];
            chosen += c;
            s.erase(i, 1);
            
            // explore
            permuteHelper(s, chosen);
            
            // un-choose
            s.insert(i, 1, c);
            chosen.erase(chosen.length() - 1, 1);
            
        }
    }
}

void permute(string s)
{
    permuteHelper(s, "");
}