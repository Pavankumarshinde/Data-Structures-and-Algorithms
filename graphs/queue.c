#include <stdio.h>
#include <stdlib.h>

#define n 3

struct queue
{
    int arr[n];
    int head;
    int tell;
    int size;
};
void printQueue(struct queue *Queue)
{

    for (int i = 0; i < Queue->size; i++)
    {
        printf("%d ", Queue->arr[Queue->head + i]);
    }
    puts("");
}
int enqueue(struct queue *Queue, int x)
{
     if (n>Queue->size && Queue->size >=0)
    {
        Queue->arr[Queue->tell] = x;
        if (Queue->tell < n - 1)
        {
            Queue->tell++;
        }
        else
        {
            Queue->tell = 0;
        }
        Queue->size++;
    }
    else
    {
        printf("queue filled completely");
    }
    // printQueue(Queue);

    
 
}
void dequeue(struct queue *Queue)
{
    if (n>=Queue->size && Queue->size > 0)
    {
        if (Queue->head < n - 1)
        {
            Queue->head++;
        }
        else
        {
            Queue->head = 0;
        }

        Queue->size--;
    }
    // printQueue(Queue);
}

int main()
{
    struct queue *Queue = (struct queue *)malloc(sizeof(struct queue));

    Queue->head = 0;
    Queue->tell = 0;
    Queue->size = 0;
    enqueue(Queue, 4);
    
    enqueue(Queue, 14);
    // dequeue(Queue);
    enqueue(Queue, 24);
    enqueue(Queue, 34);

    
    
}