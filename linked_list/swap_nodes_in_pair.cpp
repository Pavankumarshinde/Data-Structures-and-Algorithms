#include <iostream>
#include <vector>

using namespace std;

//   Definition for singly-linked list.
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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *current = head;
        ListNode *pre = nullptr;
        while (current && current->next)
        {
            ListNode *first = current;
            ListNode *second = current->next;

            first->next = second->next;
            second->next = first;
            if (pre)
            {
                pre->next = second;
            }
            else
            {
                head = second;
            }

            pre = first;
            current = first->next;
        }
        return head;
    }
};
int main()
{

    return 0;
}