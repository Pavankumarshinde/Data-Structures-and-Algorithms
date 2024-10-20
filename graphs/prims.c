#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_NODES 5

struct edge
{
    int weight;
};

struct node
{
    int index;
    bool Included;
    struct edge *Arr[MAX_NODES];
};

int main()
{
    int Aj[MAX_NODES][MAX_NODES] = {
        {INT_MAX, 9, 6, 5, 7},
        {9, INT_MAX, 2, 1, 6},
        {6, 2, INT_MAX, 9, 3},
        {5, 1, 9, INT_MAX, 1},
        {7, 6, 3, 1, INT_MAX}};

    struct node *Node[MAX_NODES];

    for (int i = 0; i < MAX_NODES; i++)
    {
        Node[i] = (struct node *)malloc(sizeof(struct node));
        Node[i]->index = i;
        Node[i]->Included = false;

        for (int j = 0; j < MAX_NODES; j++)
        {
            Node[i]->Arr[j] = (struct edge *)malloc(sizeof(struct edge));
            Node[i]->Arr[j]->weight = Aj[i][j];
        }
    }

    int current = 0;
    Node[0]->Included = true;
    int next = 0;

    for (int k = 0; k < MAX_NODES - 1; k++)
    {
        struct edge *smallest = NULL;
        smallest = (struct edge *)malloc(sizeof(struct edge));
        smallest->weight = INT_MAX;

        for (int i = 0; i < MAX_NODES; i++)
        {
            if (Node[current]->Arr[i]->weight < smallest->weight && (!Node[i]->Included))
            {
                smallest->weight = Node[current]->Arr[i]->weight;
                next = i;
            }
        }

        printf("%d %d %d\n",current, next, smallest->weight);
        Node[next]->Included = true;
        current = next;

     
    }

    return 0;
}
