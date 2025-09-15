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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head)
            return head;
        if (!head->next && n == 1)
            return head->next;

        ListNode *slow = head;
        ListNode *fast = head;

        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }
        if (fast == nullptr)
            return head->next;
        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        if (slow->next)
        {
            slow->next = slow->next->next;
        }
        else
        {
            slow->next = nullptr;
        }

        return head;
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
    sol.removeNthFromEnd(head, 2);

    cout << "List after deletion: ";
    printList(head);

    return 0;
}
