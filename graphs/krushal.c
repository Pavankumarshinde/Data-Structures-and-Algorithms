#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 10

struct node
{
    int index;
    int cycle;
};

struct edge
{
    int weight;
    struct node *i;
    struct node *j;
};
int krushal( int size,int Aj[size][size])
{
    struct node *Node[5];
    for (int i = 0; i < 5; i++)
    {
        Node[i] = (struct node *)malloc(sizeof(struct node));
        Node[i]->cycle = 0;
        Node[i]->index = i;
    }
    struct edge *Edge[5 * 5];
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            // int data = i * 5 + j;
            Edge[count] = (struct edge *)malloc(sizeof(struct edge));
            Edge[count]->weight = Aj[i][j];
            Edge[count]->i = Node[i];
            Edge[count]->j = Node[j];
            count++;
        }
    }
    for (int i = 0; i < (5 * 5); i++)
    {
        printf("%d  %d  %d\n", Edge[i]->weight, Edge[i]->i->index, Edge[i]->j->index);
    }
    puts("");

    // for(int)
    // struct edge *Arr[(5*5-5)/2];
    for (int i = 0; i < (5 * 5); i++)
    {
        for (int j = i + 1; j < (5 * 5); j++)
        {
            if (Edge[i]->weight > Edge[j]->weight)
            {
                struct edge *temp;
                temp = Edge[i];
                Edge[i] = Edge[j];
                Edge[j] = temp;
            }
        }
    }
    for (int i = 0; i < (5 * 5); i++)
    {
        printf("%d  %d  %d\n", Edge[i]->weight, Edge[i]->i->index, Edge[i]->j->index);
    }
    puts("");
    int result = 0;
    // for (int i = 0; i < (5 * 5); i++)
    // {
    //     if (!(Edge[i]->i->cycle >= 1 && Edge[i]->j->cycle >= 1))
    //     {
    //         printf("%d  %d  %d\n", Edge[i]->weight, Edge[i]->i->index, Edge[i]->j->index);
    //         //  printf(" %d %d\n",Edge[i]->i->cycle,Edge[i]->j->cycle);
    //         Edge[i]->i->cycle++;
    //         Edge[i]->j->cycle++;

    //         if (result > (5 - 3))
    //         {
    //             break;
    //         }
    //         result++;
    //     }
    // }
    printf("%d %d %d \n",Edge[0]->weight, Edge[0]->i->index,Edge[0]->j->index);
}
int prims(int size,int Aj[size][size])
{

}
int main()
{
    int Aj[5][5] = {
        {INT_MAX, 2, 3, 5, 7},
        {INT_MAX, INT_MAX, 2, 1, 1},
        {INT_MAX, INT_MAX, INT_MAX, 9, 1},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 1},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX}};

    krushal(5,Aj);
    // prims(5,Aj);


    return 0;
}
