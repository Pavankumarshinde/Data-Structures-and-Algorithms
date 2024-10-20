// Given an integer array nums, find the 
// subarray
//  with the largest sum, and return its sum.

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    
    int A[]={-2,1,-3,4,-1,2,1,-5,4};
    int n=sizeof(A)/sizeof(A[0]);
    int B[n];
    int sum=0;

    for(int i=0;i<n;i++)
    {
        B[i]=A[i];
        for(int j=i+1;j<n;j++)
        {
            B[i]+=A[j];

        }
        printf("%d ",B[i]);

        

    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(sum<abs(B[i]-B[j]))
            {
                sum=abs(B[i]-B[j]);
            }
        }

    }
    printf("\n%d",sum);
   
}