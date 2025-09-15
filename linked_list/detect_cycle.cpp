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
    bool hasCycle(ListNode *head)
    {
        if (!head)
            return false;
        if (head->next == head)
            return true;
        ListNode *slow = head;
        ListNode *fast = head;
        while (slow && fast)
        {
            slow = slow->next;
            if (fast->next)
                fast = fast->next->next;
            else
                return false;

            if (slow == fast)
                return true;
        }
        return false;
    }
};

int main()
{
    Solution sol;

    // Example 1: No cycle (1 -> 2 -> 3 -> nullptr)
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);

    cout << "List 1 has cycle? " << (sol.hasCycle(head1) ? "Yes" : "No") << endl;

    // Example 2: Cycle exists (1 -> 2 -> 3 -> back to 2)
    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = head2->next; // cycle

    cout << "List 2 has cycle? " << (sol.hasCycle(head2) ? "Yes" : "No") << endl;

    // Example 3: Single node without cycle
    ListNode *head3 = new ListNode(10);
    cout << "List 3 has cycle? " << (sol.hasCycle(head3) ? "Yes" : "No") << endl;

    // Example 4: Single node with cycle (self-loop)
    ListNode *head4 = new ListNode(20);
    head4->next = head4; // cycle to itself
    cout << "List 4 has cycle? " << (sol.hasCycle(head4) ? "Yes" : "No") << endl;

    return 0;
}