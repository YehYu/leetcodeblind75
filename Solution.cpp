
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
};
