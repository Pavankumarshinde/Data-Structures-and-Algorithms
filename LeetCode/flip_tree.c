#include <stdio.h>
#include <stdlib.h>
struct node
{
    int val;
    struct node *left;
    struct node *right;
    // int height;
};
void inorder(struct node *root)
{
    if (root)
    {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}
void flip(struct node *root)
{
    if (root)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp = root->left;
        root->left = root->right;
        root->right = temp;

        flip(root->left);
        flip(root->right);
    }
}
 #define Maxsize 10000
 struct node* CommonAncestor(struct node* root)
 {
     if (root == NULL) {
        return NULL;
    }
    if(root)
    {
      
        struct node * temp1=root->left;
        if(root->left)
        {
            root->left->left=root;

        }
        struct node * temp2=root->right;
        if(root->right)
        {
            root->right->left=root;

        }
        CommonAncestor(temp1);
        CommonAncestor(temp2);
        return root;
        
    }
 }

int main()

{

    int Array[] = {2, 4, 12, 7, 3, 0, 6, 8, -1};
    int n = sizeof(Array) / sizeof(Array[0]);
    struct node *A[n];
    for (int i = 0; i < n; i++)
    {
        A[i] = (struct node *)malloc(sizeof(struct node));
        A[i]->val = Array[i];
    }
    for (int i = 0; i < n / 2; i++)
    {
        A[i]->left = A[2 * i + 1];
        A[i]->right = A[2 * i + 2];
    }
    inorder(A[0]);
    puts("");
    // for(int i=0;i<n;i++)
    // {
    //     struct node * temp=(struct node *)malloc(sizeof(struct node));
    //     temp=A[i]->left;
    //     A[i]->left=A[i]->right;
    //     A[i]->right=temp;

    // }
    CommonAncestor(A[0]);
    // inorder(A[0]);
    // puts("");
    int Arr[Maxsize];
    int B[Maxsize];
    int i=0;
    int j=0;
    struct node *q=A[4];
    struct node *p=A[6];

    while(q)
    {
        Arr[i]=q->val;
        q=q->left;
        i++;
        
    }
    while(p)
    {
        B[j]=p->val;
        p=p->left;
        j++;

    }
    int min=Maxsize;
    for(int w=0;w<i;i++)
    {
        for(int v=0;v<j;v++)
        {
            if(Arr[w]==B[v])
            {
                if(min>Arr[w])
                {
                    min=Arr[w];

                }
                
            }

        }
        // if()

    }
    printf("%d",min);
}