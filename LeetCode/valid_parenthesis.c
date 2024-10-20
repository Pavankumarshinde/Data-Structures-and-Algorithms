#include <stdio.h>
#include<stdlib.h>
#define Maxsize 10000
struct stack
{
    char Array[Maxsize];
    int tail;

};
// for(int )
void PrintStack(struct stack * Stack)
{
    for(int i=0;i<Stack->tail;i++)
    {
        printf("%c ",Stack->Array[i]);
    }
}
void insert(struct stack *Stack,char x)
{
    Stack->Array[Stack->tail]=x;
    Stack->tail++;
}
void pull(struct stack *Stack )
{
    Stack->tail--;
}
int Check(char Arr[Maxsize],int i,struct stack *Stack)
{
    
    
    if(Arr[i]=='{')
    {
        // insert
        insert(Stack,Arr[i]);
        return 1;


    }
    if(Arr[i]=='}')
    {
        // pull
        if(Stack->Array[Stack->tail-1]=='{')
        {
            pull(Stack);
            return 1;
        }
        else
        {
            return 0;
        }

    }
    if(Arr[i]=='[')
    {
        // insert
        insert(Stack,Arr[i]);
        return 1;

    }
    if(Arr[i]==']')
    {
        // pull
        if(Stack->Array[Stack->tail-1] =='[')
        {
            pull(Stack);
            return 1;
        }
        else
        {
            return 0;
        }

    }
}

int main()
{
    char Arr[Maxsize];
    char x;
    int count = 8;
    Arr[0]='{';
    Arr[1]='[';
    Arr[2]=']';
    Arr[3]='[';
    Arr[4]=']';
    Arr[5]='}';
    // Arr[6]='[';

    // while (scanf("%c", &x) && x != '\n')
    // {
    //     Arr[count] = x;
    //     count++;
    // }
    struct stack *Stack=(struct stack*)malloc(sizeof(struct stack));
    Stack->tail=0;
    for(int i=0;i<count-2;i++)
    {
        
        if(Check(Arr,i,Stack)==0)
        {
            printf("Not valid a");
            // break;
        }
        PrintStack( Stack);
        puts("");

        
    }
    if(Stack->tail!=0)
    {
        printf("Not valid");
    }
    // if()

    return 0;
}
