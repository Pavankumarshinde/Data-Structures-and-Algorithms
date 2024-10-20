#include<stdio.h>
#define n 10
int A[n];
int * tell;
int *head;
int enqueue(int x);
void dequeue();
void printQueue();
int main(){
      
    

    // for(int i=0;i;)
    tell=&A[4];
    head=&A[4];
    enqueue(8);
    enqueue(10);
    enqueue(11);
    enqueue(22);
    enqueue(2);
    enqueue(25);
    enqueue(24);
    enqueue(24);
    enqueue(24);
    enqueue(24);

    dequeue();
    for(int i=0;i<n;i++)
    {
        printf("%d,",A[i]);
    }
    printf("\n");
    printQueue();
  
    
}
int enqueue(int x)
{
    *tell=x;
    
    if(tell!=&A[n-1])
    {tell=tell +1;}
    else{
        tell=&A[0];
    }
    if(tell==head){
        printf("queue fulled");
        return 1;
    }

}
void dequeue()
{
    if(head!=&A[n-1])
    {
        head=head+1;
    }
    else
    {
        head=&A[0];
    }
}
void printQueue()
{
    int *ptr;
    ptr=head;
    while(ptr!=tell){
        printf("%d,",*ptr);
        if(ptr!=&A[n-1]){
            ptr=ptr+1;
        }
        else{
            ptr=&A[0];
        }
        if(ptr==tell){
            break;
        }
    }


}
