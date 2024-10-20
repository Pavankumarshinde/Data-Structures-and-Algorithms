// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

#include<stdio.h>

int main()
{
    int Arr[3][4]={{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    // for(int i=0;;)
    int m=3,n=4;
    int B[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            // printf("%d ",Arr)
            B[i][j]=Arr[i][j];
            
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(Arr[i][j]==0)
            {
                for(int k=0;k<n;k++)
                {
                    B[i][k]=0;

                }
                for(int k=0;k<m;k++)
                {
                    B[k][j]=0;

                }
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",B[i][j]);
        }
        puts("");
    }
}