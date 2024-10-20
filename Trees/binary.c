#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int W=0;
int Work=0;
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
            ptr->left=NULL;
            ptr->parent=NULL;

        }
        else
        {
            ptr->parent->left = ptr->left;
            ptr->left->parent = ptr->parent;
            ptr->left=NULL;
            ptr->parent=NULL;
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
        ptr->right=NULL;
        ptr->parent=NULL;
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
            if(x>ptr->parent->key)
            {
                ptr->parent->right=root;



            }
            else
            {
                ptr->parent->left=root;
                


            }
            
            if(root==ptr->right)
            {
                root->left=ptr->left;
                ptr->left->parent=root;
                root->parent=ptr->parent;
                
                
                

            }
            else
            {
                if(root->right) {
                root->parent->left=root->right;
                root->right->parent=root->parent;
               }
                else
                {
                    root->parent->left=NULL;

                } 
                Height(root->parent);
                root->left=ptr->left;
                root->right=ptr->right;
                ptr->left->parent=root;
                ptr->right->parent=root;
                
                root->parent=ptr->parent;
                
                

            }
            ptr->parent==NULL;
            ptr->left=NULL;
            ptr->right=NULL;
            Height(root);



        }
      
    }
}


int InorderedTravelser(struct NodeOfTree *root)
{

    if (root != NULL)
    {
        InorderedTravelser(root->left);
        if (root->key != 9999)
        {
            printf("%d ", root->key);
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

        InorderedTravelser(root->right);
    }
}
void Successor(struct NodeOfTree *ptr, int x)
{
    if(ptr!=NULL)
    {
        Successor(ptr->left,x);
        if(ptr->key== x)
        {
            printf("%d",W);
        }
        W=ptr->key;
        Successor(ptr->right,x);
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
    root->key = 9999;
    // int temp = 4;
    // for (int w = 0; w < 100; w++)
    {

        int A[1000];
        int B[1000];

        for (int i = 0; i < 1000; i++)
        {
            A[i] = i + 1;
            B[i] = i + 1;
        }
        puts("");
        ShuffleArray(A);
        ShuffleArray(B);
        for (int i = 0; i < 1000; i++)
        {
            // printf("%d ", A[i]);
        }
        // puts("");
        for (int i = 0; i < 1000; i++)
        {
            // printf("%d ", B[i]);
        }
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
        for(int i=0;i<100;i++)
        {

            // scanf("%d ",&temp);
            DeleteNode(root,B[i] );
            // InorderedTravelser(root);
            // puts("");
        } 
         InorderedTravelser(root);
         printf(":%d ",root->height);

         puts("");
        //  Successor(root,992);

    }
}
