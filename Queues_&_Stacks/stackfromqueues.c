#include<stdio.h>
#define n 10
int A[n];
int B[n];
void pullOut();
int *head;
int *tell;
int enqueue(int x);
int dequeue();

int main()
{
   
 
    for(int i=0;i<n;i++)
    {
        A[i]=0;
        B[i]=0;
    }
    head=&A[0];
    A[0]=12;
    A[1]=14;
    A[2]=12;
    A[3]=13;
    A[4]=15;
    A[5]=5;

    enqueue(3);
    enqueue(4);
    enqueue(6);
    dequeue();
    dequeue();
    enqueue(9);
    enqueue(10);
    enqueue(67);
    enqueue(67);
    enqueue(67);
     enqueue(3);
    enqueue(4);
    enqueue(6);
    enqueue(88);
    

    for(int i=0;i<n;i++)
    {
        printf("%d,",A[i]);
    }
    printf("\n");
     for(int i=0;i<n;i++)
    {
        printf("%d,",B[i]);
    }
    printf("\n");



}
int enqueue(int x)
{
    if((head-1)<&A[n-1])
    {
    *head=x;
    head=head+1;
    }
    else{

        pullOut();
        
        
    }
    
    
}
int dequeue()
{
//    pullOut();
}
void pullOut()
{
   
    {
        tell=&A[0];
        head=&B[0];
        for(int i=0;i<n;i++){
            B[i]=A[(n-1)-i];
            head=head+1;
        }

    
    // }
    // else{
    //     head=&A[0];
    //     for(int i=0;i<n;i++){
    //         A[i]=B[(n-1)-i];
    //         head=head+1;
    //     }
     }
    

}
