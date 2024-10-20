#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Maxsize 10000
#define maxrow 100
#define maxcol 100
char grid[maxrow][maxcol];
int p = 0, q = 0;

void printgrid();

struct deque
{
    int arr[Maxsize];
    int *head;
    int *tail;
    int size;
};
void initialize(struct deque *A)
{

    A->head = (A->arr + Maxsize / 2);
    A->tail = (A->arr + Maxsize / 2);
    A->size = 0;
}
void add_first(int x, struct deque *A);
int remove_first(struct deque *A);
void add_last(int x, struct deque *A);
void remove_last(struct deque *A);
void printDeque(struct deque *A);

int main()
{

    struct deque *d = (struct deque *)malloc(sizeof(struct deque));
    struct deque *dj = (struct deque *)malloc(sizeof(struct deque));
    initialize(d);
    initialize(dj);

    FILE *ptr;
    FILE *ans;
    ptr = fopen("maze1.txt", "r");
    ans = fopen("mymaze.txt", "w");

    while (fgets(grid[q], sizeof(grid[q]), ptr))
    {
        q++;
    }
    p = strlen(grid[0]);
    int i_of_S, j_of_S, i_of_E, j_of_E;

    for (int i = 0; i < q; i++)
    {

        for (int j = 0; j < p; j++)
        {
            fscanf(ptr, "%c", &grid[i][j]);
            if (grid[i][j] == 'S')
            {
                i_of_S = i;
                j_of_S = j;
            }
            if (grid[i][j] == 'E')
            {
                i_of_E = i;
                j_of_E = j;
            }
        }
    }
    *d->head = (i_of_S);
    *dj->head = (j_of_S);

    int m = *d->head, n = *dj->head;
    add_first(m, d);
    add_first(n, dj);
    int distance_of_head, distance_of_point;

    while (d->size > 0)
    {

        int e = remove_first(d);
        int f = remove_first(dj);

        if ((e == i_of_E && f == j_of_E))
        {
            break;
        }

        if (grid[e][f] == '#' || grid[e][f] == '.')
        {
            continue;
        }
        else
        {
            distance_of_head = (e - i_of_E) * (e - i_of_E) + (f - j_of_E) * (f - j_of_E);
            if (e == i_of_S && f == j_of_S)
            {
                grid[e][f] = 'S';
            }
            else
            {
                grid[e][f] = '.';
            }

            int arr1[] = {0, 0, 1, -1};
            int arr2[] = {1, -1, 0, 0};
            for (int i = 0; i < 4; i++)
            {
                m = e + arr1[i];
                n = f + arr2[i];

                distance_of_point = (m - i_of_E) * (m - i_of_E) + (n - j_of_E) * (n - j_of_E);
                if ((grid[m][n] != '#' || grid[m][n] != '.') && distance_of_point < distance_of_head)
                {
                    add_first(m, d);
                    add_first(n, dj);
                }
                else
                {
                    if ((grid[m][n] != '#' || grid[m][n] != '.'))
                    {

                        add_last(m, d);
                        add_last(n, dj);
                    }
                }
            }
        }
    }

    for (int i = 0; i < q; i++)
    {
        for (int j = 0; j < p; j++)
        {

            fprintf(ans, "%c", grid[i][j]);
        }
    }

    printf("\n");
    printgrid();
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
    }
    else
    {
        printf("overFlow\n");
    }
    // printDeque(A);
}
int remove_first(struct deque *A)
{
    if (0 < A->size && A->size <= Maxsize)
    {
        int x;
        x = *A->head;
        if (A->head != A->arr)
        {
            A->head = A->head - 1;
        }
        else
        {
            A->head = A->arr + Maxsize - 1;
        }
        A->size--;
        return x;
    }
    else
    {
        printf("underflow");
    }
    // printDeque(A);
}
void add_last(int x, struct deque *A)
{

    if (-1 < A->size && A->size < Maxsize)
    {
        *A->tail = x;

        if (A->tail != A->arr)
        {
            A->tail = A->tail - 1;
        }
        else
        {
            A->tail = A->arr + Maxsize - 1;
        }

        A->size++;
    }
    else
    {
        printf("overFlow\n");
    }
    // printDeque(A);
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
    }
    else
    {
        printf("underflow");
    }
    // printDeque(A);
}
void printDeque(struct deque *A)
{
    int *ptr;
    ptr = A->tail;

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

void printgrid()
{
    for (int i = 0; i < q; i++)
    {
        for (int j = 0; j < p; j++)
        {

            printf("%c", grid[i][j]);
        }
    }
}

