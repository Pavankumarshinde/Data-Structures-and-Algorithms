// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

#include <stdio.h>
#include <stdlib.h>
#define Maxsize 100
struct Queue
{
    int Arri[Maxsize];
    int Arrj[Maxsize];
    int head;
    int tail;
    int size;
};
void enqueue(int i, int j, struct Queue *queue)
{
    queue->Arri[queue->tail] = i;
    queue->Arrj[queue->tail] = j;
    queue->tail++;
    queue->size++;
}
int dequeue(struct Queue *queue)
{
    queue->size--;
    return queue->head++;
}
void Printgrid(int rows, int cols, int grid[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    puts("");
}
void PrintQueue(struct Queue *queue)
{
    int Head = queue->head;
    for (int i = 0; i < queue->size; i++)
    {
        printf("%d ", queue->Arri[Head + i]);
    }
    puts("");
    for (int i = 0; i < queue->size; i++)
    {
        printf("%d ", queue->Arri[Head + i]);
    }
}

int main()
{

    int cols = 5, rows = 4;
    char board[4][5] = {{'A', 'B', 'C', 'E'},
                        {'S', 'F', 'C', 'S'}, 
                        {'A', 'D', 'E', 'E'}};
    char word[6] = {'A', 'B', 'C', 'C', 'E', 'D'};
    int length = 6;
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int k = 0;
            if (board[i][j] == word[k])
            {

                queue->head = 0;
                queue->tail = 0;
                queue->size = 0;
                

                enqueue(i, j, queue);
                // b[i][j] = -1;
                //  Printgrid(rows,cols,grid);
                while (queue->size > 0)
                {

                    int Head = dequeue(queue);
                    int Arr1[] = {0, 0, 1, -1};
                    int Arr2[] = {1, -1, 0, 0};
                    int got =0;
                    for (int i = 0; i < 4; i++)
                    {
                        
                        if (board[queue->Arri[Head] + Arr1[i]][queue->Arrj[Head] + Arr2[i]] == word[k + 1])
                        {
                            enqueue(queue->Arri[Head] + Arr1[i], queue->Arrj[Head] + Arr2[i], queue);
                            board[queue->Arri[Head] + Arr1[i]][queue->Arrj[Head] + Arr2[i]] = -1;
                            got=1;
                            //  Printgrid(rows,cols,grid);
                        }
                        // if(got)
                                         
                    }
                    if(got)
                    {
                        k++;
                    }
                       printf("%d ", k);

                    // dequeue(queue);
                    //  Printgrid(rows,cols,grid);
                }
                // printf("\n\n1\n\n");
                // Printgrid(rows,cols,grid);
                // PrintQueue(queue);
                // break;
                // k++;
            }
        }
    }
    // printf("%d ", k);
}