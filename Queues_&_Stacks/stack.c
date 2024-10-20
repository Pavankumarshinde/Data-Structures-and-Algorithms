#include<stdio.h>
#define n 10

int *top;
int push(int x);
int poll();
int printStack(int *ptr);

int main()
{
   
    int A[n];
    for(int i=0;i<n;i++)
    {
        A[i]=0;
    }
    top=&A[0];
    int *ptr=&A[0];
    push(3);
    push(4);
    push(6);
    poll();
    poll();
    push(9);
    push(10);
    push(67);
    poll();
    poll();
    for(int i=0;i<n;i++)
    {
        printf("%d,",A[i]);
    }
    printf("\n");
    printStack(ptr);



}
int push(int x)
{
    *top=x;
    top=top+1;
}
int poll()
{
    // *top=x;
    top=top -1;
}
int printStack(int *ptr)
{
   
    while(ptr<top)
    {
        printf("%d,",*ptr);
        ptr++;
    }
}
