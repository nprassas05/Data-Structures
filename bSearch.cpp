#include <iostream>
#include <vector>

using namespace std;

int recursiveBinarySearch(vector<int>&, int, int, int);

int main()
{
    vector<int> vec = {2, 5, 12, 18, 21, 25, 30};

    int searchNum;
    cout << "Enter a number to search for (Enter -9999 to quit): ";
    cin >> searchNum;

    while(searchNum != -9999) {
        int result = recursiveBinarySearch(
            vec, 0, vec.size() - 1, searchNum);
        if (result == -1)
            cout << "That number is not present" << endl;
        else {
            cout << "That nuber is located at ";
            cout << "index " << result << endl;
        }

    cout << "Enter a number to search for (Enter -9999 to quit): ";
    cin >> searchNum;

    }

    return 0;
}



int recursiveBinarySearch(vector<int>& v, int first, 
            int last, int target) {
    if (first > last)
        return -1;
    
    int middleIndex = (first + last) / 2;
    int middleElement = v[middleIndex];
    
    if (middleElement == target)
        return middleIndex;
    else if (middleElement > target)
        return recursiveBinarySearch(v, first, middleIndex - 1, target);
    else if (middleElement < target)
        return recursiveBinarySearch(v, middleIndex + 1, last, target);
}
