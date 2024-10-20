#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 100 // maximum size of queue;
#define maxrow 100
#define maxcol 100

char grid[maxrow][maxcol];
int p = 0, q = 0;

struct node
{
    int x_cor;
    int y_cor;
    struct node *parent;
};
struct queue
{
    struct node Arr[n];
    int head;
    int tell;
    int size;
};
void printQueue(struct queue *Queue)
{

    for (int i = 0; i < Queue->size; i++)
    {
        printf("(%d,%d),", Queue->Arr[Queue->head + i].x_cor, Queue->Arr[Queue->head + i].y_cor);
    }
    puts("");
}
int enqueue(struct queue *Queue, struct node *root)
{
    if (n > Queue->size && Queue->size >= 0)
    {
        Queue->Arr[Queue->tell] = *root;
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
int dequeue(struct queue *Queue)
{
    if (n >= Queue->size && Queue->size > 0)
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
        return Queue->head - 1;
    }
    return -1;
}
struct node insert(struct node *grand, struct node *child)
{

    child->parent = grand;
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
    int i_of_S, j_of_S, i_of_E, j_of_E;

    for (int i = 0; i < q; i++)
    {
        for (int j = 0; j < p; j++)
        {
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

    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->parent = NULL;
    root->x_cor = 1;
    root->y_cor = 2;
    enqueue(Queue, root);
    printQueue(Queue);
    int ForBreak = 0;
    while (Queue->size > 0)
    {
        struct node *grand = (struct node *)malloc(sizeof(struct node));
        int Head = dequeue(Queue);

        grand = &Queue->Arr[Head];
        int Array1[] = {0, 0, 1, -1};
        int Array2[] = {1, -1, 0, 0};
        for (int i = 0; i < 4; i++)
        {
            // if (grid[Queue->Arr[Head].x_cor + Array1[i]][Queue->Arr[Head].y_cor + Array2[i]] == ' ')
            {

                if (grid[Queue->Arr[Head].x_cor + Array1[i]][Queue->Arr[Head].y_cor + Array2[i]] == ' ')
                {
                    struct node *child = (struct node *)malloc(sizeof(struct node));
                    child->parent = grand;
                    child->x_cor = Queue->Arr[Head].x_cor + Array1[i];
                    child->y_cor = Queue->Arr[Head].y_cor + Array2[i];
                    enqueue(Queue, child);

                    grid[Queue->Arr[Head].x_cor + Array1[i]][Queue->Arr[Head].y_cor + Array2[i]] == '.';
                    root = child;
                }
            }
            if (grid[Queue->Arr[Head].x_cor + Array1[i]][Queue->Arr[Head].y_cor + Array2[i]] == 'E')
            {
                ForBreak = 1;

                break;
            }
        }

        printQueue(Queue);

     
        if (ForBreak)
        {
            break;
        }
    }
}