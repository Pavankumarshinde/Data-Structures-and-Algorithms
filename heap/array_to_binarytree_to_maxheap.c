#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct NodeOfTree
{
    int key;
    int height;
    struct NodeOfTree *right;
    struct NodeOfTree *left;
    struct NodeOfTree *parent;
};

void MaxHeapify(struct NodeOfTree *current)
{
    while (current && (current->left || current->right))
    {
        int largest = current->key;
        struct NodeOfTree *largestChild = NULL;

        if (current->left && current->left->key > largest)
        {
            largest = current->left->key;
            largestChild = current->left;
        }

        if (current->right && current->right->key > largest)
        {
            largest = current->right->key;
            largestChild = current->right;
        }

        if (lar-est == current->key)
            break;

        int temp = current->key;
        current->key = largestChild->key;
        largestChild->key = temp;

        current = largestChild;
    }
}

int main()
{
    srand(time(NULL));

    int n = 16;

    int B[] = {0, 16, 14, 10, 8, 7, 9, 3, 2, 4, 1, 6, 5, 11, 12, 13, 15};
    struct NodeOfTree *A[n];

    for (int i = 0; i < n; i++)
    {
        A[i] = (struct NodeOfTree *)malloc(sizeof(struct NodeOfTree));
        A[i]->key = B[i];
        A[i]->parent = NULL;
        A[i]->left = NULL;
        A[i]->right = NULL;
    }

    for (int i = n / 2; i >= 0; i--)
    {
        MaxHeapify(A[i]);
    }

    for (int j = 0; j < n; j++)
    {
        printf("%d ", A[j]->key);
    }

    return 0;
}
