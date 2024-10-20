// """1. Part A : Implementation of Deque

// You have to write your own implementation of a deque using an array where you
// will use the ideas of a circular buffer that was discussed in class. This is to ensure

// that you utilize the array space well. The operations of adding and removing ele-
// ments at both ends must run in O(1) average runtime. You need to implement the

// associated manipulator operations : add f irst(x), remove f irst(), add last(x) and
// remove last() and also the required access and constructor functions."""

#include <stdio.h>
#include <stdlib.h>
#define Maxsize 10

struct deque
{
    int arr[Maxsize];
    int *head;
    int *tail;
    int size;
};
void initialize(struct deque *A)
{
    A->head = A->tail = NULL;
    A->head = (A->arr + Maxsize / 2);
    A->tail = A->arr + Maxsize / 2;

    // *(A->head)=4;
    A->size = 0;
}
void add_first(int x, struct deque *A);
void remove_first(struct deque *A);
void add_last(int x, struct deque *A);
void remove_last(struct deque *A);
int printDeque(struct deque *A);

int main()
{

    struct deque *d = (struct deque *)malloc(sizeof(struct deque));
    initialize(d);
    printf("printing size and deque.");

    add_first(78, d);
    add_first(7, d);
    add_last(82, d);
    add_last(8, d);
    add_last(18, d);
    add_first(632, d);
    add_first(6, d);
    add_first(60, d);
    add_first(16, d);
    add_first(26, d);
    add_last(82, d);
    add_last(8, d);
    add_last(18, d);
    add_first(632, d);
    remove_first(d);
    add_last(8, d);
    add_first(5, d);
    remove_first(d);
    remove_first(d);
    add_first(7, d);
    remove_last(d);
    remove_last(d);
    remove_last(d);
    remove_last(d);
    remove_first(d);
    remove_first(d);
    remove_first(d);
    remove_first(d);
    remove_first(d);
    remove_first(d);
    add_first(6, d);
    add_first(60, d);
    add_first(16, d);
    add_first(26, d);
}

void add_first(int x, struct deque *A)
{
    if (-1 < A->size && A->size < Maxsize)
    {

        {
            if (A->head != A->arr + Maxsize - 1)
            {
                A->head = A->head + 1;
            }
            else
            {

                A->head = A->arr;
            }
        }
        *A->head = x;
        A->size++;
        printDeque(A);
    }
    else
    {
        printDeque(A);
        printf("   overflow\n");
    }
}
void remove_first(struct deque *A)
{
    if (0 < A->size && A->size <= Maxsize)
    {

        if (A->head != A->arr)
        {
            A->head = A->head - 1;
        }
        else
        {
            A->head = A->arr + Maxsize - 1;
        }
        A->size--;
        printDeque(A);
    }
    else
    {
        printDeque(A);
        printf("  underflow\n");
    }
}
void add_last(int x, struct deque *A)
{

    if (-1 < A->size && A->size < Maxsize)
    {
        *A->tail = x;

        {
            if (A->tail != A->arr)
            {
                A->tail = A->tail - 1;
            }
            else
            {
                A->tail = A->arr + Maxsize - 1;
            }
        }

        A->size++;
        printDeque(A);
    }

    else
    {
        printDeque(A);
        printf("   overflow\n");
    }
}
void remove_last(struct deque *A)
{
    if (0 < A->size && A->size <= Maxsize)
    {

        if (A->tail != A->arr + Maxsize - 1)
        {
            A->tail = A->tail + 1;
        }
        else
        {
            A->tail = A->arr;
        }
        A->size--;
        printDeque(A);
    }
    else
    {
        printDeque(A);
        printf("  underflow\n");
    }
}
int printDeque(struct deque *A)
{
    int *ptr;
    if (A->tail == A->arr + Maxsize - 1)
    {
        ptr = A->arr;
    }
    else
    {
        ptr = A->tail + 1;
    }

    puts("");
    printf("%d   ", A->size);
    for (int i = 0; i < A->size; i++)
    {
        printf("%d,", *ptr);

        if (ptr != A->arr + Maxsize - 1)
        {
            ptr++;
        }
        else
        {
            ptr = A->arr;
        }
    }
}
