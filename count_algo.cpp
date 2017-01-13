/*
*   Read a sequence of ints into a vector. Count how many elements have a given value.
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums;
    nums.push_back(10);
    nums.push_back(50);
    nums.push_back(5);
    nums.push_back(10);
    nums.push_back(20);

    cout << " Number of times 10 appear in the list is : " 
	 << count(nums.begin(), nums.end(), 10) << endl;

    return 0;
}
