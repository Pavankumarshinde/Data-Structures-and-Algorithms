#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next; // pointer nmaed as next,.
};

void travelser(struct node *ptr)
{
    while (1)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
        if (ptr == NULL)
        {
            break;
        }
    }
    puts("");
}
void addElement(struct node *ptr, int x)
{
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    while (1)
    {
        if (ptr->next == NULL)
        {
            
            ptr->next=head;
            head->data = x;
            head->next=NULL;
            break;
        }
      
        ptr = ptr->next;
        
    }
}
void deleteElement(struct node *ptr,int x)
{
    

    while(1)
    {
          if (ptr->next == NULL)
        {
            break;
        }
       
        if ((ptr->next)->data==x)
        {
            ptr->next=(ptr->next)->next;
            
        
    
            break;
        }
        ptr= ptr->next;
        

    }



}
void Reverse(struct node *ptr)
{
    struct node *a;
    while (1)
    {
        printf("%d ", ptr->data);
        a=ptr;
        a->next->next=ptr;
        ptr = ptr->next;
        if (ptr == NULL)
        {
            break;
        }
    }
    puts("");
}

int main()
{

    struct node *head;
    struct node *second;
    struct node *third;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 7;
    head->next = second;

    second->data = 10;
    second->next = third;

    third->data = 18;
    third->next = NULL;

  
    addElement(head, 7);travelser(head);
    deleteElement(head,5);travelser(head);
    deleteElement(head,10);travelser(head);
    // deleteElement(head,18);travelser(head);
    addElement(head, 7); travelser(head);
    addElement(head, 8);
    // deleteElement(head,10); travelser(head);
    //   travelser(head);
    //   Reverse(head);
    
}

