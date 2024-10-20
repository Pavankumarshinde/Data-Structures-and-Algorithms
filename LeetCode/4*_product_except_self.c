// not done



// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

#include<stdio.h>

int main()
{
    int n=4;
    int nums[]={12,34,42,-1};
    int answers[]={0,0,0,0};
    int Number=34;
    int product=1;
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(j!=i)
        {
            answers[j]=answers[j]*nums[i];

        }
        

    }
    printf("%d",product);
    return 0;
}