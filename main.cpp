#include "Solution.cpp"
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    vector<int> v = {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
    for (vector<int> vr : Solution::threeSum(v))
    {
        cout << " threeSum : " << endl;
        for (int r : vr)
            cout << r << endl;
    }
    return 0;
}