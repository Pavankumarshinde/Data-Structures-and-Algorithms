#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 1040 

struct hash
{
    int A[n];
};
void PrintHashTable(struct hash *HashTable,FILE *file2)
{

    for (int i = 0; i < n; i++)
    {
        fprintf(file2 ,"%d  %d\n", i, HashTable->A[i]);
    }
}
int Hash1(int x)
{
    return x % n;
}
int Hash2(int x)
{
    return 7 - (x % 7);
}

int insert(struct hash *HashTable, int x)
{
    int i = 1;

    int index = Hash1(x);
    if (HashTable->A[index] == 0)
    {
        HashTable->A[index] = x;
    }
    else
    {

        while (HashTable->A[index] != 0)
        {
            index = (Hash1(x) + i * Hash2(x)) % n;

            i++;
            if (i > n)
            {
                break;
            }
        }
        HashTable->A[index] = x;
    }
}
int delete(struct hash *HashTable, int x)
{
    int i = 1;

    int index = Hash1(x);
    if (HashTable->A[index] == 0)
    {
        return 1;
    }
    else if (HashTable->A[index] == x)
    {
        HashTable->A[index] = -1;
        return i;
    }
    else
    {

        while (HashTable->A[index] != 0 && HashTable->A[index] != x)
        {
            index = (Hash1(x) + i * Hash2(x)) % n;

            i++;
            // printf("%d  %d  %d %d\n",x,Hash1(x),Hash2(x),index);
            if (i > n)
            {
                break;
            }
        }
        if (HashTable->A[index] == 0)
        {
            return 1 * i;
        }
        else if (HashTable->A[index] == x)
        {
            HashTable->A[index] = -1;
            return i;
        }
        else
        {
            // printf("%d ",index);
            return 1 * i;
        }
    }
}
int search(struct hash *HashTable, int x)
{
    int i = 1;

    int index = Hash1(x);
    if (HashTable->A[index] == 0)
    {
        // printf("%d :is Not in Hash Table  \n",x);
        return 1;
    }
    else if (HashTable->A[index] == x)
    {
        // printf("%d :is at index %d  in Hash Table \n ",x,index);
        
        return i;
    }
    else
    {

        while (HashTable->A[index] != 0 && HashTable->A[index] != x)
        {
            index = (Hash1(x) + i * Hash2(x)) % n;

            i++;
           
            
            if (i > n)
            {
                break;
            }
        }
        if (HashTable->A[index] == 0)
        {
            // printf("%d :is Not in Hash Table  \n",x);
            return 1*i;
        }
        else if (HashTable->A[index] == x)
        {
            // printf("%d :is at index %d  in Hash Table\n  ",x,index);


            return i;
        }
        else
        {
            // printf("%d :is not found after  %d  no. of probs\n  ",x,i);
            return 1*i;
        }
    }
    // PrintHashTable(HashTable);
    // puts("");
}
void shuffle(int A[])
{
    for(int i=0;i<1000;i++)
    {
        int j=i+ rand()%(1000-i);
        int temp=A[i];
        A[i]=A[j];
        A[j]=temp;
    }
}
int main()
{

    struct hash *HashTable = (struct hash *)malloc(sizeof(struct hash));
    FILE *file = fopen("inputfile.txt", "r");
    // FILE *file3=fopen("100input_for_unsussesful_search.txt","r");
    FILE * file2=fopen("OpenAddresingOutput.txt","w");
    FILE * searchPrint=fopen("100_successful_searches.txt","w");
    FILE * deleteProbes=fopen("delete_these_keys.txt","w");
    FILE * searchPrint2=fopen("another_100_successful_searches.txt","w");
    FILE *unsuccesfull=fopen("100_unsuccessful_searches.txt","w");
    int B[1100];

    //    saved 0 in all slot as default. for my convience.
    for (int i = 0; i < n; i++)
    {
        HashTable->A[i] = 0;
    }
    for (int i = 0; i < 1100; i++)
    {

        fscanf(file, "%d\n", &B[i]);
        
       
        
    }
     for (int i = 0; i < 1000; i++)
    {

        
        insert(HashTable, B[i]);

        
    }
    
    PrintHashTable(HashTable,file2);
    shuffle(B);

   

    for(int i=0;i<100;i++)
    {
        fprintf(searchPrint,"%d :is found after   %d  no. of probes \n  ",B[i],search(HashTable,B[i]));
    }
    for(int i=0;i<100;i++)
    {
        fprintf(deleteProbes,"%d :is deleted after %d  no. probes are required \n  ",B[i],delete(HashTable,B[i]));
    }
     for(int i=100;i<200;i++)
    {
        fprintf(searchPrint2,"%d :is found after   %d  no. of probes \n  ",B[i],search(HashTable,B[i]));
        
    }
     for(int i=1000;i<1100;i++)
    {
        fprintf(unsuccesfull,"%d :is not found and    %d no. probes are required \n  ",B[i],search(HashTable,B[i]));
        
    }
    



    return 0;
}