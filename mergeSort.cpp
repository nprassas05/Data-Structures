#include <iostream>
#include <vector>
using namespace std;

void mergeSort(vector<int> &v);
vector<int> merge(vector<int> &a, vector<int> &b);

int main()
{
    vector<int> v = {43, 12, 76, 34, 15, 8, 9};
    mergeSort(v);
    
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    
    return 0;
}

void mergeSort(vector<int> &v) {
    if (v.size() > 1) {
        int middle = (int) v.size() / 2;
        cout << "middle = " << middle << endl;
        vector<int> v1(v.begin(), v.begin() + middle);
        vector<int> v2(v.begin() + middle, v.end());
        
        /* Run mergesort on the two subvectors and then merge them */
        mergeSort(v1);
        mergeSort(v2);
        v = merge(v1, v2);
        
    }
}

/* merge two sorted vectors */
vector<int> merge(vector<int> &a, vector<int> &b)
{
    vector<int> c;
    while (!a.empty() && !b.empty()) {
        if (a[0] < b[0]) {
            c.push_back(a[0]);
            a.erase(a.begin());
        }
        else {
            c.push_back(b[0]);
            b.erase(b.begin());
        }
    }
    
    /* if vector a is empty, add the rest of b to c,
     and if b is empty, add the rest of a to c
     */
    if (a.empty()) {
        while (!b.empty()) {
            c.push_back(b[0]);
            b.erase(b.begin());
        }
    }
	 		
    if (b.empty()) {
        while (!a.empty()) {
            c.push_back(a.front());
            a.erase(a.begin());
        }
    }
    
    return c;
}