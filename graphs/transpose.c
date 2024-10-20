#include <stdio.h>
#include<stdlib.h>

#define n 5

typedef struct
{
    int index;
    struct node *next;
}node;
typedef struct 
{
    // int A[n];/
     node A[n];
}List;
void PrintList( List *list)
{
    for(int i=0;i<n;i++)
    {
         node *ptr=( node*)malloc(sizeof( node));
         ptr=&list->A[i];
        while(1)
        {
            printf("%d ",ptr->index);
            if(ptr->next==NULL)
            {
                break;
            }
        }
        puts("");
    }

}
// void addElement( node *ptr, int x)
// {
//      node *head;
//     head = ( node *)malloc(sizeof( node));
//     while (1)
//     {
//         if (ptr->next == NULL)
//         {
            
//             ptr->next=head;
//             head->index = x;
//             head->next=NULL;
//             break;
//         }
      
//         ptr = ptr->next;
        
//     }
// }
int main()
{
     List *list =(List*) malloc(sizeof( List));
    for (int i = 0; i < n; i++)
    {
        list->A[i].index=i;
        list->A[i].next=NULL;
    
    }
    {
        node newnode;
        newnode=malloc(sizeof(node));


    

    }
   
    

    PrintList(list);

}