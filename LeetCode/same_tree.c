#include<stdio.h>
struct node{
    int value;
    struct node *left;
    struct node * right;
    struct node * parent;
};
void Insert(int x,struct node root)
{

}

int main()
{

    struct node * p=(struct node*)malloc(sizeof(struct node));
    struct node * q=(struct node*)malloc(sizeof(struct node));
    p->value=1000;
    p->parent=NULL;
    p->left=NULL;
    p->right=NULL;
    q->value=1000;
    q->parent=NULL;
    q->left=NULL;
    q->right=NULL;

    
    

}