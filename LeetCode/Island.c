#include <stdio.h>
#include<stdlib.h>
#define Maxsize 100
struct Queue {
    int Arri[Maxsize];
    int Arrj[Maxsize];
    int head;
    int tail;
    int size;
};
void enqueue(int i,int j,struct Queue * queue)
{
    queue->Arri[queue->tail]=i;
    queue->Arrj[queue->tail]=j;
    queue->tail++;
    queue->size++;

}
int dequeue(struct Queue *queue)
{
    queue->size--;
    return queue->head++;
    

}void Printgrid(int rows,int cols,int grid[rows][cols])
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            printf("%d ",grid[i][j]);

        }
        printf("\n");
    }
    puts("");
}
void PrintQueue(struct Queue *queue)
{
    int Head=queue->head;
    for(int i=0;i<queue->size;i++)
    {
        printf("%d ",queue->Arri[Head+i]);
        

    }
    puts("");
    for(int i=0;i<queue->size;i++)
    {
        printf("%d ",queue->Arri[Head+i]);
        
    }
}


int main()
{
    int rows = 4;
    int cols = 5;
    int grid[4][5] = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1}};
    struct Queue *queue=(struct Queue*)malloc(sizeof(struct Queue));
    int k=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(grid[i][j]==1)
            {
                queue->head=0;
                queue->tail=0;
                queue->size=0;

                enqueue(i,j,queue);
                grid[i][j]=-1;
                //  Printgrid(rows,cols,grid);
                while(queue->size>0)
                {
                    int Head=dequeue(queue);
                    int Arr1[]={0,0,1,-1};
                    int Arr2[]={1,-1,0,0};
                    for(int i=0;i<4;i++)
                    {
                        if(grid[queue->Arri[Head]+Arr1[i]][queue->Arrj[Head]+Arr2[i]]==1)
                        {
                            enqueue(queue->Arri[Head]+Arr1[i],queue->Arrj[Head]+Arr2[i],queue);
                            grid[queue->Arri[Head]+Arr1[i]][queue->Arrj[Head]+Arr2[i]]=-1;
                            //  Printgrid(rows,cols,grid);

                        }
                    }
                    // dequeue(queue);
                    //  Printgrid(rows,cols,grid);

                }
                // printf("\n\n1\n\n");
                // Printgrid(rows,cols,grid);
                // PrintQueue(queue);
                // break;
                k++;



            }

        }
    }
    printf("%d ",k);
}