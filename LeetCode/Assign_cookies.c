#include<stdio.h>

int main()
{
    int g[] = {1,2,3,4,5,7};
    int  s[] = {1,3,4,6,2};
    int gSize=6;
    int sSize=5;
    for (int i=0;i<gSize;i++)
    {
        for(int j=i+1;j<gSize;j++)
        {
            if(g[j]<g[i])
            {
                int temp=g[j];
                g[j]=g[i];
                g[i]=temp;
            
            }
        }
    }
    for (int i=0;i<sSize;i++)
    {
        for(int j=i+1;j<sSize;j++)
        {
            if(s[j]<s[i])
            {
                int temp=s[j];
                s[j]=s[i];
                s[i]=temp;
            
            }
        }
    }
    int count=0;
    int k=0;
    for(int i=0;i<gSize;i++)
    {
        for(int j=k;j<sSize;j++)
        if(g[i]<=s[j])
        {
            count++;
            k=j;
            break;


        }
        
    }
    printf("%d ",count);
}