#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int key;
    int data;
    int height;
    struct node *left;
    struct node *right;
};
struct node *Insert(struct node *root, int x)
{
    
    struct node * current = (struct node *)malloc(sizeof(struct node ));
    current=root;
    if (current)
    {
        if (current->key > x)
        {
            if (current->left == NULL)
            {
                struct node * extranode = (struct node *)malloc(sizeof(struct node ));
                extranode->key = x;
                extranode->height = 1;
                extranode->left = NULL;
                extranode->right = NULL;
                current->left = extranode;
            }
            else
            {
                Insert(current->left, x);
            }
        }
        if (current->key < x)
        {
            if (current->right == NULL)
            {
                struct node * extranode = (struct node *)malloc(sizeof(struct node ));
                extranode->key = x;
                extranode->height = 1;
                extranode->left = NULL;
                extranode->right = NULL;

                current->right = extranode;
            }
            else
            {
                Insert(current->left, x);
            }
        }
    }
    else
    {
        struct node * extranode = (struct node *)malloc(sizeof(struct node ));
        extranode->key = x;
        extranode->height = 1;
        extranode->left = NULL;
        extranode->right = NULL;
        root = extranode;
    }
}
void LevelBylevel(struct node *root)
{
}

int main()
{
    struct node *root = (struct node *)malloc(sizeof(struct node ));
    root = NULL;
    Insert(root, 3);
    // printf("%d ",root->key);
    Insert(root, 13);
    Insert(root, 31);
    Insert(root, 23);

    // LevelBylevel(root);
    
}