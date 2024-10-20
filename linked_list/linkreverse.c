#include <stdio.h>
#include <stdlib.h>
#define n 4
struct linked
{
    int data;
    struct linked *ptr;
};
void PrintLinkList(struct linked *head)
{

    struct linked *current = (struct linked *)malloc(sizeof(struct linked));
    current = head;
    while (current)
    {
        printf("%d ", current->data);
        current = current->ptr;
    }
}
struct linked *Reverse(struct linked *head)
{
    struct linked *pre = (struct linked *)malloc(sizeof(struct linked));
    pre = NULL;
    struct linked *next = (struct linked *)malloc(sizeof(struct linked));
    struct linked *current = (struct linked *)malloc(sizeof(struct linked));
    current = head;
    while (current->ptr)
    {
        next = current->ptr;
        current->ptr = pre;
        pre = current;
        current = next;
    }
    current->ptr = pre;

    return current;
}

struct linked *Addnode(struct linked *head, int x)
{
    struct linked *current = (struct linked *)malloc(sizeof(struct linked));
    current = head;
    struct linked *extranode = (struct linked *)malloc(sizeof(struct linked));
    while (current->ptr)
    {
        current = current->ptr;
    }
    current->ptr = extranode;
    extranode->data = x;
    extranode->ptr = NULL;
    return extranode;
}
int main()
{
    struct linked *head = (struct linked *)malloc(sizeof(struct linked));
    struct linked *tail = (struct linked *)malloc(sizeof(struct linked));

    head->data = 0;
    tail = NULL;
    head->ptr = tail;

    tail = Addnode(head, 2);
    tail = Addnode(head, 12);
    tail = Addnode(head, 22);

    PrintLinkList(head);

    puts("");
    tail = Reverse(head);

    PrintLinkList(tail);
}