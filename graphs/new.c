#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define n 10000 // maximum size of the queue
#define maxrow 100
#define maxcol 100

char grid[maxrow][maxcol];
int p = 0, q = 0;

struct link
{
    int x_cor;
    int y_cor;
    char character;
    struct link *next;
};

struct queue
{
    struct link *Arr[n];
    int head;
    int tell;
    int size;
};

void printgrid()
{
    for (int i = 0; i < q; i++)
    {
        for (int j = 0; j < p; j++)
        {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

void printQueue(struct queue *Queue)
{
    for (int i = 0; i < Queue->size; i++)
    {
        printf("%d %d", Queue->Arr[Queue->head + i]->x_cor, Queue->Arr[Queue->head + i]->y_cor);
        puts("");
    }
    puts("");
}

int enqueue(struct queue *Queue, struct link *x)
{
    if (Queue->size < n && Queue->size >= 0)
    {
        Queue->Arr[Queue->tell] = x;
        if (Queue->tell < n - 1)
        {
            Queue->tell++;
        }
        else
        {
            Queue->tell = 0;
        }
        Queue->size++;
        return 1; // Indicate success
    }
    else
    {
        printf("Queue filled completely\n");
        return 0; // Indicate failure
    }
}

struct link *dequeue(struct queue *Queue)
{
    if (Queue->size > 0)
    {
        struct link *element = Queue->Arr[Queue->head];

        if (Queue->head < n - 1)
        {
            Queue->head++;
        }
        else
        {
            Queue->head = 0;
        }

        Queue->size--;
        return element;
    }
    return NULL;
}

void LinkThese(struct link *x, int i, int j, char c)
{
    struct link *ptr = (struct link *)malloc(sizeof(struct link));
    ptr->x_cor = i;
    ptr->y_cor = j;
    ptr->character = c;
    ptr->next = NULL;

    while (x->next != NULL)
    {
        x = x->next;
    }
    x->next = ptr;
}

int main()
{
    struct queue *Queue = (struct queue *)malloc(sizeof(struct queue));
    Queue->head = 0;
    Queue->tell = 0;
    Queue->size = 0;

    FILE *ptr;
    FILE *ans;
    ptr = fopen("maze1.txt", "r");
    ans = fopen("mymaze.txt", "w");

    while (fgets(grid[q], sizeof(grid[q]), ptr))
    {
        q++;
    }
    p = strlen(grid[0]);
    struct link *AL[(p - 1) * (q - 1)];
    struct link *start = (struct link *)malloc(sizeof(struct link));
    struct link *end = (struct link *)malloc(sizeof(struct link));
    int count = 0;

    for (int i = 0; i < q; i++)
    {
        for (int j = 0; j < p; j++)
        {
            struct link *x = (struct link *)malloc(sizeof(struct link));
            x->x_cor = i;
            x->y_cor = j;
            x->character = grid[i][j];
            x->next = NULL;
            AL[count] = x;

            if (AL[count]->character == 'S')
            {
                start = AL[count];
            }
            if (AL[count]->character == 'E')
            {
                end = AL[count];
            }

            if ((grid[i + 1][j]) != '#')
            {
                LinkThese(x, i + 1, j, grid[i + 1][j]);
            }
            if ((grid[i - 1][j]) != '#')
            {
                LinkThese(x, i - 1, j, grid[i - 1][j]);
            }
            if ((grid[i][j - 1]) != '#')
            {
                LinkThese(x, i, j - 1, grid[i][j - 1]);
            }
            if ((grid[i][j + 1]) != '#')
            {
                LinkThese(x, i, j + 1, grid[i][j + 1]);
            }

            count++;
        }
    }

    enqueue(Queue, start);

    while (Queue->size > 0)
    {
        int ForBreak = 0;
        struct link *current = dequeue(Queue);

        while (current != NULL)
        {
            if (current->character != '.')
            {
                if (enqueue(Queue, current))
                {
                    current->character = '.';
                }
            }
            if (current->character == 'E')
            {
                ForBreak = 1;
                break;
            }
            current = current->next;
        }

        if (ForBreak)
        {
            break;
        }
    }

    // Free allocated memory for links in AL
    for (int i = 0; i < count; i++)
    {
        free(AL[i]);
    }

    // Free memory for the queue
    free(Queue);

    fclose(ptr);
    fclose(ans);

    return 0;
}
