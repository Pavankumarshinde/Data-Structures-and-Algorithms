// done

// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

#include<stdio.h>
#include<stdbool.h>

int  main()
{
    int n=4;
    bool Repeat=false;
    int nums[]={1,2,3,1};
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(nums[i]==nums[j])
            {
                Repeat=true;
                break;
            }
            


        }
    }
    if(Repeat)
    {
        printf("true");

    }
    else
    {
        printf("false");

    }

}