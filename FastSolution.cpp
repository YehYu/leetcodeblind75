
#include <string>
#include <map>
#include <math.h>
using namespace std;

class FastSolution
{
public:
    static string longestPalindrome(string s)
    {
        int max = 0;
        string res = "";
        int curr = 0;

        while(curr < s.size())
        {
            int start = curr;
            int end = curr;

            while(end < s.size() && s[end] == s[end + 1])
                end++;
            curr = end + 1;

            while(start > 0 && end < s.size() && s[start - 1] == s[end + 1])
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



};