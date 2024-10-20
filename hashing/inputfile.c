#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define n 10000000

int shuffle( int * A)
{
    for(int i=0;i<n;i++)
    {
        int j=i+ rand() %(n-i);
        int temp=A[i];
        A[i]=A[j];
        A[j]=temp;

    }
}
int main() {
    FILE *file;
   
    file=fopen("inputfile.txt","w");
    
    
    
     int *A = ( int*)malloc(n * sizeof( int));  

    if (A == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        A[i] = i + 1;
    }
    shuffle( A);
    for(int i=0;i<1100;i++)
    {
        fprintf(file,"%d\n",A[i]);
        
    }
   



   
    free(A);

    return 0;
}