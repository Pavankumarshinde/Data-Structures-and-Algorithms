#include<stdio.h>
int main()
{
    int n=10;
    int nums[] = {0,3,7,2,5,8,4,6,0,1};
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(nums[i]>nums[j])
            {
                int temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
            }
        }

    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",nums[i]);
    }
    puts("");
    int MaxK=0;
    for(int i=0;i<n;i++)
    {
        // if(nums[i]-nums[i-1]==1)
        // {


        // }
        int k=0;
        int j=i+1;
        while(nums[j]-nums[j-1]==1)
        {
            k++;
            j++;

        }
        if(k>MaxK)
        {
            MaxK=k;
        }
    }
    printf("%d ",MaxK+1);
}