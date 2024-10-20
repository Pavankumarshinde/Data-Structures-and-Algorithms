/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.*/

#include <stdio.h>

int main()
{
    int n = 6;
    int A[] = {-1, 0, 1, 2, -1, -4};
    for (int i = 0; i < n-2; i++)
    {
        for (int j = i + 1; j < n-2; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if(A[i]+A[j]+A[k]==0)
                {
                    printf("%d %d %d ",A[i],A[j],A[k]);
                    puts("");
                }            
            }
        }
    }
}