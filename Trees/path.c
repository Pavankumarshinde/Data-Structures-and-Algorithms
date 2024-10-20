#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int pathsum = 0;
int Total = 0;
struct NodeOfTree
{
    int key;
    int height;
    int total;
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
void DeleteNode(struct NodeOfTree *ptr, int x)
{
    struct NodeOfTree *root;
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
        if (x > ptr->parent->key)
        {
            ptr->parent->right = ptr->left;
            ptr->left->parent = ptr->parent;
            ptr->left = NULL;
            ptr->parent = NULL;
        }
        else
        {
            ptr->parent->left = ptr->left;
            ptr->left->parent = ptr->parent;
            ptr->left = NULL;
            ptr->parent = NULL;
        }
        Height(ptr->parent);
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
        ptr->parent = NULL;
        Height(ptr->parent);
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

                root->parent = ptr->parent;
            }
            ptr->parent == NULL;
            ptr->left = NULL;
            ptr->right = NULL;
            Height(root);
        }
    }
}
int sum(struct NodeOfTree *root)
{
    pathsum = 0;

    while (root != NULL)
    {
        pathsum = root->key + pathsum;
        root = root->parent;
    }
    return pathsum;
}
int sumleft(struct NodeOfTree *root)
{
    pathsum = 0;

    while (root != NULL)
    {
        pathsum = root->key + pathsum;
        root = root->left;
    }
    return pathsum;
}
int sumRight(struct NodeOfTree *root)
{
    pathsum = 0;

    while (root != NULL)
    {
        pathsum = root->key + pathsum;
        root = root->right;
    }
    return pathsum;
}

int InorderedTravelserParent(struct NodeOfTree *root)
{

    // int total;
    if (root != NULL)
    {
        InorderedTravelserParent(root->left);
        // if (root->key != 9999)
        // {
        //     printf("%d ", root->key);
        // }
        if (root->right == NULL && root->left == NULL)
        {

            root->total = sum(root);
            if (root->total > Total)
            {
                Total = root->total;
            }
        }
      
        InorderedTravelserParent(root->right);
    }
}
int InorderedTravelserLeft(struct NodeOfTree *root)
{

    // int total;
    if (root != NULL)
    {
        InorderedTravelserLeft(root->right);
        // if (root->key != 9999)
        // {
        //     printf("%d ", root->key);
        // }
        if (root->right == NULL && root->parent == NULL)
        {

            root->total = sumleft(root);
            if (root->total > Total)
            {
                Total = root->total;
            }
        }
      
        InorderedTravelserLeft(root->parent);
    }
}
int InorderedTravelserRight(struct NodeOfTree *root)
{

    // int total;
    if (root != NULL)
    {
        InorderedTravelserRight(root->parent);
        // if (root->key != 9999)
        // {
        //     printf("%d ", root->key);
        // }
        if (root->left == NULL && root->parent == NULL)
        {

            root->total = sumRight(root);
            if (root->total > Total)
            {
                Total = root->total;
            }
        }
      
        InorderedTravelserRight(root->left);
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
        }
        else
        {
            return InsertNode(ptr->right, x);
        }
    }
}
int makingroot(struct NodeOfTree *root)
{
    if (root)

    {
        makingroot(root->left);
        if (root->right == NULL && root->left == NULL)
        {
            InorderedTravelserParent(root);
        }
        if (root->right == NULL && root->parent == NULL)
        {
            InorderedTravelserLeft(root);
        }
        if (root->parent == NULL && root->left == NULL)
        {
            InorderedTravelserRight(root);
        }
        makingroot(root->right);
    }
}

int main()
{
    srand(time(NULL));
    struct NodeOfTree *root = (struct NodeOfTree *)malloc(sizeof(struct NodeOfTree));
    root->key = 0;
    InsertNode(root, 9);
    InsertNode(root, -5);
    InsertNode(root, 81);
    InsertNode(root, 80);
    makingroot(root);
    // InorderedTravelser(root);

    printf("max path%d :", Total);
}
