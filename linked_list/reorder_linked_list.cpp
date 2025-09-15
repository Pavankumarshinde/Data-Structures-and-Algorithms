#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverse(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *pre = nullptr;
        ListNode *curr = head;
        ListNode *Next = curr->next;
        while (Next)
        {
            curr->next = pre;
            pre = curr;
            curr = Next;
            Next = Next->next;
        }
        curr->next = pre;
        return curr;
    }

    ListNode *merge(ListNode *p, ListNode *q)
    {
        ListNode *sol = p;
        ListNode *ans = p;
        p = p->next;
        int i = 0;
        while (p && q)
        {
            if (i % 2 == 0)
            {
                ans->next = q;
                ans = ans->next;
                q = q->next;
            }
            else
            {
                ans->next = p;
                ans = ans->next;
                p = p->next;
            }
            i++;
        }
        if (p)
            ans->next = p;
        if (q)
            ans->next = q;
        return sol;
    }

    void reorderList(ListNode *head)
    {
        if (!head || !head->next)
            return;

        ListNode *slow = head;
        ListNode *fast = head;
        while (slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *p = head;
        ListNode *q = slow->next;
        slow->next = nullptr;

        q = reverse(q);
        head = merge(p, q);
    }
};

// Helper function to print list
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
    // Example: Input list = [2,4,6,8]
    ListNode *head = new ListNode(2);
    head->next = new ListNode(4);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(8);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    sol.reorderList(head);

    cout << "Reordered List: ";
    printList(head);

    return 0;
}
