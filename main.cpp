#include "Solution.cpp"
#include "FastSolution.cpp"
#include <stdio.h>
#include <iostream>
using namespace std;
typedef Solution::ListNode ListNode;

int main()
{
    /*
    ListNode *l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode *l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode *l3 = new ListNode(2, new ListNode(6));
    vector<ListNode*> list;
    list.push_back(l1);
    list.push_back(l2);
    list.push_back(l3);
    ListNode *A = Solution::mergeKLists(list);
    while (A)
    {
        cout << A->val << endl;
        A = A->next;
    }
    */
    //vector<int> v = {4, 5, 6, 7, 0, 1, 2};
    //cout << Solution::search(v, 0) << endl;
    /*
    vector<int> v = {2, 3, 5};
    for (vector<int> a : Solution::combinationSum(v, 8))
    {
        cout << "anser : " << endl;
        for (int i : a)
            cout << i << endl;
    }
*/
    /*  
  vector<vector<int>> v = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
     Solution::rotate(v);
    for (vector<int> a : v)
    {
        for (int i : a)
            cout << i << " ";
        cout << endl;
    }
    */

    // vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    // for (vector<string> a : Solution::groupAnagrams(strs))
    // {
    //     for (string i : a)
    //         cout << i;
    //     cout << endl;
    // }

    // vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    // cout << Solution::maxSubArray(nums) << endl;

    // vector<vector<int>> order = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // for (int a : Solution::spiralOrder(order))
    //     cout << a;
    // cout << endl;

    vector<int> nums = {3,2,1,0,4};
    cout << Solution::canJump(nums);

    return 0;
}