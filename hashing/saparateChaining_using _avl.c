#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define n 10

struct NodeOfTree
{
    int key;
    int height;
    struct NodeOfTree *right;
    struct NodeOfTree *left;
    struct NodeOfTree *parent;
};
struct hash
{
    struct NodeOfTree *A[n];
};

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int Treeheight(struct NodeOfTree *ptr)
{
    if (ptr != NULL)
    {
        return 1 + max(Treeheight(ptr->left), Treeheight(ptr->right));
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

struct NodeOfTree *RightRotation(struct NodeOfTree *y)
{
    struct NodeOfTree *x = y->left;
    struct NodeOfTree *T2 = x->right;

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

    y->parent = x;
    if (T2 != NULL)
    {
        T2->parent = y;
    }

    y->height = max(Treeheight(y->left), Treeheight(y->right)) + 1;
    x->height = max(Treeheight(x->left), Treeheight(x->right)) + 1;

    return x;
}

struct NodeOfTree *LeftRotation(struct NodeOfTree *x)
{
    struct NodeOfTree *y = x->right;
    struct NodeOfTree *T2 = y->left;

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

    x->parent = y;
    if (T2 != NULL)
    {
        T2->parent = x;
    }

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

struct NodeOfTree *DeleteNode(struct NodeOfTree *root, int x)
{
    if (root == NULL)
        return root;

    if (x < root->key)
    {
        root->left = DeleteNode(root->left, x);
    }
    else if (x > root->key)
    {
        root->right = DeleteNode(root->right, x);
    }
    else
    {
        if (root->left == NULL)
        {
            struct NodeOfTree *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct NodeOfTree *temp = root->left;
            free(root);
            return temp;
        }

        struct NodeOfTree *temp = root->right;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }

        root->key = temp->key;
        root->right = DeleteNode(root->right, temp->key);
    }

    root->height = max(Treeheight(root->left), Treeheight(root->right) + 1);

    int balance = CheckBalance(root);

    if (balance > 1)
    {
        if (x < root->right->key)
        {
            root->right = RightRotation(root->right);
            return LeftRotation(root);
        }
        else
        {
            return LeftRotation(root);
        }
    }
    if (balance < -1)
    {
        if (x > root->left->key)
        {
            root->left = LeftRotation(root->left);
            return RightRotation(root);
        }
        else
        {
            return RightRotation(root);
        }
    }

    return root;
}

int InorderTraversal(struct NodeOfTree *root)
{
    if (root != NULL)
    {
        InorderTraversal(root->left);
        if (root->key >0)
        {
            printf("%d ", root->key);
        }
        InorderTraversal(root->right);
    }
}

struct NodeOfTree *InsertNode(struct NodeOfTree *ptr, int x)
{
    if (ptr == NULL)
    {
        struct NodeOfTree *root = (struct NodeOfTree *)malloc(sizeof(struct NodeOfTree));
        root->key = x;
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    if (x < ptr->key)
    {
        ptr->left = InsertNode(ptr->left, x);
    }
    else if (x > ptr->key)
    {
        ptr->right = InsertNode(ptr->right, x);
    }

    ptr->height = max(Treeheight(ptr->left), Treeheight(ptr->right) + 1);

    int balance = CheckBalance(ptr);

    if (balance > 1)
    {
        if (x < ptr->right->key)
        {
            return LeftRotation(ptr);
        }
        else
        {
            ptr->right = RightRotation(ptr->right);
            return LeftRotation(ptr);
        }
    }
    if (balance < -1)
    {
        if (x > ptr->left->key)
        {
            return RightRotation(ptr);
        }
        else
        {
            ptr->left = LeftRotation(ptr->left);
            return RightRotation(ptr);
        }
    }

    return ptr;
}



void PrintHashTable(struct hash *HashTable)
{
    for (int i = 0; i < n; i++)
    {
        
        InorderTraversal(HashTable->A[i]);
        
        printf("\n");
    }
}

void insert(int x, struct hash *HashTable)
{
    int index = abs(x % n);

    struct NodeOfTree *newnode = (struct NodeOfTree *)malloc(sizeof(struct NodeOfTree));

    newnode->key = x;
    newnode->parent = NULL;
    newnode->left = NULL;
    newnode->right = NULL;

    if (HashTable->A[index] == NULL)
    {
        HashTable->A[index] = newnode;
    }
    else
    {
        InsertNode(HashTable->A[index], x);
        
    }
    // PrintHashTable(HashTable);
    // puts("");
}

int delete(int x, struct hash *HashTable)
{
    int index = x % n;

    DeleteNode(HashTable->A[index], x);

    // PrintHashTable(HashTable);
}
int Searchnode(struct NodeOfTree * root,int x)
{
    if (x < root->key)
    {
        if(root->left==NULL)
        {
            return -1;
        }
        else
        {
            Searchnode(root->left,x);

        }       
        
    }
    else if (x > root->key)
    {
        if(root->right==NULL)
        {
            return -1;
        }
        else
        {
            Searchnode(root->right,x);

        }   
        
       
    }
    else
    {
        return x%n;
    }


}
int search(int x ,struct hash *HashTable)
{
    int index = x % n;

    return Searchnode(HashTable->A[index], x);

    

}

int main()
{
    srand(time(NULL));
    struct NodeOfTree *root = (struct NodeOfTree *)malloc(sizeof(struct NodeOfTree));
    root->key = 9999;
    FILE *file=fopen("inputfile.txt","r");
    int B[1000];
    


   

    struct hash *HashTable = (struct hash *)malloc(sizeof(struct hash));

    for (int i = 0; i < n; i++)
    {
        HashTable->A[i] = NULL;
    }
    for(int i=0;i<10;i++)
    {
        insert(-i,HashTable);
    }
    for(int i=0;i<1000;i++)
    {
        fscanf(file,"%d\n",&B[i]);
        insert(B[i],HashTable);

    }
      PrintHashTable(HashTable);
    

    

    //    It will print -1 if not found. and print one slot from 0 to 9 to which it belong.

    printf("\n%d ",search(9370349,HashTable));

    delete(9370349,HashTable);
    
    printf("\n%d ",search(9370349,HashTable));
    return 0;
}
