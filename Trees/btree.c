#include<stdio.h>
#include<stdlib.h>

struct node {
    int key1;
    int key2;
    int key3;
    int key4;

    struct node * one;
    struct  node  * two;
    struct node * three;
    struct node * four;
    struct node * five;

};

void Insert(struct node *root ,int x)
{
    if(root==NULL)
    {
        root->key1=x;


    }

    
}

int main()
{
    struct node * root=(struct node *)malloc(sizeof(struct node));

    Insert(root,5);
    Insert(root,3);
    Insert(root,4);


    
}