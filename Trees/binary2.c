#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int work = 0;

struct NodeOfTree
{
    int key;
    int height;
    struct NodeOfTree *right;
    struct NodeOfTree *left;
    struct NodeOfTree *parent;
};
int max(int a, int b)
{
    if (a > b)
    {
        work += 1;
        return a;
    }
    if (b > a)
    {
        work += 1;
        return b;
    }
    return a;
}
int Treeheight(struct NodeOfTree *ptr)
{

    if (ptr != NULL)
    {
        work += 1;
        return (1 + max(Treeheight(ptr->left), Treeheight(ptr->right)));
    }
    return -1;
}
int Height(struct NodeOfTree *root)
{

    if (root != NULL)
    {

        root->height = Treeheight(root);
        return Height(root->parent);
    }
}
void DeleteNode(struct NodeOfTree *ptr, int x)
{
    struct NodeOfTree *root;
    work++;
    while (ptr->key != x)
    {

        work += 1;
        if (x < ptr->key)
        {
            ptr = ptr->left;
        }
        else if (x > ptr->key)
        {
            ptr = ptr->right;
        }
        work++;
    }
    if (ptr->right == NULL && ptr->left == NULL)
    {
        work++;
        if (x > ptr->parent->key)
        {
            ptr->parent->right = NULL;
            ptr->parent = NULL;
        }
        else
        {
            ptr->parent->left = NULL;
            ptr->parent = NULL;
        }
        Height(ptr->parent);
    }
    else if (ptr->right == NULL && ptr->left != NULL)
    {
        work++;
        if (x > ptr->parent->key)
        {
            ptr->parent->right = ptr->left;
            ptr->left->parent = ptr->parent;
            ptr->left = NULL;
            ptr->parent = NULL;
            work += 2;
        }
        else
        {
            ptr->parent->left = ptr->left;
            ptr->left->parent = ptr->parent;
            ptr->left = NULL;
            ptr->parent = NULL;
            work += 2;
        }
        Height(ptr->parent);
    }
    else if (ptr->right != NULL && ptr->left == NULL)
    {
        work++;
        if (x > ptr->parent->key)
        {
            ptr->parent->right = ptr->right;
            ptr->right->parent = ptr->parent;
            work += 2;
        }ptr->left;
                root->right = ptr->right;
                ptr->left->parent = root;
                ptr->right->parent = root;

                root->parent = ptr->parent;
            }
            work += 3;
            ptr->parent == NULL;
            ptr->left = NULL;
            ptr->right = NULL;
      
        else
        {
            ptr->parent->left = ptr->right;
            ptr->right->parent = ptr->parent;
            work += 2;
        }

        ptr->right = NULL;
        ptr->parent = NULL;
        Height(ptr->parent);
    }
    else
    {
        work++;
        root = (ptr->right);
        while (root->left != NULL)
        {
            root = root->left;
            work += 1;
        }
        {
            work++;
            if (x > ptr->parent->key)
            {
                ptr->parent->right = root;
                work += 1;
            }
            else
            {
                ptr->parent->left = root;
                work += 1;
            }
            if (root == ptr->right)
            {
                root->left = ptr->left;
                ptr->left->parent = root;
                root->parent = ptr->parent;
                work += 3;
            }
            else
            {

                if (root->right)
                {
                    root->parent->left = root->right;
                    root->right->parent = root->parent;
                    work += 2;
                }
                else
                {
                    root->parent->left = NULL;
                    work++;
                }
                work += 5;
                Height(root->parent);
                root->left =       Height(root);
        }
    }
}

int InorderedTravelser(struct NodeOfTree *root, FILE *file)
{

    if (root != NULL)
    {
        InorderedTravelser(root->left, file);
        if (root->key != 9999)
        {
            fprintf(file, "%d ", root->key);
        }

        //     if(root->left!=NULL)
        // {
        //     printf("    %d",root->left->key);

        // }
        // if(root->right!=NULL)
        // {
        //      printf("   %d",root->right->key);

        // }

        // printf("%d ",root->left->key);
        // // root->height=Treeheight(root);
        // printf("      ::%d\n",root->height);

        InorderedTravelser(root->right, file);
    }
}

int InsertNode(struct NodeOfTree *ptr, int x)
{
    struct NodeOfTree *root = (struct NodeOfTree *)malloc(sizeof(struct NodeOfTree));

    work++;

    if (x < ptr->key)
    {

        if (ptr->left == NULL)
        {
            work += 2;
            root->key = x;
            root->left = NULL;
            root->right = NULL;
            ptr->left = root;
            root->parent = ptr;
            Height(root);
        }
        else
        {
            return InsertNode(ptr->left, x);
        }
    }
    else if (x > ptr->key)
    {

        work++;
        if (ptr->right == NULL)
        {
            work += 2;
            root->key = x;
            root->left = NULL;
            root->right = NULL;
            ptr->right = root;
            root->parent = ptr;
            Height(root);
        }
        else
        {
            return InsertNode(ptr->right, x);
        }
    }
}
int ShuffleArray(int A[])
{

    for (int i = 0; i < 1000; i++)
    {
        int j = i + rand() % (1000 - i);
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}

int main()
{
    srand(time(NULL));
    struct NodeOfTree *root = (struct NodeOfTree *)malloc(sizeof(struct NodeOfTree));

    FILE *file;
    FILE *file2;
    FILE *heighttt;
    FILE *workk;
    workk = fopen("WorkBst", "w");
    file = fopen("outputBST.txt", "w");
    file2 = fopen("input.txt", "r");
    heighttt = fopen("heightsBST.txt", "w");
    for (int w = 0; w < 100; w++)
    {
        work = 0;

        int A[1000];
        int B[1000];

        // for (int i = 0; i < 1000; i++)
        // {
        //     A[i] = i + 1;
        //     B[i] = i + 1;
        // }
        // puts("");
        // ShuffleArray(A);
        // ShuffleArray(B);
        for (int i = 0; i < 1000; i++)
        {
            fscanf(file2, "%d ", &A[i]);
        }
        fscanf(file2, "\n");
        // puts("");
        for (int i = 0; i < 100; i++)
        {
            fscanf(file2, "%d ", &B[i]);
        }
        fscanf(file2, "\n");
        // puts("");
        for (int i = 0; i < 1000; i++)
        {
            InsertNode(root, A[i]);
        }
        // puts("");

        // DeleteNode(root, 4);
        //  DeleteNode(root,2);

        // InorderedTravelser(root);
        // puts("");
        for (int i = 0; i < 100; i++)
        {

            // scanf("%d ",&temp);
            DeleteNode(root, B[i]);
            // InorderedTravelser(root);
            // puts("");
        }
        fprintf(workk, "%d\n", work);

        InorderedTravelser(root, file);
        fprintf(file, "\n");
        fprintf(heighttt, "%d\n", root->height);
    }
}
