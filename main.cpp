#include "Solution.cpp"
#include "FastSolution.cpp"
#include <stdio.h>
#include <iostream>
using namespace std;
typedef Solution::ListNode ListNode;
typedef Solution::TreeNode TreeNode;
typedef FastSolution::TreeNode FTreeNode;

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
    // TreeNode *root = new TreeNode(1, new TreeNode(2, new TreeNode(3, new TreeNode(4, new TreeNode(5), nullptr), nullptr), nullptr),nullptr);
    // for (vector<int> m : Solution::levelOrder(root))
    // {
    //     for (int i : m)
    //         cout << i << " ";

    //     cout << endl;
    // }

    //104. Maximum Depth of Binary Tree
    // TreeNode *root = new TreeNode(1, new TreeNode(2, new TreeNode(3, new TreeNode(4, new TreeNode(5), nullptr), nullptr), nullptr),nullptr);
    // cout <<Solution::maxDepth(root);

    ////105. Construct Binary Tree from Preorder and Inorder Traversal
    ////Input: preorder = [ 3, 9, 20, 15, 7 ], inorder = [ 9, 3, 15, 20, 7 ] Output : [ 3, 9, 20, null, null, 15, 7 ]
    // vector<int> preorder = {1,2,3};
    // vector<int> inorder = {1,3,2};
    // for (vector<int> m : FastSolution::levelOrder(FastSolution::buildTree(preorder, inorder)))
    // {
    //     for (int i : m)
    //         cout << i << " ";

    //     cout << endl;
    // }

    // //121. Best Time to Buy and Sell Stock
    // vector<int> price = {7,1,5,3,6,4};
    // cout << Solution::maxProfit(price);

    // //124. Binary Tree Maximum Path Sum
    // FTreeNode *root = new FTreeNode(-10, new FTreeNode(9), new FTreeNode(20, new FTreeNode(15), new FTreeNode(7)));
    // cout <<FastSolution::maxPathSum(root);

    // //125. Valid Palindrome
    // string s = "race a car";
    // cout <<Solution::isPalindrome(s);

    // //128. Longest Consecutive Sequence
    // vector<int>nums = {4,0,-4,-2,2,5,2,0,-8,-8,-8,-8,-1,7,4,5,5,-4,6,6,-3};
    // cout <<FastSolution::longestConsecutive(nums);


    //133. Clone Graph
    typedef Solution::Node Node;
    Node *node1 = new Node(1);
    // Node *node2 = new Node(2);
    // Node *node3 = new Node(3);
    // Node *node4 = new Node(4);
    // node1->neighbors = {node2, node4};
    // node2->neighbors = {node1, node3};
    // node3->neighbors = {node2, node4};
    // node4->neighbors = {node1, node3};
    Node *cloneNode =  Solution::cloneGraph(node1);

    return 0;
}