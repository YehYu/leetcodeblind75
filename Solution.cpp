
#include "data.h"
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <bitset>

using namespace std;

class Solution
{
public:
    static vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> tempMap;
        for (int i = 0; i < nums.size(); i++)
        {
            if (tempMap.find(target - nums[i]) != tempMap.end())
                return {tempMap[target - nums[i]], i};
            tempMap[nums[i]] = i;
        }
        return vector<int>();
    }

    static int lengthOfLongestSubstring(string s)
    {
        int r = 0;
        map<char, int> tempMap;
        for (int i = 0, startIndex = 0; i < s.length(); i++)
        {
            map<char, int>::iterator iter = tempMap.find(s[i]);
            if (iter != tempMap.end())
                startIndex = max(startIndex, iter->second);
            r = max(r, i - startIndex + 1);
            tempMap[s[i]] = i + 1;
        }
        return r;
    }

    static string longestPalindrome(string s)
    {
        int front = 0;
        int length = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int f;
            for (f = i - 1; f >= 0; f--)
                if (s.at(f) != s.at(i))
                    break;
            int b;
            for (b = i + 1; b < s.length(); b++)
                if (s.at(b) != s.at(i))
                    break;
            while (f >= 0 && b < s.length())
            {
                if (s.at(f) != s.at(b))
                    break;
                f--;
                b++;
            }
            int tempLength = b - f - 1;
            if (tempLength > length)
            {
                front = f + 1;
                length = tempLength;
            }
        }
        return s.substr(front, length);
    }

    static int maxArea(vector<int> &height)
    {
        int length = height.size();
        int i = 0;
        int r = 0;
        while (i < length)
        {
            int h = height[i];
            int div = 0;
            if (h != 0)
                div = r / h;
            for (int tset_i = length - 1; tset_i >= i + div; tset_i--)
            {
                int tempR = (tset_i - i) * h;
                if (height[tset_i] >= h && tempR >= r)
                {
                    r = tempR;
                    div = tset_i - i;
                }
            }

            for (int tset_i = 0; tset_i <= i - div; tset_i++)
            {
                int tempR = (i - tset_i) * h;
                if (height[tset_i] >= h && tempR >= r)
                    r = tempR;
            }
            i++;
        }
        return r;
    }

    static vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> r;
        if (nums.size() < 3)
            return r;
        sort(nums.begin(), nums.end());
        if (nums.front() > 0 || nums.back() < 0)
            return r;

        for (int i = 0; i < nums.size() && nums[i] <= 0; i++)
        {
            if (i != 0 && nums[i - 1] == nums[i])
                continue;

            int target = -1 * nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                int sum = nums[left] + nums[right];
                if (sum == target)
                {
                    r.push_back({nums[i], nums[left], nums[right]});
                    do
                    {
                        left++;
                    } while (left < right && nums[left] == nums[left - 1]);
                }
                else if (sum > target)
                    right--;
                else
                    left++;
            }
        }
        return r;
    }

    //19. Remove Nth Node From End of List
    static ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        vector<ListNode *> templist;
        templist.push_back(head);
        while (templist.back()->next)
            templist.push_back(templist.back()->next);
        int removeTarget = templist.size() - n;
        if (removeTarget == 0)
            head = head->next;
        else
            templist[removeTarget - 1]->next = templist[removeTarget]->next;
        return head;
    }

    //20. Valid Parentheses
    static bool isValid(string s)
    {
        if (s.length() % 2)
            return false;
        vector<char> temp;
        map<char, char> parenthesesMap = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
        for (char c : s)
        {
            if (parenthesesMap.find(c) != parenthesesMap.end())
                temp.push_back(c);
            else if (temp.size() != 0 && parenthesesMap[temp.back()] == c)
                temp.pop_back();
            else
                return false;
        }
        return temp.size() == 0 ? true : false;
    }

    //21. Merge Two Sorted Lists
    static ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr || l2 == nullptr)
            return (l1 == nullptr) ? l2 : l1;

        ListNode *currl = new ListNode(0);
        ListNode *currl1 = l1;
        ListNode *currl2 = l2;
        while (currl1 && currl2)
        {
            currl->next = (currl1->val <= currl2->val) ? currl1 : currl2;
            (currl1->val <= currl2->val) ? currl1 = currl1->next : currl2 = currl2->next;
            currl = currl->next;
        }
        currl->next = (currl2 == nullptr) ? currl1 : currl2;
        return (l1->val <= l2->val) ? l1 : l2;
    }

    //23. Merge k Sorted Lists
    static ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *result = nullptr;
        while (!lists.empty())
        {
            result = mergeTwoLists(result, lists.back());
            lists.pop_back();
        }
        return result;
    }

    static int search(vector<int> &nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end)
        {
            int mid = (end + start) * 0.5;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                (nums[mid] >= nums[end] && target < nums[start]) ? start = mid + 1 : end = mid - 1;
            else if (nums[mid] < target)
                (nums[mid] <= nums[start] && target > nums[end]) ? end = mid - 1 : start = mid + 1;
        }
        return -1;
    }

    static void comp(const vector<int> &candidates, int target, vector<vector<int>> &result, vector<int> &temp, int start)
    {
        for (int i = start; i < candidates.size(); i++)
        {
            int newTarget = target - candidates[i];
            if (newTarget < 0)
                break;
            else
            {
                temp.push_back(candidates[i]);
                (newTarget == 0) ? result.push_back(temp) : comp(candidates, newTarget, result, temp, i);
                temp.pop_back();
            }
        }
    }
    static vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> r;
        vector<int> temp;
        comp(candidates, target, r, temp, 0);
        return r;
    }

    static void rotate(vector<vector<int>> &matrix)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = i; j < matrix[i].size(); j++)
            {
                if (i != j)
                {
                    matrix[i][j] = matrix[i][j] ^ matrix[j][i];
                    matrix[j][i] = matrix[i][j] ^ matrix[j][i];
                    matrix[i][j] = matrix[i][j] ^ matrix[j][i];
                }
            }
        }

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size() / 2; j++)
            {
                matrix[i][j] = matrix[i][j] ^ matrix[i][matrix[i].size() - 1 - j];
                matrix[i][matrix[i].size() - 1 - j] = matrix[i][j] ^ matrix[i][matrix[i].size() - 1 - j];
                matrix[i][j] = matrix[i][j] ^ matrix[i][matrix[i].size() - 1 - j];
            }
        }
    }

    static vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> result;
        map<string, int> stringMap;
        for (int i = 0; i < strs.size(); i++)
        {
            string a = strs[i];
            sort(a.begin(), a.end());
            if (stringMap.find(a) == stringMap.end())
            {
                stringMap.insert(pair<string, int>(a, result.size()));
                result.push_back({{strs[i]}});
                continue;
            }
            result[stringMap[a]].push_back(strs[i]);
        }
        return result;
    }

    static int maxSubArray(vector<int> &nums)
    {
        int result = nums[0];
        int tempR = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (tempR <= 0)
                tempR = nums[i];
            else
                tempR += nums[i];

            result = max(tempR, result);
        }
        return result;
    }

    static vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> result;
        vector<vector<bool>> haveValue(matrix.size(), vector<bool>(matrix[0].size(), false));
        int start_i = 0;
        int start_j = 0;
        int step_i = 0;
        int step_j = 1;
        for (int i = 0; i < matrix.size() * matrix[0].size(); i++)
        {
            result.push_back(matrix[start_i][start_j]);
            haveValue[start_i][start_j] = true;
            start_i += step_i;
            start_j += step_j;
            if (step_i != 0)
            {
                if (start_i < 0 || start_i >= matrix.size() || haveValue[start_i][start_j])
                {
                    start_i -= step_i;
                    step_j = step_i * -1;
                    step_i = 0;
                    start_j += step_j;
                }
            }
            else if (step_j != 0)
            {
                if (start_j < 0 || start_j >= matrix[0].size() || haveValue[start_i][start_j])
                {
                    start_j -= step_j;
                    step_i = step_j;
                    step_j = 0;
                    start_i += step_i;
                }
            }
        }
        return result;
    }

    //55. Jump Game
    static bool canJump(vector<int> &nums)
    {
        int Good_index = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if ((i + nums[i]) >= Good_index)
                Good_index = i;
        }
        return Good_index == 0;
    }

    //56. Merge Intervals
    static vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        map<int, int> tempMap;
        vector<vector<int>> result;
        for (vector<int> interval : intervals)
            tempMap[interval[0]] = (tempMap.find(interval[0]) == tempMap.end()) ? interval[1] : max(interval[1], tempMap[interval[0]]);

        map<int, int>::iterator iter = tempMap.begin();
        while (iter != tempMap.end())
        {
            if (result.empty() || iter->first > result.back()[1])
                result.push_back({iter->first, iter->second});
            else
                result.back()[1] = result.back()[1] > iter->second ? result.back()[1] : iter->second;

            iter++;
        }
        return result;
    }

    //57. Insert Interval
    static vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        if (intervals.empty())
            return {newInterval};

        vector<vector<int>> result;
        auto checkInterval = [&result](const vector<int> &interval)
        {
            if (result.empty() || interval[0] > result.back()[1])
                result.push_back({interval[0], interval[1]});
            else
                result.back()[1] = result.back()[1] > interval[1] ? result.back()[1] : interval[1];
        };
        bool checkNew = false;
        for (const vector<int> &interval : intervals)
        {
            if (!checkNew && newInterval[0] <= interval[0])
            {
                checkNew = true;
                checkInterval(newInterval);
            }
            checkInterval(interval);
        }

        if (!checkNew)
            checkInterval(newInterval);

        return result;
    }

    //62. Unique Paths
    static int computePaths(int m, int n, vector<vector<int>> &matrix)
    {
        if (matrix[m][n] != -1)
            return matrix[m][n];

        if (m == 0)
        {
            matrix[m][n] = 1;
            return 1;
        }

        int result = 0;
        for (int j = 0; j <= n; j++)
            result += computePaths(m - 1, n - j, matrix);

        matrix[m][n] = result;
        return result;
    }
    static int uniquePaths(int m, int n)
    {
        if (m > n)
        {
            m = m ^ n;
            n = m ^ n;
            m = m ^ n;
        }
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        return computePaths(m - 1, n - 1, matrix);
    }

    //70. Climbing Stairs
    static int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        //因為一次可走一階或是兩階
        vector<int> dp(n, 0);
        dp[0] = 1; //走道第一皆的走法=1
        dp[1] = 2; //走道第二皆的走法=2,(1+1)or2
        for (int i = 2; i < n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n - 1];
    }

    //73. Set Matrix Zeroes
    static void setZeroes(vector<vector<int>> &matrix)
    {
        int firstZeroMN = -1;
        for (int m = 0; m < matrix.size(); m++)
        {
            for (int n = 0; n < matrix[0].size(); n++)
            {
                if (firstZeroMN != -1 && (m == firstZeroMN / matrix[0].size() || n == firstZeroMN % matrix[0].size()))
                    continue;
                if (matrix[m][n] == 0)
                {
                    if (firstZeroMN == -1)
                    {
                        firstZeroMN = m * matrix[0].size() + n;
                        for (int t = 0; t < matrix.size(); t++)
                            matrix[t][firstZeroMN % matrix[0].size()] = matrix[t][firstZeroMN % matrix[0].size()] == 0 ? 1 : 0;
                        for (int t = 0; t < matrix[0].size(); t++)
                            matrix[firstZeroMN / matrix[0].size()][t] = matrix[firstZeroMN / matrix[0].size()][t] == 0 ? 1 : 0;
                        continue;
                    }
                    matrix[firstZeroMN / matrix[0].size()][n] = 1;
                    matrix[m][firstZeroMN % matrix[0].size()] = 1;
                }
            }
        }
        if (firstZeroMN == -1)
            return;
        for (int m = 0; m < matrix.size(); m++)
        {
            for (int n = 0; n < matrix[0].size(); n++)
            {
                if (m == firstZeroMN / matrix[0].size() || n == firstZeroMN % matrix[0].size())
                    continue;
                if (matrix[firstZeroMN / matrix[0].size()][n] == 1 || matrix[m][firstZeroMN % matrix[0].size()] == 1)
                    matrix[m][n] = 0;
            }
        }
        for (int m = 0; m < matrix.size(); m++)
            matrix[m][firstZeroMN % matrix[0].size()] = 0;
        for (int n = 0; n < matrix[0].size(); n++)
            matrix[firstZeroMN / matrix[0].size()][n] = 0;
    }

    //76. Minimum Window Substring
    static string minWindow(string s, string t)
    {
        string result;
        map<char, int> countMap;
        map<int, char> tempMap;
        int right, left = -1, t_length = t.length(), min_length = s.length() + 1;

        for (char c : t)
            countMap[c]++;

        for (right = 0; right < s.length(); right++)
        {
            if (countMap.find(s[right]) == countMap.end())
                continue;
            tempMap[right] = s[right];
            if (countMap[s[right]]-- > 0)
                t_length--;
            if (t_length == 0)
            {
                map<int, char>::iterator it = left != -1 ? ++tempMap.find(left) : tempMap.begin();
                while (it != tempMap.end())
                {
                    if (countMap[it->second]++ == 0)
                    {
                        t_length++;
                        left = it->first;
                        int &&l = right - it->first + 1;
                        if (min_length > l)
                        {
                            min_length = l;
                            result = s.substr(it->first, l);
                        }
                        break;
                    }
                    it++;
                }
            }
        }

        return result;
    }

    //79. Word Search
    static bool checkExist(vector<vector<char>> &board, const string &word, int x, int y, int strPos)
    {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != word[strPos])
            return false;
        if (strPos == word.length() - 1)
            return true;
        char tempChar = board[x][y];
        board[x][y] = '0';
        bool exist = (checkExist(board, word, x - 1, y, strPos + 1) || checkExist(board, word, x + 1, y, strPos + 1) || checkExist(board, word, x, y - 1, strPos + 1) || checkExist(board, word, x, y + 1, strPos + 1));
        board[x][y] = tempChar;
        return exist;
    }
    static bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == word[0])
                    if (checkExist(board, word, i, j, 0))
                        return true;
            }
        }
        return false;
    }

    //91. Decode Ways
    static int checkNumDecodings(int pos, const string &s, map<int, int> &tempMap)
    {
        if (tempMap.find(pos) != tempMap.end())
            return tempMap[pos];
        int size1 = 0, size2 = 0;
        if (pos == s.length() - 1)
        {
            size1 = s[pos] == '0' ? 0 : 1;
        }
        else if (pos == s.length() - 2)
        {
            size1 = s[pos] == '0' ? 0 : checkNumDecodings(pos + 1, s, tempMap);
            size2 = (s[pos] == '0' || stoi(s.substr(pos, 2)) >= 27) ? 0 : 1;
        }
        else
        {
            size1 = s[pos] == '0' ? 0 : checkNumDecodings(pos + 1, s, tempMap);
            size2 = (s[pos] == '0' || stoi(s.substr(pos, 2)) >= 27) ? 0 : checkNumDecodings(pos + 2, s, tempMap);
        }

        int &&r = size1 + size2;
        tempMap[pos] = r;
        return r;
    }
    static int numDecodings(string s)
    {
        map<int, int> tempMap;
        return checkNumDecodings(0, s, tempMap);
    }

    //98. Validate Binary Search Tree
    static bool checkIsValidBST(TreeNode *root, TreeNode *max, TreeNode *min)
    {
        if (!root)
            return true;

        if ((max && root->val >= max->val) || (min && root->val <= min->val))
            return false;

        return (checkIsValidBST(root->left, root, min) && checkIsValidBST(root->right, max, root));
    }
    static bool isValidBST(TreeNode *root)
    {
        return checkIsValidBST(root, nullptr, nullptr);
    }

    //100. Same Tree
    static bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;
        if (p && q && p->val != q->val)
            return false;
        if ((p && !q) || (!p && q))
            return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    //102. Binary Tree Level Order Traversal
    static vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
            return vector<vector<int>>();
        vector<vector<int>> r;
        queue<TreeNode *> traversalQueue;
        traversalQueue.push(root);
        while (traversalQueue.size())
        {
            int level_count = traversalQueue.size();
            vector<int> temp;
            for (int i = 0; i < level_count; i++)
            {
                TreeNode *node = traversalQueue.front();
                temp.push_back(node->val);
                if (node->left)
                    traversalQueue.push(node->left);
                if (node->right)
                    traversalQueue.push(node->right);
                traversalQueue.pop();
            }
            r.push_back(temp);
        }
        return r;
    }

    //104. Maximum Depth of Binary Tree
    static int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int l_Depth = maxDepth(root->left) + 1;
        int r_Depth = maxDepth(root->right) + 1;
        return l_Depth > r_Depth ? l_Depth : r_Depth;
    }

    //105. Construct Binary Tree from Preorder and Inorder Traversal
    static TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        TreeNode *root = new TreeNode(preorder[0]);
        map<int, int> inorderValMapIndex;
        for (int i = 0; i < inorder.size(); i++)
            inorderValMapIndex[inorder[i]] = i;

        map<int, TreeNode *> tempMap;
        tempMap[0] = root;
        vector<int> temp{0};
        int cur = 0, pre;
        for (int next = 1; next < preorder.size(); next++)
        {
            TreeNode *tempNode = new TreeNode(preorder[next]);
            if (inorderValMapIndex[preorder[next]] < inorderValMapIndex[preorder[cur]])
            {
                tempMap[cur]->left = tempNode;
            }
            else
            {
                do
                {
                    cur = temp.back();
                    temp.pop_back();
                    if (temp.empty())
                        break;
                    pre = temp.back();
                } while (inorderValMapIndex[preorder[next]] > inorderValMapIndex[preorder[pre]]);

                tempMap[cur]->right = tempNode;
            }
            tempMap[next] = tempNode;
            temp.push_back(next);
            cur = temp.back();
        }
        return root;
    }

    //121. Best Time to Buy and Sell Stock
    static int maxProfit(vector<int> &prices)
    {
        int buy = prices[0];
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            int profit = prices[i] - buy;
            maxProfit = profit > maxProfit ? profit : maxProfit;
            buy = prices[i] < buy ? prices[i] : buy;
        }
        return maxProfit;
    }

    //124. Binary Tree Maximum Path Sum
    static int getPathMaxSum(TreeNode *root, int &maxSum)
    {
        if (!root)
            return 0;

        int &&leftSum = getPathMaxSum(root->left, maxSum) + root->val;
        int &&rightSum = getPathMaxSum(root->right, maxSum) + root->val;
        int &&sum = leftSum + rightSum - root->val;
        maxSum = max({maxSum, leftSum, rightSum, sum, root->val});
        return max({leftSum, rightSum, root->val});
    }
    static int maxPathSum(TreeNode *root)
    {
        if (!root)
            return 0;

        int max = root->val;
        getPathMaxSum(root, max);
        return max;
    }

    //125. Valid Palindrome
    static bool isPalindrome(string s)
    {
        int start = 0;
        int end = s.size() - 1;

        while (start < end)
        {
            while (end > start && !isalnum(s[end]))
                end--;

            while (start < end && !isalnum(s[start]))
                start++;

            if (start > end)
                break;

            if (tolower(s[start]) != tolower(s[end]))
                return false;

            start++;
            end--;
        }
        return true;
    }

    //128. Longest Consecutive Sequence
    static int longestConsecutive(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        sort(nums.begin(), nums.end());
        int longestCount = 1;
        int count = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
            {
                count = (nums[i] - nums[i - 1] == 1) ? count + 1 : 1;
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
    static bool checkWordBreak(const string &s, int start, vector<string> &wordDict, unordered_map<int, bool> &checkmap)
    {
        if (s.size() == start)
            return true;
        if (checkmap.find(start) != checkmap.end())
            return checkmap[start];

        for (const string &word : wordDict)
        {
            int wordSize = word.size();
            if (s.compare(start, wordSize, word) == 0)
            {
                if (checkWordBreak(s, start + wordSize, wordDict, checkmap))
                    return true;
            }
        }
        checkmap[start] = false;
        return false;
    }
    static bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_map<int, bool> checkmap;
        return checkWordBreak(s, 0, wordDict, checkmap);
    }

    //141. Linked List Cycle
    static bool hasCycle(ListNode *head)
    {
        unordered_set<ListNode *> nodeSet;
        while (head)
        {
            if (nodeSet.find(head) != nodeSet.end())
                return true;
            nodeSet.insert(head);
            head = head->next;
        }
        return false;
    }

    //143. Reorder List
    static void reorderList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return;
        vector<ListNode *> nodeList;
        while (head)
        {
            nodeList.push_back(head);
            head = head->next;
        }
        int s = 0, e = nodeList.size() - 1;
        while (e - s > 1)
        {
            nodeList[e]->next = nodeList[s]->next;
            nodeList[s]->next = nodeList[e];
            s++;
            e--;
        }
        nodeList[e]->next = nullptr;
    }

    //152. Maximum Product Subarray
    static int maxProduct(vector<int> &nums)
    {
        int result = nums[0];
        int tempMax = 1;
        int tempMin = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            int &&temp1 = tempMax * nums[i];
            int &&temp2 = tempMin * nums[i];
            tempMax = max(nums[i], max(temp1, temp2));
            tempMin = min(nums[i], min(temp1, temp2));
            result = (result > tempMax) ? result : tempMax;
        }
        return result;
    }

    //153. Find Minimum in Rotated Sorted Array
    static int findMin(vector<int> &nums)
    {
        int min = nums[0];
        for (int num : nums)
        {
            if (num < min)
                min = num;
        }
        return min;
    }

    //190. Reverse Bits
    static uint32_t reverseBits(uint32_t n)
    {
        uint32_t r = 0;
        int moveBit = 31;
        while (n)
        {
            r |= ((n & 1) << moveBit);
            n >>= 1;
            moveBit--;
        }
        return r;
    }

    //191. Number of 1 Bits
    static int hammingWeight(uint32_t n)
    {
        int r = 0;
        while (n)
        {
            r += (n & 1);
            n >>= 1;
        }
        return r;
    }

    //198. House Robber
    static int rob(vector<int> &nums)
    {
        int r = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int pre2 = i >= 2 ? nums[i - 2] : 0;
            int pre3 = i >= 3 ? nums[i - 3] : 0;
            nums[i] += (pre2 > pre3) ? pre2 : pre3;
            r = r > nums[i] ? r : nums[i];
        }
        return r;
    }

    //200. Number of Islands
    static void searchIslands(vector<vector<char>> &grid, int x, int y)
    {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != '1')
            return;
        grid[x][y] = '0';
        searchIslands(grid, x - 1, y);
        searchIslands(grid, x + 1, y);
        searchIslands(grid, x, y - 1);
        searchIslands(grid, x, y + 1);
        return;
    }

    static int numIslands(vector<vector<char>> &grid)
    {
        int r = 0;
        for (int m = 0; m < grid.size(); m++)
        {
            for (int n = 0; n < grid[m].size(); n++)
            {
                if (grid[m][n] == '1')
                {
                    r++;
                    searchIslands(grid, m, n);
                }
            }
        }
        return r;
    }

    //206. Reverse Linked List
    //Iterative
    static ListNode *reverseList(ListNode *head)
    {
        ListNode *preNode = nullptr;
        ListNode *curNode = head;
        while (curNode)
        {
            ListNode *nextNode = curNode->next;
            curNode->next = preNode;
            preNode = curNode;
            curNode = nextNode;
        }
        return preNode;
    }

    //207. Course Schedule
    //DFS
    static bool checkCycle(int course, vector<int> &coursesChecked, vector<vector<int>> &graph)
    {
        if (coursesChecked[course] == 1) //visting
            return true;

        if (coursesChecked[course] == -1) //visted
            return false;

        coursesChecked[course] = 1;
        for (int c : graph[course])
        {
            if (checkCycle(c, coursesChecked, graph))
                return true;
        }
        coursesChecked[course] = -1;
        return false;
    }

    static bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        if (prerequisites.empty() || numCourses <= 1)
            return true;

        vector<int> coursesChecked(numCourses, 0); //0: unvisted 1: visting -1:visted
        vector<vector<int>> graph(numCourses, vector<int>());
        for (vector<int> pair : prerequisites)
            graph[pair[0]].push_back(pair[1]);

        for (int course = 0; course < numCourses; course++)
        {
            if (checkCycle(course, coursesChecked, graph))
                return false;
        }
        return true;
    }

    //208. Implement Trie (Prefix Tree)
    static void testTrie()
    {
        Trie *trie = new Trie();
        trie->insert("apple");
        cout << trie->search("apple");   // return True
        cout << trie->search("app");     // return False
        cout << trie->startsWith("app"); // return True
        trie->insert("app");
        cout << trie->search("app"); // return True
        delete trie;
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
    static void searchword(vector<vector<char>> &board, vector<string> &result, int i, int j, TrieWordSearchNode *trieNode)
    {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '.')
            return;

        TrieWordSearchNode *node = trieNode->childVec[board[i][j] - 'a'];
        if (node)
        {
            if (!node->word.empty())
            {
                result.push_back(node->word);
                node->word.clear(); //prevent result duplicates psuh
            }

            char c = board[i][j];
            board[i][j] = '.';
            searchword(board, result, i + 1, j, node);
            searchword(board, result, i - 1, j, node);
            searchword(board, result, i, j + 1, node);
            searchword(board, result, i, j - 1, node);
            board[i][j] = c;
        }
    }
    static vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        vector<string> result;
        TrieWordSearchNode *trieNode = new TrieWordSearchNode();
        for (const string &word : words)
            trieNode->addNode(word);

        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                searchword(board, result, i, j, trieNode);

        delete trieNode;
        return result;
    }

    //213. House Robber II
    static int rob2(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];

        vector<int> v1 = vector<int>(nums.begin(), nums.end() - 1);
        vector<int> v2 = vector<int>(nums.begin() + 1, nums.end());
        int &&r1 = rob(v1);
        int &&r2 = rob(v2);
        return r2 > r1 ? r2 : r1;
    }

    //217. Contains Duplicate
    static bool containsDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
                return true;
        }
        return false;
    }

    //226. Invert Binary Tree
    //BFS
    static TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return root;

        queue<TreeNode *> nodeQueue;
        nodeQueue.push(root);
        while (!nodeQueue.empty())
        {
            TreeNode *cur = nodeQueue.front();
            TreeNode *temp = cur->left;
            cur->left = cur->right;
            cur->right = temp;
            if (cur->left)
                nodeQueue.push(cur->left);
            if (cur->right)
                nodeQueue.push(cur->right);
            nodeQueue.pop();
        }
        return root;
    }

    //230. Kth Smallest Element in a BST
    //Solution1: Iterative
    static int kthSmallest(TreeNode *root, int k)
    {
        vector<TreeNode *> nodeVector;
        while (root || !nodeVector.empty())
        {
            while (root)
            {
                nodeVector.push_back(root);
                root = root->left;
            }
            root = nodeVector.back();
            nodeVector.pop_back();
            if (--k == 0)
                return root->val;
            root = root->right;
        }
        return -1;
    }

    // 235. Lowest Common Ancestor of a Binary Search Tree
    // Recursive Approach
    static TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        else if (p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        else
            return root;
    }

    //238. Product of Array Except Self
    //time O(n)
    static vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> r(nums.size(), 1);
        vector<int> rf(nums.size(), 1);
        vector<int> rb(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++)
        {
            rf[i] = nums[i - 1] * rf[i - 1];
            rb[nums.size() - 1 - i] = nums[nums.size() - i] * rb[nums.size() - i];
            r[i] = rf[i] * rb[i];
            r[nums.size() - 1 - i] = rf[nums.size() - 1 - i] * rb[nums.size() - 1 - i];
        }
        return r;
    }

    //242. Valid Anagram
    //sort
    static bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
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
