
#include <string>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
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

    // Definition for singly-linked list.
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
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
                tempR = nums[i] >= 0 ? nums[i] : max(tempR, nums[i]);
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
};
