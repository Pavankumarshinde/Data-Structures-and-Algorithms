#include <stdio.h>
#include <stdlib.h>
// #include <bool.h>


#define n 5

struct node
{
    int value;
    struct node *next;
};

struct hash
{
    struct node *A[n]; 
};
void PrintHashTable(struct hash *HashTable)
{
    for (int i = 0; i < n; i++)
    {
        struct node *ptr = HashTable->A[i];
        while (ptr != NULL)
        {
            printf("%d ", ptr->value);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void insert(int x, struct hash *HashTable)
{
    int index = abs(x % n);
    
    struct node *newnode = (struct node*)malloc(sizeof(struct node)); 
    
    
    newnode->value = x;
    newnode->next = NULL;

    if (HashTable->A[index]==NULL)
    {
        HashTable->A[index] = newnode;
    }
    else
    {
        struct node *ptr = HashTable->A[index];
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }
    PrintHashTable(HashTable);
    puts("");
}


int delete(int x,struct hash * HashTable)
{
    int index=x%n;
    int  Isthere;
     

        struct node *ptr = HashTable->A[index];
        struct node *temp = HashTable->A[index];
        
        while (ptr != NULL)
        {
            
            if(ptr->value==x)
            {
                Isthere=1;
                if(ptr->next)
                {
                    temp->next=ptr->next;

                }
                else
                {
                    temp->next=NULL;
                }
                ptr->next=NULL;





            }
            else
            {
                Isthere=0;

            }
            temp=ptr;
            ptr = ptr->next;
        }
        if(Isthere==0)
        {
            // printf("%d is not there",x);
        }
        PrintHashTable(HashTable);
        puts("");
        // ptr->next = newnode;
    

}

int main()
{
    struct hash *HashTable = (struct hash *)malloc(sizeof(struct hash));
  

    
    for (int i = 0; i < n; i++) {
        HashTable->A[i]=NULL;
    }
    //  for (int i = 0; i < n; i++) {
    //     HashTable->A[i]->value=0;
    // }

    insert(-1, HashTable);
    insert(-2, HashTable);
    insert(-3, HashTable);
    insert(-4, HashTable);
    insert(0, HashTable);


    insert(21, HashTable);
    insert(23, HashTable);
    insert(25, HashTable);
    insert(27, HashTable);
    insert(29, HashTable);
    insert(31, HashTable);
    insert(33, HashTable);
    insert(35, HashTable);
    insert(37, HashTable);
    insert(38, HashTable);
    // PrintHashTable(HashTable);
    delete(33,HashTable);
     delete(21, HashTable);
    delete(23, HashTable);
    delete(25, HashTable);
    delete(27, HashTable);
    delete(29, HashTable);
    delete(31, HashTable);
    delete(33, HashTable);
    delete(35, HashTable);
    delete(37, HashTable);
    delete(38, HashTable);
    // PrintHashTable(HashTable);

   

    return 0;
}
