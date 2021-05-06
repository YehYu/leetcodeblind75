#include "Solution.cpp"
#include "FastSolution.cpp"
#include <stdio.h>
#include <iostream>
using namespace std;

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
    // TreeNode *root = new TreeNode(-10, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    // cout <<FastSolution::maxPathSum(root);

    // //125. Valid Palindrome
    // string s = "race a car";
    // cout <<Solution::isPalindrome(s);

    // //128. Longest Consecutive Sequence
    // vector<int>nums = {4,0,-4,-2,2,5,2,0,-8,-8,-8,-8,-1,7,4,5,5,-4,6,6,-3};
    // cout <<FastSolution::longestConsecutive(nums);

    // //133. Clone Graph
    // typedef Solution::Node Node;
    // Node *node1 = new Node(1);
    // Node *node2 = new Node(2);
    // Node *node3 = new Node(3);
    // Node *node4 = new Node(4);
    // node1->neighbors = {node2, node4};
    // node2->neighbors = {node1, node3};
    // node3->neighbors = {node2, node4};
    // node4->neighbors = {node1, node3};
    // Node *cloneNode =  Solution::cloneGraph(node1);

    // //139. Word Break
    // string s = "applepenapple";
    // vector<string> wordDict = {"apple","pen"};
    // cout<<Solution::wordBreak(s, wordDict);

    // //141. Linked List Cycle
    // //[3,2,0,-4], , pos = 1
    // ListNode *temp, *temp2;
    // ListNode* node = new ListNode(3, (temp = new ListNode(2,new ListNode(0, (temp2 = new ListNode(-4))))));
    // temp2->next = temp;
    // cout<<Solution::hasCycle(node);

    // //143. Reorder List
    // ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    // Solution::reorderList(head);

    // //152. Maximum Product Subarray
    // vector<int>nums{2,-5,-2,-4,3};
    // cout<<Solution::maxProduct(nums);

    // //153. Find Minimum in Rotated Sorted Array
    // vector<int>nums{3,4,5,1,2};
    // cout<<Solution::findMin(nums);

    // //190. Reverse Bits
    // cout<<Solution::reverseBits(43261596);

    // //191. Number of 1 Bits
    // uint32_t num = 0x0000000b;
    // cout<<Solution::hammingWeight(num);

    // //198. House Robber
    // vector<int>nums = {2,7,9,3,1};
    // cout<<FastSolution::rob(nums);

    // //200. Number of Islands
    // vector<vector<char>> grid = {
    //     {'1', '1', '0', '0', '0'},
    //     { '1', '1', '0', '0', '0' },
    //     { '0', '0', '1', '0', '0' },
    //     { '0', '0', '0', '1', '1' }
    // };
    // cout<<FastSolution::numIslands(grid);

    // //206. Reverse Linked List
    // ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    // head = Solution::reverseList(head);

    // //207. Course Schedule
    // int numCourses = 8;
    // vector<vector<int>> prerequisites = {{1,0},{2,6},{1,7},{6,4},{7,0},{0,5}};
    // cout<<Solution::canFinish(numCourses, prerequisites);

    // //208. Implement Trie (Prefix Tree)
    // Solution::testTrie();

    // //211. Design Add and Search Words Data Structure
    // Solution::testWordDictionary();

    // //212. Word Search II
    // //Output: ["eat","oath"]
    // vector<vector<char>> board = {{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
    // vector<string> words = {"oath", "pea", "eat", "rain"};
    // for (string s : Solution::findWords(board, words))
    //     cout << s << endl;

    // //213. House Robber II
    // vector<int>nums = {1,2,3,0};
    // cout<<FastSolution::rob2(nums);

    // //217. Contains Duplicate
    // vector<int>nums = {1,2,3,1};
    // cout<<Solution::containsDuplicate(nums);

    //226. Invert Binary Tree
    //In [4,2,7,1,3,6,9], out[4,7,2,9,6,3,1]
    TreeNode *root = new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)), new TreeNode(7, new TreeNode(6), new TreeNode(9)));
    cout<<root<<endl;;
    cout<<Solution::invertTree(root);

    return 0;
}