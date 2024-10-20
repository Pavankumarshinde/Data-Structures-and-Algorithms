#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define MAX_LEN 1000
int work = 0;

struct node
{
    int data;
    int height; /* stores the height of subtree rooted current node */
    struct node *left;
    struct node *right;
    struct node *parent;
};
typedef struct node node;

node *search(node *root, int key) // Searches the AVL tree for a given key
{
    work += 1;
    if (root->data == key)
    {

        return root;
    }
    else if (root->right != NULL && key > root->data)
        return search(root->right, key);
    else if (root->left != NULL)
        return search(root->left, key);
    else
    {
        printf("Key not found! ");
        return NULL;
    }
}
node *getNewNode(int val) // Function to create new node in heap and get pointer to it
{
    work += 4;
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->right = newNode->left = NULL;
    newNode->height = 1;
    node *parent = NULL;
    return newNode;
}
int max(int a, int b)
{
    work += 1;
    if (a > b)
        return a;
    else
        return b;
}
int getHeight(node *a) // Tells the height of a node
{
    if (a == NULL)
        return 0;
    else
        return a->height;
}
void updateHeights(node *key) // Updates the heights of the nodes
{
    work += 1;
    while (key != NULL)
    {
        work++;
        key->height = 1 + max(getHeight(key->left), getHeight(key->right));
        key = key->parent;
        work++;
    }
}

node *rotate(node **root, node *parent_pass, node *child_pass) // Rotates the parent and child
{
    work += 4;
    node *pa = parent_pass;
    node *pap = pa->parent;
    node *ch = child_pass;
    node *cr = ch->right;
    node *cl = ch->left;
    if (pa->right == ch)
    {
        pa->right = cl;
        if (cl != NULL)
            cl->parent = pa;
        ch->left = pa;
        ch->parent = pa->parent;
        pa->parent = ch;
        work += 4;
        if (pap != NULL)
        {
            if (pap->right == pa)
                pap->right = ch;
            else
                pap->left = ch;
        }
        else
            *root = ch;
        work += 2;
    }
    else
    {
        pa->left = cr;
        if (cr != NULL)
            cr->parent = pa;
        ch->right = pa;
        ch->parent = pa->parent;
        pa->parent = ch;
        work += 4;
        if (pap != NULL)
        {
            if (pap->right == pa)
                pap->right = ch;
            else
                pap->left = ch;
        }
        else
            *root = ch;
        work += 2;
    }
    return ch;
}

void rectify(node **root, node *key) // Balances an AVL tree
{
    node *temp = key;
    work += 1;
    while (temp != NULL)
    {
        int lheight = getHeight(temp->left), rheight = getHeight(temp->right);
        work++;
        if (lheight > rheight + 1)
        {
            if (getHeight(temp->left->left) >= getHeight(temp->left->right))
            {
                work += 1;
                temp = rotate(root, temp, temp->left);
                updateHeights(temp->right);
            }
            else
            {
                work += 2;
                temp->left = rotate(root, temp->left, (temp->left->right));
                updateHeights(temp->left->left);
                temp = rotate(root, temp, (temp->left));
                updateHeights(temp->right);
            }
        }
        else if (rheight > lheight + 1)
        {
            work += 1;
            work += 1;
            if (getHeight(temp->right->right) >= getHeight(temp->right->left))
            {
                work += 1;
                temp = rotate(root, temp, temp->right);
                updateHeights(temp->left);
            }
            else
            {
                work += 2;
                temp->right = rotate(root, (temp->right), (temp->right->left));
                updateHeights(temp->right->right);
                temp = rotate(root, temp, (temp->right));
                updateHeights(temp->left);
            }
        }
        temp = temp->parent;
        work += 1;
    }
}
void insert(node **root, int key) // inserts an element at the correct position in a tree
{
    node **temp = root, *curparent = NULL;
    work += 2;
    while (*temp != NULL)
    {
        work += 3;
        curparent = *temp;
        if (key >= (*temp)->data)
            temp = &((*temp)->right);
        else
            temp = &((*temp)->left);
    }
    work += 1;
    *temp = getNewNode(key);
    (*temp)->parent = curparent;
    work += 1;
    updateHeights(*temp);
    rectify(root, *temp);
}

node *treeMinRParent(node *root) // Returns parent of minimum node of a tree
{
    node *prev = NULL;
    if (root == NULL)
        return NULL;
    while (root->left != NULL)
    {
        prev = root;
        root = root->left;
        work += 2;
    }
    return prev;
}

node *delete(node **root, int key) // deletes a given node from AVL tree
{
    node *temp = *root;
    node *parent1 = NULL;
    work += 2;
    while (temp != NULL)
    {
        work += 1;
        if (temp->data == key)
        {
            work++;
            if (temp->right == NULL)
            {
                if (parent1 == NULL)
                {
                    work += 1;
                    *root = temp->left;
                }
                else
                {
                    work += 2;
                    if (temp == parent1->left)
                        parent1->left = temp->left;
                    else
                        parent1->right = temp->left;
                }
                if (temp->left != NULL)
                    temp->left->parent = parent1;
                updateHeights(parent1);
                rectify(root, parent1);
                work += 2;
            }
            else if (temp->left == NULL)
            {
                work += 1;
                if (parent1 == NULL)
                {
                    *root = temp->right;
                }
                else
                {
                    if (temp == parent1->left)
                        parent1->left = temp->right;
                    else
                        parent1->right = temp->right;
                    work += 2;
                }
                work += 2;
                if (temp->right != NULL)
                    ;
                temp->right->parent = parent1;
                updateHeights(parent1);
                rectify(root, parent1);
            }
            else
            {
                node *minP = treeMinRParent(temp->right);
                if (minP == NULL)
                {
                    temp->right->left = temp->left;
                    temp->left->parent = temp->right;
                    work += 2;
                    if (parent1 == NULL)
                    {
                        *root = temp->right;
                        work += 1;
                    }
                    else
                    {
                        if (temp == parent1->left)
                            parent1->left = temp->right;
                        else
                            parent1->right = temp->right;
                        work += 2;
                    }
                    if (temp->right != NULL)
                        temp->right->parent = parent1;
                    work += 1;
                    updateHeights(parent1);
                    rectify(root, parent1);
                }
                else
                {
                    node *temp1 = minP->left->right;
                    minP->left->left = temp->left;
                    minP->left->right = temp->right;
                    temp->left->parent = minP->left;
                    temp->right->parent = minP->left;
                    work += 5;

                    if (parent1 == NULL)
                    {
                        *root = minP->left;
                        work += 1;
                    }
                    else
                    {
                        if (temp == parent1->left)
                            parent1->left = minP->left;
                        else
                            parent1->right = minP->left;
                        work += 2;
                    }
                    if (minP->left != NULL)
                        minP->left->parent = parent1;
                    minP->left = temp1;
                    updateHeights(minP);
                    rectify(root, minP);
                    work += 2;
                }
            }
            free(temp);
            // printf("Deleted\n");
            break;
        }
        else if (key > temp->data)
        {
            parent1 = temp;
            temp = temp->right;
            work += 2;
        }

        else
        {
            work += 2;
            parent1 = temp;
            temp = temp->left;
        }
    }
}

node *Inorder(node *root, FILE *file) // printing
{
    if (root)
    {
        Inorder(root->left, file);
        fprintf(file, "%d ", root->data);
        Inorder(root->right, file);
    }
}
int main()
{
    FILE *file;
    FILE *file2;
    FILE *heighttt;
    FILE *workk;
    workk = fopen("WorkAvl", "w");
    file = fopen("outputAVl.txt", "w");
    file2 = fopen("input.txt", "r");
    heighttt = fopen("heightsAVL.txt", "w");
    for (int w = 0; w < 100; w++)
    {
        work = 0;
        srand(time(NULL));
        node *root = NULL;

        int A[1000];
        int B[1000];

        // for (int i = 0; i < 1000; i++)
        // {
        //     A[i] = i + 1;
        //     B[i] = i + 1;
        // }
        for (int i = 0; i < 1000; i++)
        {
            fscanf(file2, "%d ", &A[i]);
        }
        for (int i = 0; i < 100; i++)
        {
            fscanf(file2, "%d ", &B[i]);
        }

        // ShuffleArray(A);
        // ShuffleArray(B);

        fscanf(file2, "\n");

        fscanf(file2, "\n");

        for (int i = 0; i < 1000; i++)
        {
            insert(&root, A[i]);
        }

        for (int i = 0; i < 100; i++)
        {

            delete (&root, B[i]);
        }
        Inorder(root, file);
        // levelByLevel(root);
        fprintf(file, "\n");
        fprintf(workk, "%d\n", work);
        fprintf(heighttt, "%d\n", root->height);
    }
}