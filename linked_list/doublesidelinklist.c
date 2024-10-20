#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *pre;
    struct node *next;
};

struct node *Addnode(struct node *head, int x)
{
    struct node *current = (struct node *)malloc(sizeof(struct node *));
    current = head;
    while (current->next)
    {
        current = current->next;
    }
    struct node *extranode = (struct node *)malloc(sizeof(struct node *));
    current->next = extranode;
    extranode->pre = current;
    extranode->next = NULL;
    extranode->data = x;
    return extranode;
}
void PrintLink(struct node *head)
{
    struct node *current = (struct node *)malloc(sizeof(struct node *));
    current = head;
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}
void PrintLinkTil(struct node *tail)
{
    struct node *current = (struct node *)malloc(sizeof(struct node *));
    current = tail;
    while (current)
    {
        printf("%d ", current->data);
        current = current->pre;
    }
}
void removenode(struct node *head, int x)
{
    struct node *current = (struct node *)malloc(sizeof(struct node *));
    current = head;
    while (current->next)
    {
        if (current->data == x)
        {
            break;
        }
        current = current->next;
    }
    current->pre->next = current->next;
    current->next->pre = current->pre;
    current->next = NULL;
    current->pre = NULL;
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node *));
    struct node *tail = (struct node *)malloc(sizeof(struct node *));
    head->data = 0;
    head->pre = NULL;
    head->next = NULL;
    tail = Addnode(head, 3);
    tail = Addnode(head, 13);
    tail = Addnode(head, 33);
    PrintLink(head);
    removenode(head, 13);

    puts("");
    PrintLinkTil(tail);
}
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <time.h>
    
    int W = 0;
    int Work = 0;
    
    struct NodeOfTree
    {
        int key;
        int height;
        struct NodeOfTree *right;
        struct NodeOfTree *left;
        struct NodeOfTree *parent;
    };
    
    int max(int a, int b)
    {
        if (a > b) {
            return a;
        }
        else {
            return b;
        }
    }
    
    int Treeheight(struct NodeOfTree *ptr)
    {
        if (ptr != NULL) {
            return (1 + max(Treeheight(ptr->left), Treeheight(ptr->right)));
        }
        return -1;
    }
    
    int Height(struct NodeOfTree *root)
    {
        if (root != NULL) {
            root->height = Treeheight(root);
            return Height(root->parent);
        }
    }
    
    void DeleteNode(struct NodeOfTree *ptr, int x)
    {
        struct NodeOfTree *root;
        while (ptr->key != x) {
            if (x < ptr->key) {
                ptr = ptr->left;
            }
            else if (x > ptr->key) {
                ptr = ptr->right;
            }
        }
        // ... (rest of the DeleteNode function)
    }
    
    int InorderedTravelser(struct NodeOfTree *root)
    {
        if (root != NULL) {
            InorderedTravelser(root->left);
            if (root->key != 9999) {
                printf("%d ", root->key);
            }
            InorderedTravelser(root->right);
        }
    }
    
    // ... (other functions like Successor, InsertNode, and main)
    
    int main()
    {
        // ... (rest of the main function)
    }