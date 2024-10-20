// done

/*You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.*/

#include<stdio.h>

int main()
{
    int n=9;
    int A[]={1,8,6,2,5,4,8,3,7};
    int water=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int a=A[i];
            int b=A[j];
            if(b<a)
            {
                a=b;
            }

            if(water < a*(j-i))
            {
                water=a*(j-i);
            }
        }

        
    }
    printf("%d ",water);
}