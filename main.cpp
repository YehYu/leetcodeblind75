#include "Solution.cpp"
#include <stdio.h>
#include <iostream>
using namespace std;
typedef Solution::ListNode ListNode;

int main()
{
    ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* A = Solution::mergeTwoLists(l1, l2);
    while (A)
    {
        cout <<A->val<< endl;
        A = A->next;
    }
    
    

    return 0;
}