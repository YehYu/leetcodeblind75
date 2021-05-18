
#include "data.h"
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
#include <limits.h>
#include <iostream>
using namespace std;

class FastSolution
{
public:
    static string longestPalindrome(string s)
    {
        int max = 0;
        string res = "";
        int curr = 0;

        while (curr < s.size())
        {
            int start = curr;
            int end = curr;

            while (end < s.size() && s[end] == s[end + 1])
                end++;
            curr = end + 1;

            while (start > 0 && end < s.size() && s[start - 1] == s[end + 1])
            {
                start--;
                end++;
            }

            if (end - start + 1 > max)
            {
                max = end - start + 1;
                res = s.substr(start, max);
            }
        }
        return res;
    }

    static int maxArea(vector<int> &height)
    {
        int maxy = INT_MIN;
        int miny;
        int i = 0, j = height.size() - 1;
        while (i < j)
        {
            miny = min(height[i], height[j]);
            maxy = max(maxy, miny * (j - i));
            if (height[i] < height[j])
                ++i;
            else
                --j;
        }
        return maxy;
    }

    static vector<vector<int>> threeSum(vector<int> &nums)
    {

        int *s;                                         // start pointer.
        int *e;                                         // end pointer.
        int fix = 0, exp = 0, sum = 0, n = nums.size(); // Initialize some variables.
        vector<vector<int>> v;                          // 2-D vector which has to returned.

        // corner case.
        if (nums.size() < 3)
            return v;

        // sort the vector becoz I wanna use 2-pointer technique.
        sort(nums.begin(), nums.end());

        // Loop through entire nums.
        for (int i = 0; i < nums.size(); i++)
        {
            // Temporary vector to feed a vector to v.
            vector<int> vtemp(3, 0);

            // Jump duplicates in nums.
            if (i != 0 && (nums[i - 1] == nums[i]))
                continue;

            fix = nums[i];    // fix one number from nums.
            exp = -1 * fix;   // expected value from 2-pointer.
            s = &nums[i + 1]; // Initialize start pointer.
            e = &nums[n - 1]; // Initialize end pointer.

            // 2-Pointer technique to find expected value.
            while (s < e)
            {
                sum = *s + *e;

                // Case-1.
                if (sum == exp)
                {
                    vtemp[0] = nums[i];
                    vtemp[1] = *s;
                    vtemp[2] = *e;
                    v.push_back(vtemp);
                    // Main condition to remove duplicates.
                    s++;
                    while (s < e && *s == *(s - 1))
                        s++;
                }

                // Case-2.
                else if (sum < exp)
                    s++;

                // Case-3.
                else
                    e--;
            }
            // 2-Pointer ends here!.

        } // For loop end here!.

        return v;
    }

    //19. Remove Nth Node From End of List
    static ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *prev = new ListNode(0);
        prev->next = head;
        ListNode *k = prev;
        ListNode *curr = head;
        for (int i = 0; i < n; i++)
        {
            curr = curr->next;
        }
        while (curr)
        {
            prev = prev->next;
            curr = curr->next;
        }
        prev->next = prev->next->next;
        return k->next;
    }

    //20. Valid Parentheses
    static bool isValid(string s)
    {
        int indexOfLastOpen = -1;
        for (int i = 0; i < s.length(); ++i)
        {
            switch (s[i])
            {
            case '(':
            {
                indexOfLastOpen++;
                s[indexOfLastOpen] = '(';
                break;
            }
            case '{':
            {
                indexOfLastOpen++;
                s[indexOfLastOpen] = '{';
                break;
            }
            case '[':
            {
                indexOfLastOpen++;
                s[indexOfLastOpen] = '[';
                break;
            }
            case ')':
            {
                if (indexOfLastOpen >= 0)
                {
                    if (s[indexOfLastOpen] != '(')
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
                indexOfLastOpen--;
                break;
            }
            case '}':
            {
                if (indexOfLastOpen >= 0)
                {
                    if (s[indexOfLastOpen] != '{')
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
                indexOfLastOpen--;
                break;
            }
            case ']':
            {
                if (indexOfLastOpen >= 0)
                {
                    if (s[indexOfLastOpen] != '[')
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
                indexOfLastOpen--;
                break;
            }
            }
        }

        return indexOfLastOpen >= 0 ? false : true;
    }

    //21. Merge Two Sorted Lists
    static ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        // most Discuss "recursion"
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        if (l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }

    //23. Merge k Sorted Lists
    static ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return NULL;
        int len = lists.size();
        while (len > 1)
        {
            for (int i = 0; i < len / 2; ++i)
            {
                lists[i] = mergeTwoLists(lists[i], lists[len - 1 - i]);
            }
            len = (len + 1) / 2;
        }

        return lists.front();
    }

    static int search(vector<int> &nums, int target)
    {
        int start = 0, end = nums.size() - 1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] >= nums[start])
            {
                if (target >= nums[start] && nums[mid] >= target)
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            else if (nums[mid] <= nums[end])
            {
                if (nums[mid] <= target && target <= nums[end])
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }

    //combinationSum
    static vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> cur;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, cur, ans);
        return ans;
    }
    static void dfs(vector<int> &candidates, int target, int s, vector<int> &cur, vector<vector<int>> &ans)
    {
        if (target == 0)
        {
            ans.push_back(cur);
            return;
        }
        for (int i = s; i < candidates.size(); i++)
        {
            if (candidates[i] > target)
                break;
            cur.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, cur, ans);
            cur.pop_back();
        }
    }
    ////

    static void rotate(vector<vector<int>> &matrix)
    {
        unsigned int N = matrix.size();
        for (int i = 0; i < (N + 1) / 2; ++i)
        {
            for (int j = 0; j < N / 2; ++j)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[N - 1 - j][i];
                matrix[N - 1 - j][i] = matrix[N - 1 - i][N - 1 - j];
                matrix[N - 1 - i][N - 1 - j] = matrix[j][N - 1 - i];
                matrix[j][N - 1 - i] = temp;
            }
        }
    }

    static int maxSubArray(vector<int> &nums)
    {
        int result = nums[0];
        int tempR = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            tempR += nums[i];
            tempR = (nums[i] > tempR) ? nums[i] : tempR;
            result = (result > tempR) ? result : tempR;
        }
        return result;
    }

    //Using Divide and Conquer method
    static int maxSubArrayUsingDivideAndConquer(vector<int> &nums)
    {
        return maxSubArrayHelperFunction(nums, 0, nums.size() - 1);
    }
    static int maxSubArrayHelperFunction(vector<int> &nums, int left, int right)
    {
        if (right == left)
            return nums[left];
        int middle = (left + right) / 2;
        int leftans = maxSubArrayHelperFunction(nums, left, middle);
        int rightans = maxSubArrayHelperFunction(nums, middle + 1, right);
        int leftmax = nums[middle];
        int rightmax = nums[middle + 1];
        int temp = 0;
        for (int i = middle; i >= left; i--)
        {
            temp += nums[i];
            if (temp > leftmax)
                leftmax = temp;
        }
        temp = 0;
        for (int i = middle + 1; i <= right; i++)
        {
            temp += nums[i];
            if (temp > rightmax)
                rightmax = temp;
        }
        return max(max(leftans, rightans), leftmax + rightmax);
    }

    static vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        if (matrix.size() == 0)
            return ans;
        int r1 = 0, r2 = matrix.size() - 1;
        int c1 = 0, c2 = matrix[0].size() - 1;
        while (r1 <= r2 && c1 <= c2)
        {
            for (int c = c1; c <= c2; c++)
                ans.push_back(matrix[r1][c]);
            for (int r = r1 + 1; r <= r2; r++)
                ans.push_back(matrix[r][c2]);
            if (r1 < r2 && c1 < c2)
            {
                for (int c = c2 - 1; c > c1; c--)
                    ans.push_back(matrix[r2][c]);
                for (int r = r2; r > r1; r--)
                    ans.push_back(matrix[r][c1]);
            }
            r1++;
            r2--;
            c1++;
            c2--;
        }
        return ans;
    }

    //55. Jump Game
    static bool canJump(vector<int> &nums)
    {
        if (nums.size() == 1)
            return true;
        int Good_index = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if ((i + nums[i]) >= Good_index)
                Good_index = i;
            if (Good_index <= nums[0])
                return true;
        }
        return false;
    }

    //56. Merge Intervals
    static vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;

        // sort based on start
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &A, const vector<int> &B) { return A[0] < B[0]; });

        // check and merge
        for (const vector<int> &i : intervals)
        {
            if (!res.empty() && i[0] <= res.back()[1])
                res.back()[1] = max(res.back()[1], i[1]);
            else
                res.emplace_back(i);
        }

        return res;
    };

    //57. Insert Interval
    static vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        if (intervals.empty())
            return {newInterval};

        vector<vector<int>> result;
        int insertIndex = 0;
        for (const vector<int> &interval : intervals)
        {
            if (interval[1] < newInterval[0])
            {
                insertIndex++;
                result.emplace_back(interval);
            }
            else if (interval[0] > newInterval[1])
                result.emplace_back(interval);
            else
            {
                newInterval[0] = interval[0] < newInterval[0] ? interval[0] : newInterval[0];
                newInterval[1] = interval[1] > newInterval[1] ? interval[1] : newInterval[1];
            }
        }
        result.insert(result.begin() + insertIndex, newInterval);
        return result;
    }

    //62. Unique Paths
    static int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                dp[i][j] = (i == 0 || j == 0) ? 1 : (dp[i - 1][j] + dp[i][j - 1]);

        return dp[m - 1][n - 1];
    }

    //70. Climbing Stairs
    static int climbStairs(int n)
    {
        if (n == 1)
            return 1;

        int first = 1;
        int second = 2;
        for (int i = 3; i <= n; i++)
        {
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }

    //73. Set Matrix Zeroes
    static void setZeroes(vector<vector<int>> &matrix)
    {
        bool col0HasZero = false;
        int Rsize = matrix.size();
        int Csize = matrix[0].size();

        for (int row = 0; row < Rsize; row++)
        {
            col0HasZero = (matrix[row][0] == 0) || col0HasZero;
            for (int col = 1; col < Csize; col++)
            {
                if (matrix[row][col] == 0)
                    matrix[row][0] = matrix[0][col] = 0;
            }
        }

        for (int row = Rsize - 1; row >= 0; row--)
        {
            for (int col = Csize - 1; col >= 1; col--)
            {
                if (matrix[row][0] == 0 || matrix[0][col] == 0)
                    matrix[row][col] = 0;
            }
            matrix[row][0] = col0HasZero ? 0 : matrix[row][0];
        }
    }

    //76. Minimum Window Substring
    static string minWindow(string s, string t)
    {
        vector<int> map(128, 0);
        for (auto c : t)
            map[c]++;
        int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
        while (end < s.size())
        {
            if (map[s[end++]]-- > 0)
                counter--; //in t
            while (counter == 0)
            { //valid
                if (end - begin < d)
                    d = end - (head = begin);
                if (map[s[begin++]]++ == 0)
                    counter++; //make it invalid
            }
        }
        return d == INT_MAX ? "" : s.substr(head, d);
    }

    //79. Word Search
    static bool search(vector<vector<char>> &board, const string &word, int d, int i, int j)
    {
        int h = board.size();
        int w = board[0].size();
        if (i < 0 || j < 0 || i >= h || j >= w || board[i][j] != word[d])
            return false;
        if (d == word.size() - 1)
            return true;
        board[i][j] = '.';
        bool found = search(board, word, d + 1, i + 1, j) || search(board, word, d + 1, i - 1, j) || search(board, word, d + 1, i, j + 1) || search(board, word, d + 1, i, j - 1);
        board[i][j] = word[d];
        return found;
    }
    static bool exist(vector<vector<char>> &board, string word)
    {
        if (board.empty())
            return false;
        int h = board.size();
        int w = board[0].size();
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
                if (search(board, word, 0, i, j))
                    return true;
        }
        return false;
    }

    //91. Decode Ways
    static int numDecodings(string s)
    {
        if (s[0] == '0')
            return 0;
        if (s.size() == 1)
            return 1;
        int n0 = 1;
        int n1 = 1;
        for (int i = 1; i < s.length(); i++)
        {
            int nc = 0;
            if (s[i] != '0')
                nc = n1;
            int &&num = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (num >= 10 && num <= 26)
                nc += n0;
            n0 = n1;
            n1 = nc;
        }
        return n1;
    }

    //98. Validate Binary Search Tree
    static bool isValidBST(TreeNode *root)
    {
        //Do an in-order traversal
        if (!root)
            return true;
        vector<TreeNode *> temp;
        TreeNode *pre = nullptr;
        while (root || !temp.empty())
        {
            while (root)
            {
                temp.push_back(root);
                root = root->left;
            }
            root = temp.back();
            temp.pop_back();
            if (pre && pre->val >= root->val)
                return false;
            pre = root;
            root = root->right;
        }

        return true;
    }

    //100. Same Tree
    static bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        if (p->val != q->val)
            return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    //102. Binary Tree Level Order Traversal
    static void recursive(TreeNode *root, vector<vector<int>> *levels, int level)
    {
        if (root == nullptr)
            return;

        if (level > levels->size())
            levels->push_back(vector<int>());

        levels->at(level - 1).push_back(root->val);
        recursive(root->left, levels, level + 1);
        recursive(root->right, levels, level + 1);
    }

    static vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> levels;
        recursive(root, &levels, 1);
        return levels;
    }

    //104. Maximum Depth of Binary Tree
    static int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;

        int leftd = maxDepth(root->left);
        int rightd = maxDepth(root->right);
        return max(leftd, rightd) + 1;
    }

    //105. Construct Binary Tree from Preorder and Inorder Traversal
    static TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        map<int, int> inorderValMapIndex;
        for (int i = 0; i < inorder.size(); i++)
            inorderValMapIndex[inorder[i]] = i;

        return buildSubTree(preorder, 0, preorder.size() - 1, inorderValMapIndex, 0, inorder.size() - 1);
    }

    static TreeNode *buildSubTree(vector<int> &preorder, int preStart, int preEnd, map<int, int> &inorderValMapIndex, int inStart, int inEnd)
    {
        if (preEnd - preStart <= -1)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[preStart]);
        int inRootIndex = inorderValMapIndex[preorder[preStart]] - inStart;
        int inLeftIndex = inStart;
        int inRightIndex = inStart + 1 + inRootIndex;
        int preLeftIndex = preStart + 1;
        int preRightIndex = preStart + 1 + inRootIndex;
        root->left = buildSubTree(preorder, preLeftIndex, preRightIndex - 1, inorderValMapIndex, inLeftIndex, inRightIndex - 2);
        root->right = buildSubTree(preorder, preRightIndex, preEnd, inorderValMapIndex, inRightIndex, inEnd);
        return root;
    }

    //121. Best Time to Buy and Sell Stock
    static int maxProfit(vector<int> &prices)
    {
        int maxProfit = 0;
        int profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            profit += prices[i] - prices[i - 1];
            profit = profit > 0 ? profit : 0;
            maxProfit = profit > maxProfit ? profit : maxProfit;
        }
        return maxProfit;
    }

    //124. Binary Tree Maximum Path Sum
    static int getRootPathMaxSum(TreeNode *root, int &maxSum)
    {
        if (!root)
            return 0;

        int leftSum = max(0, getRootPathMaxSum(root->left, maxSum));
        int rightSum = max(0, getRootPathMaxSum(root->right, maxSum));
        int &&sum = leftSum + rightSum + root->val;
        maxSum = max(maxSum, sum);
        return max(leftSum, rightSum) + root->val;
    }
    static int maxPathSum(TreeNode *root)
    {
        if (!root)
            return 0;

        int max = root->val;
        getRootPathMaxSum(root, max);
        return max;
    }

    //125. Valid Palindrome
    static bool isPalindrome(string s)
    {
        for (int start = 0, end = s.size() - 1; start < end;)
        {
            if (!isalnum(s[start]))
                start++;
            else if (!isalnum(s[end]))
                end--;
            else if (tolower(s[start++]) != tolower(s[end--]))
                return false;
        }
        return true;
    }

    //128. Longest Consecutive Sequence
    static int longestConsecutive(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        unordered_map<int, int> numsMap;
        int longestCount = 0;
        for (int num : nums)
        {
            if (numsMap.find(num) == numsMap.end())
            {
                int leftcount = numsMap.find(num - 1) == numsMap.end() ? 0 : numsMap[num - 1];
                int rightcount = numsMap.find(num + 1) == numsMap.end() ? 0 : numsMap[num + 1];
                int &&count = leftcount + 1 + rightcount;
                numsMap[num - leftcount] = numsMap[num + rightcount] = numsMap[num] = count;
                longestCount = longestCount > count ? longestCount : count;
            }
        }
        return longestCount;
    }

    //133. Clone Graph
    // Definition for a Node.
    class Node
    {
    public:
        int val;
        vector<Node *> neighbors;
        Node()
        {
            val = 0;
            neighbors = vector<Node *>();
        }
        Node(int _val)
        {
            val = _val;
            neighbors = vector<Node *>();
        }
        Node(int _val, vector<Node *> _neighbors)
        {
            val = _val;
            neighbors = _neighbors;
        }
    };
    static Node *cloneSubGraph(Node *node, unordered_map<int, Node *> &map)
    {
        if (map.find(node->val) != map.end())
            return map[node->val];

        Node *cloneNode = new Node(node->val);
        map[node->val] = cloneNode;
        for (Node *neighborNode : node->neighbors)
            cloneNode->neighbors.push_back(cloneSubGraph(neighborNode, map));

        return cloneNode;
    }
    static Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;

        unordered_map<int, Node *> nodeMap;
        return cloneSubGraph(node, nodeMap);
    }

    //139. Word Break
    static bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<int> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 0; i < s.size(); i++)
        {
            if (dp[i])
            {
                for (string word : wordDict)
                {
                    if (s.compare(i, word.size(), word) == 0)
                    {
                        dp[i + word.size()] = true;
                    }
                }
            }
        }
        return dp.back();
    }

    //141. Linked List Cycle
    static bool hasCycle(ListNode *head)
    {
        ListNode *slowNode = head;
        ListNode *fastNode = head;
        while (fastNode && fastNode->next)
        {
            slowNode = slowNode->next;
            fastNode = fastNode->next->next;
            if (fastNode == slowNode)
                return true;
        }
        return false;
    }

    //143. Reorder List
    static void reorderList(ListNode *head)
    {
        //need reorder only if has three more nodes
        if (head == nullptr || head->next == nullptr)
            return;

        //Find the middle node of the list
        ListNode *oneStep = head;
        ListNode *twoStep = head;
        while (twoStep->next && twoStep->next->next)
        {
            oneStep = oneStep->next;
            twoStep = twoStep->next->next;
        }

        //Reverse the half after middle  1->2->3->4->5->6 to 1->2->3->6->5->4
        ListNode *midNode = oneStep;
        ListNode *newLastNode = oneStep->next;
        ListNode *reverseNode;
        while (newLastNode->next)
        {
            reverseNode = newLastNode->next;
            newLastNode->next = reverseNode->next;
            reverseNode->next = midNode->next;
            midNode->next = reverseNode;
        }

        //Start reorder one by one  1->2->3->6->5->4 to 1->6->2->5->3->4
        ListNode *forwardNode = head;
        ListNode *reorderNode;
        while (forwardNode != midNode)
        {
            reorderNode = midNode->next;
            midNode->next = reorderNode->next;
            reorderNode->next = forwardNode->next;
            forwardNode->next = reorderNode;
            forwardNode = reorderNode->next;
        }
    }

    //152. Maximum Product Subarray
    static int maxProduct(vector<int> &nums)
    {
        int n = nums.size(), res = nums[0], l = 0, r = 0;
        for (int i = 0; i < n; i++)
        {
            l = (l ? l : 1) * nums[i];
            r = (r ? r : 1) * nums[n - 1 - i];
            res = max(res, max(l, r));
        }
        return res;
    }

    //153. Find Minimum in Rotated Sorted Array
    static int findMin(vector<int> &nums)
    {
        int right = nums.size() - 1;
        int left = 0;
        while (nums[left] > nums[right])
        {
            int mid = (left + right) / 2;
            (nums[mid] >= nums[left]) ? (left = mid + 1) : (right = mid);
        }
        return nums[left];
    }

    //190. Reverse Bits
    //僅適用 32 位元無號整數
    static uint32_t reverseBits(uint32_t n)
    {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }

    //191. Number of 1 Bits
    //僅適用 32 位元無號整數
    static int hammingWeight(uint32_t n)
    {
        n = (n & 0x55555555) + ((n & 0xaaaaaaaa) >> 1);
        n = (n & 0x33333333) + ((n & 0xcccccccc) >> 2);
        n = (n & 0x0f0f0f0f) + ((n & 0xf0f0f0f0) >> 4);
        n = (n & 0x00ff00ff) + ((n & 0xff00ff00) >> 8);
        n = (n & 0x0000ffff) + ((n & 0xffff0000) >> 16);
        return n;
    }

    //198. House Robber
    static int rob(vector<int> &nums)
    {
        for (int i = 1; i < nums.size(); i++)
        {
            nums[i] += i == 1 ? 0 : nums[i - 2];
            nums[i] = (nums[i] > nums[i - 1]) ? nums[i] : nums[i - 1];
        }
        return nums.back();
    }

    //200. Number of Islands
    static int numIslands(vector<vector<char>> &grid)
    {
        int r = 0;
        vector<pair<int, int>> search_dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> grid_queue;
        for (int m = 0; m < grid.size(); m++)
        {
            for (int n = 0; n < grid[m].size(); n++)
            {
                if (grid[m][n] == '1')
                {
                    r++;
                    grid_queue.push({m, n});
                    while (!grid_queue.empty())
                    {
                        int i = grid_queue.front().first;
                        int j = grid_queue.front().second;
                        grid_queue.pop();
                        grid[i][j] = '0';
                        for (const pair<int, int> &dir : search_dir)
                        {
                            int &&x = i + dir.first;
                            int &&y = j + dir.second;
                            if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != '1')
                                continue;
                            grid[x][y] = '0';
                            grid_queue.push({x, y});
                        }
                    }
                }
            }
        }
        return r;
    }

    //206. Reverse Linked List
    //Recursive
    static ListNode *reverseList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *r = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return r;
    }

    //207. Course Schedule
    //BFS
    static bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        if (prerequisites.empty() || numCourses < 2)
            return true;

        vector<int> courseIncount(numCourses, 0);
        vector<vector<int>> graph(numCourses, vector<int>());
        for (vector<int> pair : prerequisites)
        {
            graph[pair[0]].push_back(pair[1]);
            courseIncount[pair[1]]++;
        }

        queue<int> checkqueue;
        for (int i = 0; i < numCourses; i++)
        {
            if (courseIncount[i] == 0)
                checkqueue.push(i);
        }
        while (!checkqueue.empty())
        {
            int c = checkqueue.front();
            checkqueue.pop();
            numCourses--;
            for (int nextC : graph[c])
            {
                courseIncount[nextC]--;
                if (courseIncount[nextC] == 0)
                    checkqueue.push(nextC);
            }
        }
        return numCourses == 0;
    }

    //208. Implement Trie (Prefix Tree)
    static void testTrie()
    {
        Trie trie;
        trie.insert("apple");
        cout << trie.search("apple");   // return True
        cout << trie.search("app");     // return False
        cout << trie.startsWith("app"); // return True
        trie.insert("app");
        cout << trie.search("app"); // return True
    }

    //211. Design Add and Search Words Data Structure
    static void testWordDictionary()
    {
        WordDictionary *wordDictionary = new WordDictionary();
        wordDictionary->addWord("bad");
        wordDictionary->addWord("dad");
        wordDictionary->addWord("mad");
        cout << wordDictionary->search("pad"); // return False
        cout << wordDictionary->search("bad"); // return True
        cout << wordDictionary->search(".ad"); // return True
        cout << wordDictionary->search("b.."); // return True
        delete wordDictionary;
    }

    //212. Word Search II
    //DFS + backtracking + 79. Word Search
    static vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        vector<string> result;
        vector<pair<int, int>> charPosVec[26];
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                charPosVec[board[i][j] - 'a'].push_back({i, j});

        for (const string &word : words)
        {
            int &&c = word[0] - 'a';
            for (pair<int, int> pos : charPosVec[c])
            {
                if (search(board, word, 0, pos.first, pos.second))
                {
                    result.push_back(word);
                    break;
                }
            }
        }
        return result;
    }

    //213. House Robber II
    //modify 198. House Robber
    static int robBySEPos(vector<int> &nums, int start, int end)
    {
        int pre2 = 0, pre1 = 0;
        for (int i = start; i < end; i++)
        {
            int &&tempCur = nums[i] + pre2;
            tempCur = tempCur > pre1 ? tempCur : pre1;
            pre2 = pre1;
            pre1 = tempCur;
        }
        return pre1;
    }
    static int rob2(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];

        int &&r1 = robBySEPos(nums, 0, nums.size() - 1);
        int &&r2 = robBySEPos(nums, 1, nums.size());
        return r2 > r1 ? r2 : r1;
    }

    //217. Contains Duplicate
    static bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> numSet;
        for (int num : nums)
        {
            if (numSet.find(num) != numSet.end())
                return true;
            numSet.insert(num);
        }
        return false;
    }

    //226. Invert Binary Tree
    //DFS  recursive.
    static TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return root;

        invertTree(root->left);
        invertTree(root->right);
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        return root;
    }

    //230. Kth Smallest Element in a BST
    //Solution2:Recursive
    static int kthSmallest(TreeNode *root, int k)
    {
        return findKthSmallest(root, k);
    }
    static int findKthSmallest(TreeNode *root, int &k)
    {
        if (root)
        {
            int val = findKthSmallest(root->left, k);
            if (k == 0)
                return val;
            if (--k == 0)
                return root->val;
            return findKthSmallest(root->right, k);
        }
        return -1;
    }

    // 235. Lowest Common Ancestor of a Binary Search Tree
    // Iterative Approach
    static TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        while (root)
        {
            if (p->val < root->val && q->val < root->val)
                root = root->left;
            else if (p->val > root->val && q->val > root->val)
                root = root->right;
            else
               break;    
        }
        return root;
    }

    //238. Product of Array Except Self
    //space O(1), time O(n)
    static vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> r(n, 1);
        for (int i = 1; i < n; i++)
            r[i] = nums[i - 1] * r[i - 1];
        int temp = 1;
        for(int i = n-2; i >=0; i--){
            temp *= nums[i + 1];
            r[i] *= temp;
        }
        return r;
    }
    
    //242. Valid Anagram
    //hash map
    static bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        unordered_map<char, int> temp;
        for(int i = 0; i<t.size(); i++){
            temp[s[i]]++;
            temp[t[i]]--;
        }
        for(unordered_map<char, int> ::iterator it = temp.begin();it != temp.end();it++)
            if(it->second != 0)
                return false;
        return true;
    }

    //252. Meeting Rooms
    static bool canAttendMeetings(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](const vector<int>&a,const vector<int>&b)->bool{return b[0] > a[0];});
        for (int i = 1; i < intervals.size(); i++)
        if(intervals[i][0] < intervals[i-1][1])
            return false;
        return true;
    }

};