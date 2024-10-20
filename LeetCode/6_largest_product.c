// done

// Given an integer array nums, find a
// subarray
//  that has the largest product, and return the product.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int A[] = {2,3,-2,4};
    // double negativeInf = -INFINITY;
    int n = sizeof(A) / sizeof(A[0]);
    int B[n];
    int max =-INFINITY;
    int Max=-INFINITY;
    // int k=n-1;
    for (int k = 1; k <=n; k++)
    {
        
        for (int i = 0; i < k; i++)
        {
            B[i] = A[i];
            for (int j = i + 1; j < k; j++)
            {
                B[i] = B[i] * A[j];
            }
            if (B[i] > max)
            {
                max = B[i];
            }
        }
        for(int i=k;i<n;i++)
        {
            B[i]=-INFINITY;
        }
        puts("");
        for (int i = 0; i < n; i++)
        {
        printf("%d ", B[i]);
        }
        printf("\n%d ", max);
        if(max>Max)
        {
            Max=max;
        }
    }
    printf("\n%d ", Max);

    
    
}