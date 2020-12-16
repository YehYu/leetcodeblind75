#include "Solution.cpp"
#include <stdio.h>
#include <iostream>
using namespace std;
typedef Solution::ListNode ListNode;

int main()
{
    ListNode *head = new ListNode(1, new ListNode(2));

    ListNode *r = Solution::removeNthFromEnd(head, 2);
    while (r)
    {
        cout << r->val << endl;
        r = r->next;
    }
    return 0;
}