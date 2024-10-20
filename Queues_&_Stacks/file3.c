#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int top;
    int size;
    int * arr;
};

int isFull(struct stack * s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack * s, int val)
{
    if (isFull(s))
    {
        printf("Stack overflow\n");
    }
    s->top = s->top + 1;
    s->arr[s->top] = val;
}

void display(struct stack * s)
{
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ",s->arr[i]);
    }
}

int main()
{
    struct stack * s;
    s->top = -1;
    s->size = 5;
    s->arr = (int *)malloc(s->size * sizeof(int));

    push(s, 4);
    push(s, 7);
    push(s, 8);
    push(s, 3);
    printf("Original stack\n");
    display(s);
}
