#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
    ListNode *merge(ListNode *list1, ListNode *list2)
    {
        ListNode *p = list1;
        ListNode *q = list2;
        ListNode *ans = nullptr;
        ListNode *sol;
        if (p->val < q->val)
        {
            ans = p;
            p = p->next;
            sol = ans;
        }
        else
        {
            ans = q;
            q = q->next;
            sol = ans;
        }

        while (p && q)
        {
            if (p->val < q->val)
            {
                ans->next = p;
                p = p->next;
                ans = ans->next;
            }
            else
            {
                ans->next = q;
                q = q->next;
                ans = ans->next;
            }
        }
        if (p)
        {
            ans->next = p;
        }
        if (q)
        {
            ans->next = q;
        }
        return sol;
    }
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        return merge(list1, list2);
    }
};
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}
int main()
{
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(6);

    ListNode *list2 = new ListNode(2);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(5);
    Solution sol;

    ListNode *mergeList = sol.mergeTwoLists(list1, list2);
    printList(mergeList);
    return 0;
}
