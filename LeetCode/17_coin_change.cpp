/*You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.*/

// #include <stdio.h>
// #define n 5

// int *top;
// int push(int x)
// {
//     *top = x;
//     top = top + 1;
// }
// int poll()
// {
//     // *top=x;
//     top = top - 1;
// }
// int printStack(int *ptr)
// {

//     while (ptr < top)
//     {
//         printf("%d,", *ptr);
//         ptr++;
//     }
// }

// int main()
// {

//     int A[n];
//     for (int i = 0; i < n; i++)
//     {
//         A[i] = 0;
//     }
//     top = &A[0];
//     int *ptr = &A[0];

//     {

//         int amount = 17;
//         int A[] = {1, 3, 5, 7, 20};
        
//         int num = 0;
        
//         for (int i = n - 1; i >= 0; i--)
//         {
//             push(A[n-1]);
            

//             // while (amount >= A[i])
//             // {
//             //     amount = amount - A[i];
//             //     num += 1;
//             // }
//         }
//         // printf("%d ", num);
//     }

//     printStack(ptr);
// }

// #include<stdio.h>

// int max=10000;
int Dp(int sum, int coins[],int N)
{

    int min=max;
    if(sum==0)
    {
        return 1;
    }
    if(sum<0)
    {
        return 0;
    }
    else
    {
        int x=0;
        for(int j=0;j<N;j++)
        {
            if(min>Dp(sum-coins[j],coins,4) + 1)
            {
                min=Dp(sum-coins[j] ,coins,4) + 1;

            }
            
        }

        return min ;
    }
}
// int main()
// {
//     int coins[4]={1,2,5,10};
//     int sum=11;
//     printf("%d",Dp(sum,coins,4));
// }

// #include<stdio.h>
// int dp(int sum, int arr[])
// {
//     if(sum<0)
//     {
//         return 0;
//     }
//     if(sum==0)
//     {
//         return 1;
//     }
//     if(sum==1)
//     {
//         return 1;
//     }
//     if(sum==2)
//     {
//         return 2;
//     }
//     if(sum==3)
//     {
//         return 4;
//     }
//     if(sum==4)
//     {
//         return 8;
//     }
//     if(sum==5)
//     {
//         return 16;
//     }
//     if(sum==6)
//     {
//         return 32;
//     }
//     if (arr[sum] != -1) 
//     {
//         return arr[sum];
//     }
//     return arr[sum] = (dp(sum-1, arr)+dp(sum-2, arr)+dp(sum-3, arr)+dp(sum-4, arr)+dp(sum-5, arr)+dp(sum-6, arr))%1000000007;
    
// }
// int main()
// {
//     int sum;
//     scanf("%d",&sum);
//     int arr[sum + 1];
//     for (int i=0;i<=sum;i++) 
//     {
//         arr[i] = -1;
//     }
//     printf("%d",dp(sum, arr)%1000000007);
// }
#include<iostream>

int dp(int sum,int A[],int n,int j)
{
    
    if(sum<0)
    {
        return 0;
    }
    if( sum==0)
    {
        return 1;

    }
    // for(int i=0;i<n;i++)
    // {
    //     if(sum==A[i])
    //     {
    //         return 1;
    //     }
    // }
    int total=0;
    for(int i=0;i<n;i++)
    {
        if(i!=j)
        {
            total+=dp(sum-A[i],A,n,i);

        }
        

       
        
        
       

    }
    return total;
    

}
int main()
{
    int n;
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d ",&A[i]);

    }
    
    
    int sum=0;

    for(int i=0;i<n;i++)
    {
        sum+=A[i];

    }
    // int Array[sum+1];rt
    // for(int i=0;i<=sum;i++)
    // {
    //     Array[i]=-1;


    // }
    // for(int i=0;i<n;i++)
    // {
    //     Array[sum-A[i]]=A[i];
    // }
    
    printf("%d",dp(sum,A,3,n+1)+n);
    // printf("%d ",sum);
    
    // scanf("%d")
}