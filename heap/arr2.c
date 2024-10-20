#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int W = 0;
int Work = 0;

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
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int Treeheight(struct NodeOfTree *ptr)
{
    if (ptr != NULL) {
        return (1 + max(Treeheight(ptr->left), Treeheight(ptr->right)));
    }
    return -1;
}

int Height(struct NodeOfTree *root)
{
    if (root != NULL) {
        root->height = Treeheight(root);
        return Height(root->parent);
    }
    return 0;
}

void DeleteNode(struct NodeOfTree *ptr, int x)
{
    struct NodeOfTree *root;
    while (ptr->key != x) {
        if (x < ptr->key) {
            ptr = ptr->left;
        } else if (x > ptr->key) {
            ptr = ptr->right;
        }
    }
    if (ptr->right == NULL && ptr->left == NULL) {
        // Case 1: Node has no children
        if (x > ptr->parent->key) {
            ptr->parent->right = NULL;
        } else {
            ptr->parent->left = NULL;
        }
        Height(ptr->parent);
    } else if (ptr->right == NULL && ptr->left != NULL) {
        // Case 2: Node has only left child
        // ... (rest of the Case 2)
    } else if (ptr->right != NULL && ptr->left == NULL) {
        // Case 3: Node has only right child
        // ... (rest of the Case 3)
    } else {
        // Case 4: Node has both left and right children
        // ... (rest of the Case 4)
    }
}

int InorderedTravelser(struct NodeOfTree *root)
{
    if (root != NULL) {
        InorderedTravelser(root->left);
        if (root->key != 9999) {
            printf("%d ", root->key);
        }
        InorderedTravelser(root->right);
    }
}

void Successor(struct NodeOfTree *ptr, int x)
{
    if (ptr != NULL) {
        Successor(ptr->left, x);
        if (ptr->key == x) {
            printf("%d", W);
        }
        W = ptr->key;
        Successor(ptr->right, x);
    }
}

int InsertNode(struct NodeOfTree *ptr, int x)
{
    struct NodeOfTree *root = (struct NodeOfTree *)malloc(sizeof(struct NodeOfTree));

    if (x < ptr->key) {
        // Case 1: Node has no left child
        if (ptr->left == NULL) {
            root->key = x;
            root->left = NULL;
            root->right = NULL;
            ptr->left = root;
            root->parent = ptr;
            Height(root);
        } else {
            // ... (rest of the Case 1)
            return InsertNode(ptr->left, x);
        }
    } else if (x > ptr->key) {
        // Case 2: Node has no right child
        if (ptr->right == NULL) {
            root->key = x;
            root->left = NULL;
            root->right = NULL;
            ptr->right = root;
            root->parent = ptr;
            Height(root);
        } else {
            // ... (rest of the Case 2)
            return InsertNode(ptr->right, x);
        }
    }
}

int ShuffleArray(int A[1000])
{
    for (int i = 0; i < 1000; i++) {
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

    for (int w = 0; w < 100; w++) {
        int A[1000];
        int B[1000];

        for (int i = 0; i < 1000; i++) {
            A[i] = i + 1;
            B[i] = i + 1;
        }

        ShuffleArray(A);
        ShuffleArray(B);

        for (int i = 0; i < 1000; i++) {
            InsertNode(root, A[i]);
        }

        for (int i = 0; i < 100; i++) {
            DeleteNode(root, B[i]);
        }

        InorderedTravelser(root);
        printf(":%d ", root->height);
        puts("");
    }
    return 0;
}