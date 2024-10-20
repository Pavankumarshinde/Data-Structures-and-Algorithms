
#include <iostream>
#include <vector>

using namespace std;



/**
 * Definition for singly-linked list.
 */


struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 /**/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head )
        {
            return head;

        }
        ListNode *current=head;
        ListNode * smaller=nullptr;
        ListNode * greater=nullptr;
        ListNode * Head1=new ListNode();
        ListNode * Head2=new ListNode ();
        while(current)
        {
            if(current->val<x)
            {
                // firstlinked list
                if(!smaller)
                {
                    // smaller->val=current->val;
                    Head1->val=current->val;
                    Head1->next=nullptr;
                    smaller=Head1;
                }
                else
                {
                    ListNode * temp =new ListNode();
                    temp->val=current->val;
                    temp->next=nullptr;
                    smaller->next=temp;
                    smaller=temp;


                }
            }
            else
            {
                // second linked list.
                if(!greater)
                {
                    Head2->val=current->val;
                    Head2->next=nullptr;
                    greater=Head2;
                }
                else
                {
                    ListNode * temp =new ListNode();
                    temp->val=current->val;
                    temp->next=nullptr;
                    greater->next=temp;
                    greater=temp;


                }
            }
            current=current->next;

        }
        if(!smaller)
        {
            return Head2;
        }
        if(!greater)
        {
            return Head1;
        }
        smaller->next=Head2;
        return Head1;
        
    }
};
int main() {
    
    return 0;
}