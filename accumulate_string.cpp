/*
*   Read a sequence of string into a vector. Concatenate using accumulate.
*/
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int main()
{
    vector<string> names;
    names.push_back(" Vivek");
    names.push_back(" Bhadra");

    /*
        Note the below will not work
        string fullName = accumulate(names.begin(), names.end(), " ");
        The third parameter here is a string literal not a string object.
        Hence the type of the other operands also becomes string literals
        rather than string object. Hence the program will not compile.
    */
    string fullName = accumulate(names.begin(), names.end(), string(" "));

    cout << " Full name of the person is : " << fullName << endl;

    return 0;
}
