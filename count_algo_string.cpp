/*
*   Read a sequence of ints into a vector. Count how many elements have a given value.
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<string> names;
    names.push_back("Allen");
    names.push_back("Siera");
    names.push_back("Jenny");
    names.push_back("Allen");
    names.push_back("James");
    names.push_back("Allen");


    cout << " Number of times Allen appear in the list is : " << count(names.begin(), names.end(), "Allen") << endl;

    return 0;
}
