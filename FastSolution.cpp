
#include <string>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
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
    static vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, cur, ans);
        return ans;
    }
    static void dfs(vector<int>& candidates, int target, int s, vector<int>& cur, vector<vector<int>>& ans){
        if(target==0){
            ans.push_back(cur);
            return;
        }
        for(int i=s; i<candidates.size();i++){
            if(candidates[i] > target) break;
            cur.push_back(candidates[i]);
            dfs(candidates, target-candidates[i], i , cur, ans);
            cur.pop_back();
        }
    }
    ////

};