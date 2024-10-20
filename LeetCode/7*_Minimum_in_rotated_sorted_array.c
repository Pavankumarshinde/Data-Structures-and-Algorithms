/*Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.*/

#include<stdio.h>
#include<math.h>

int main()
{
    int n=5;
    int A[]={3,4,5,1,2};
    int min=A[0];
    for(int i=0;i<;i++)
    {
        int a=0;
        int b=n+1/2;
        
        if(A[a]>A[b])
        {
            // a=a;
            // if(A[b]<min)
            // {
            //     min=A[b];
            // }
            b=(a+b)/2;
            // printf("%d ",min);
            
            

        }
        else if(A[a]<A[b])
        {
            // if(A[a]<min)
            // {
            //     min=A[a];
            // }
            int temp=a;
            a=b;
            b=b+(b-temp);
            // printf("%d ",m/in);
            

        }
        // else
        // {
        //     printf("%d ",min);
        //     break;
        // }

    }

}