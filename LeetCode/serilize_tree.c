#include<stdio.h>
#include<stdlib.h>
struct node{
    int value;
    struct node *left;
    struct node * right;

};
int main()
{
    int Arr[10]={NULL,3,5,2,5,2,NULL,2342,23,34};
    int n=10;
    struct node * A[n];
    for(int i=0;i<n;i++)
    {
        A[i]=(struct node*)malloc(sizeof(struct node));
        // A[i]->left=
        A[i]->value=Arr[i];
    }
    for(int i=0;i<n/2;i++)
    {
        

    }
}