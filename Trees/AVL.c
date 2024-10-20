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
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    if (b > a)
    {
        return b;
    }
    return a;
}
int Treeheight(struct NodeOfTree *ptr)
{

    if (ptr != NULL)
    {
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

int InorderedTravelser(struct NodeOfTree *root, FILE *file)
{

    if (root != NULL)
    {
        InorderedTravelser(root->left, file);
        if (root->key != 9999)
        {
            fprintf(file, "%d ", root->key);

            // if (root->left != NULL)
            // {
            //     printf("    %d", root->left->key);
            // }
            // if (root->right != NULL)
            // {
            //     printf("   %d", root->right->key);
            // }

            // printf("%d ",root->left->key);
            // root->height = Treeheight(root);
            // printf("      ::%d\n", root->height);
        }
        InorderedTravelser(root->right, file);
    }
}

struct NodeOfTree *RightRotation(struct NodeOfTree *y)
{
    struct NodeOfTree *x = y->left;
    struct NodeOfTree *T2 = x->right;

    // Update parent pointers
    x->parent = y->parent;
    if (y->parent != NULL)
    {
        if (y == y->parent->left)
        {
            y->parent->left = x;
        }
        else
        {
            y->parent->right = x;
        }
    }

    x->right = y;
    y->left = T2;

    // Update parent pointers for children
    y->parent = x;
    if (T2 != NULL)
    {
        T2->parent = y;
    }

    // Update heights
    y->height = max(Treeheight(y->left), Treeheight(y->right)) + 1;
    x->height = max(Treeheight(x->left), Treeheight(x->right)) + 1;

    return x;
}

struct NodeOfTree *LeftRotation(struct NodeOfTree *x)
{
    struct NodeOfTree *y = x->right;
    struct NodeOfTree *T2 = y->left;

    // Update parent pointers
    y->parent = x->parent;
    if (x->parent != NULL)
    {
        if (x == x->parent->left)
        {
            x->parent->left = y;
        }
        else
        {
            x->parent->right = y;
        }
    }

    y->left = x;
    x->right = T2;

    // Update parent pointers for children
    x->parent = y;
    if (T2 != NULL)
    {
        T2->parent = x;
    }

    // Update heights
    x->height = max(Treeheight(x->left), Treeheight(x->right)) + 1;
    y->height = max(Treeheight(y->left), Treeheight(y->right)) + 1;

    return y;
}

int CheckBalance(struct NodeOfTree *ptr)
{
    int RightHeight = -1;
    int LeftHeight = -1;
    if (ptr->left)
    {
        LeftHeight = ptr->left->height;
    }
    if (ptr->right)
    {
        RightHeight = ptr->right->height;
    }

    if (ptr->parent == NULL)
    {
        return 0;
    }
    else
    {
        return RightHeight - LeftHeight;
    }
}
int ForRotation(struct NodeOfTree *ptr, int x)
{
    while (ptr->key != 9999)
    {
        ptr = ptr->parent;
        int C = CheckBalance(ptr);
        if (C > 1 && x > ptr->right->key)
        {
            // left rotaion.
            ptr = LeftRotation(ptr);
        }
        else if (C > 1 && x < ptr->right->key)
        {
            ptr->right = RightRotation(ptr->right);
            ptr = LeftRotation(ptr);
        }
        else if (C < -1 && x < ptr->left->key)
        {
            // right rotataion
            ptr = RightRotation(ptr);
        }
        else if (C < -1 && x > ptr->left->key)
        {
            ptr->left = LeftRotation(ptr->left);
            ptr = RightRotation(ptr);
        }
    }
    Height(ptr->parent);
}

int DeleteNode(struct NodeOfTree *ptr, int x)
{
    struct NodeOfTree *root;
    struct NodeOfTree *temp;

    while (ptr->key != x)
    {
        if (x < ptr->key)
        {
            ptr = ptr->left;
        }
        else if (x > ptr->key)
        {
            ptr = ptr->right;
        }
    }
    if (ptr->right == NULL && ptr->left == NULL)
    {
        if (x > ptr->parent->key)
        {
            ptr->parent->right = NULL;
        }
        else
        {
            ptr->parent->left = NULL;
        }

            Height(ptr->parent);
         temp = ptr->parent;
        ptr->parent = NULL;
            // ForRotation(temp, x);
    }
    else if (ptr->right == NULL && ptr->left != NULL)
    {
        if (x > ptr->parent->key)
        {
            ptr->parent->right = ptr->left;
            ptr->left->parent = ptr->parent;
            ptr->left = NULL;
        }
        else
        {
            ptr->parent->left = ptr->left;
            ptr->left->parent = ptr->parent;
            ptr->left = NULL;
        }
            Height(ptr->parent);
            temp = ptr->parent;
        ptr->parent = NULL;
            // ForRotation(temp, x);

        
    }
    else if (ptr->right != NULL && ptr->left == NULL)
    {
        if (x > ptr->parent->key)
        {
            ptr->parent->right = ptr->right;
            ptr->right->parent = ptr->parent;
        }
        else
        {
            ptr->parent->left = ptr->right;
            ptr->right->parent = ptr->parent;
        }
        ptr->right = NULL;
            Height(ptr->parent);
            temp=ptr->parent;
        ptr->parent = NULL;
            // ForRotation(temp, x);
        

    }
    else
    {
        root = (ptr->right);
        while (root->left != NULL)
        {
            root = root->left;
        }
        {
            if (x > ptr->parent->key)
            {
                ptr->parent->right = root;
            }
            else
            {
                ptr->parent->left = root;
            }

            if (root == ptr->right)
            {
                root->left = ptr->left;
                ptr->left->parent = root;
                root->parent = ptr->parent;
            }
            else
            {
                if (root->right)
                {
                    root->parent->left = root->right;
                    root->right->parent = root->parent;
                }
                else
                {
                    root->parent->left = NULL;
                }
                Height(root->parent);
                root->left = ptr->left;
                root->right = ptr->right;
                ptr->left->parent = root;
                ptr->right->parent = root;
                    // Height(root->parent);
                    // temp=root->parent;
                    //  ForRotation(root, x);
                root->parent = ptr->parent;
            }
            // Height(ptr->parent);
            // temp=ptr->parent;
            // ForRotation(temp, x);
            ptr->parent = NULL;
            ptr->left = NULL;
            ptr->right = NULL;
            Height(root);
        }
    }
}

int InsertNode(struct NodeOfTree *ptr, int x)
{
    struct NodeOfTree *root = (struct NodeOfTree *)malloc(sizeof(struct NodeOfTree));

    if (x < ptr->key)
    {

        if (ptr->left == NULL)
        {

            root->key = x;
            root->left = NULL;
            root->right = NULL;
            ptr->left = root;
            root->parent = ptr;
            Height(root);

            {
                while (ptr->key != 9999)
                {
                    ptr = ptr->parent;
                    int C = CheckBalance(ptr);
                    if (C > 1 && x > ptr->right->key)
                    {
                        // left rotaion.
                        ptr = LeftRotation(ptr);
                    }
                    else if (C > 1 && x < ptr->right->key)
                    {
                        ptr->right = RightRotation(ptr->right);
                        ptr = LeftRotation(ptr);
                    }
                    else if (C < -1 && x < ptr->left->key)
                    {
                        // right rotataion
                        ptr = RightRotation(ptr);
                    }
                    else if (C < -1 && x > ptr->left->key)
                    {
                        ptr->left = LeftRotation(ptr->left);
                        ptr = RightRotation(ptr);
                    }
                }
            }

            Height(root);
        }
        else
        {
            return InsertNode(ptr->left, x);
        }
    }
    else if (x > ptr->key)
    {

        if (ptr->right == NULL)
        {

            root->key = x;
            root->left = NULL;
            root->right = NULL;
            ptr->right = root;
            root->parent = ptr;
            Height(root);
            {
                while (ptr->key != 9999)
                {
                    ptr = ptr->parent;
                    int C = CheckBalance(ptr);
                    if (C > 1)
                    {
                        if (x > ptr->right->key)
                        {
                            // left rotaion.
                            ptr = LeftRotation(ptr);
                        }
                        else
                        {
                            if (x < ptr->right->key)
                            {
                                ptr->right = RightRotation(ptr->right);
                                ptr = LeftRotation(ptr);
                            }
                        }
                    }

                    else if (C < -1)
                    {
                        if (x < ptr->left->key)
                        {
                            // right rotataion
                            ptr = RightRotation(ptr);
                        }
                        else if (x > ptr->left->key)
                        {
                            ptr->left = LeftRotation(ptr->left);
                            ptr = RightRotation(ptr);
                        }
                    }
                }
            }
            Height(root);
        }
        else
        {
            return InsertNode(ptr->right, x);
        }
    }
    else
    {
        while (ptr->key != 9999)
        {
            ptr = ptr->parent;
            int C = CheckBalance(ptr);
            if (C > 1)
            {
                if (x > ptr->right->key)
                {
                    // left rotaion.
                    ptr = LeftRotation(ptr);
                }
                else
                {
                    if (x < ptr->right->key)
                    {
                        ptr->right = RightRotation(ptr->right);
                        ptr = LeftRotation(ptr);
                    }
                }
            }

            else if (C < -1)
            {
                if (x < ptr->left->key)
                {
                    // right rotataion
                    ptr = RightRotation(ptr);
                }
                else if (x > ptr->left->key)
                {
                    ptr->left = LeftRotation(ptr->left);
                    ptr = RightRotation(ptr);
                }
            }
        }
    }
}
int ShuffleArray(int A[])
{

    for (int i = 0; i < 10; i++)
    {
        int j = i + rand() % (10 - i);
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}

int main()
{
    srand(time(NULL));
    struct NodeOfTree *root = (struct NodeOfTree *)malloc(sizeof(struct NodeOfTree));
    root->key = 9999;
    // int temp = 4;
    FILE *file;
    FILE *file2;
    FILE *heighttt;

    file = fopen("output.txt", "w");
    file2 = fopen("input.txt", "w");
    heighttt = fopen("heights.txt", "w");
    for (int w = 0; w < 100; w++)
    {

        int A[1000];
        int B[1000];

        for (int i = 0; i < 1000; i++)
        {
            A[i] = i + 1;
            B[i] = i + 1;
        }
        // puts("");
        ShuffleArray(A);
        ShuffleArray(B);
        for (int i = 0; i < 1000; i++)
        {
            fprintf(file2, "%d ", A[i]);
        }
        fprintf(file2, "\n");
        // puts("");
        for (int i = 0; i < 100; i++)
        {
            fprintf(file2, "%d ", B[i]);
        }
        fprintf(file2, "\n");
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
            // DeleteNode(root,B[i] );
            // InorderedTravelser(root);
            // puts("");
        }
        InorderedTravelser(root, file);
        fprintf(file, "\n");
        fprintf(heighttt, "%d\n", root->height);
    }
}
