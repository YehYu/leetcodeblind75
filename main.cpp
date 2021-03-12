#include "Solution.cpp"
#include "FastSolution.cpp"
#include <stdio.h>
#include <iostream>
using namespace std;
typedef Solution::ListNode ListNode;
typedef Solution::TreeNode TreeNode;

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

    // vector<int> nums = {3,2,1,0,4};
    // cout << Solution::canJump(nums);

    // vector<vector<int>> intervals  = {{1, 4}, {4, 5}};
    // for (vector<int> interval: FastSolution::merge(intervals))
    //     cout << interval[0]<<", "<<interval[1]<<endl;

    //57. Insert Interval
    // vector<vector<int>> intervals  = {{1,5}};
    // vector<int> newInterval = {2, 7};
    // for (vector<int> interval: Solution::insert(intervals, newInterval))
    //     cout << interval[0]<<", "<<interval[1]<<endl;

    //62. Unique
    //cout << FastSolution::uniquePaths(3,7);

    //70. Climbing Stairs
    //cout << FastSolution::climbStairs(7);

    //73. Set Matrix Zeroes
    // vector<vector<int>> matrix = {{1,2,3,4},{5,0,7,8},{0,10,11,12},{13,14,15,0}};
    // Solution::setZeroes(matrix);
    // for (vector<int> m : matrix)
    // {
    //     for (int i : m)
    //     {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }

    // //76. Minimum Window Substring
    // string s = "ADOBECODEBANC",t = "ABC"
    // cout << Solution::minWindow(s, t);

    //79. Word Search
    // vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    // string word = "ABCCED";

    //91. Decode Ways
    // string s = "1123";
    // cout << FastSolution::numDecodings(s);

    //98. Validate Binary Search Tree
    // TreeNode *root = new TreeNode(3, new TreeNode(1, new TreeNode(0), new TreeNode(2)), new TreeNode(5, new TreeNode(4), new TreeNode(6)));
    // cout << Solution::isValidBST(root);

    //100. Same Tree
    // TreeNode *q = new TreeNode(1, new TreeNode(2), nullptr);
    // TreeNode *p = new TreeNode(1, nullptr, new TreeNode(2));
    // cout << Solution::isSameTree(q, p);

    //102. Binary Tree Level Order Traversal
    TreeNode *root = new TreeNode(1, new TreeNode(2, new TreeNode(3, new TreeNode(4, new TreeNode(5), nullptr), nullptr), nullptr),nullptr);
    for (vector<int> m : Solution::levelOrder(root))
    {
        for (int i : m)
            cout << i << " ";

        cout << endl;
    }

    return 0;
}