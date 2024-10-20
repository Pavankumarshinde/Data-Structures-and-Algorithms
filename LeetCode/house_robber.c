/*You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.*/
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

struct house
{
    int index;
    int data;
};
int Check(int Array_index[], int x,int count, int size)
{
    int B[count+1];
    for(int i=0;i<=count;i++)
    {
        B[i]=abs(Array_index[i]-x);
        if(B[i]<=1)
        {
            return 0;

        }
    }
    return 1;
    
}

int main()
{
    int Arr[] = {};
    int size = sizeof(Arr) / sizeof(Arr[0]);
    struct house *A[size];
    for (int i = 0; i < size; i++)
    {
        A[i] = (struct house *)malloc(sizeof(struct house));
        A[i]->data = Arr[i];
        A[i]->index = i;
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (A[i]->data < A[j]->data)
            {
                // A[i]->data
                struct house *temp;
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
    if (size > 0)
    {
        int total = A[0]->data;
        int Array_index[size];
        int count = 1;
        Array_index[0] = A[0]->index;
        printf("[%d] %d\n",A[0]->index,A[0]->data);
        for (int i = 1; i < size; i++)
        {
            printf("[%d] %d\n", A[i]->index, A[i]->data);
            if (Check(Array_index, A[i]->index,count,size))
            {
                {
                    total = total + A[i]->data;
                    Array_index[count] = A[i]->index;
                    count++;

                    // printf("\n%d",total);
                }
            }
        }
        printf("\n%d", total);
        // return total;
    }
    
}


//   #include <stdio.h>
// #include <stdlib.h>

// struct house {
//     int index;
//     int data;
// };

// int Check(int Array_index[], int x, int count, int size) {
//     int B[count + 1];
//     for (int i = 0; i <= count; i++) {
//         B[i] = abs(Array_index[i] - x);
//         if (B[i] <= 1) {
//             return 0;
//         }
//     }
//     return 1;
// }

// int rob(int* nums, int numsSize) {
//     if (numsSize == 0) {
//         return 0;
//     }

//     int size = numsSize;
//     int Arr[size];
//     for (int i = 0; i < size; i++) {
//         Arr[i] = nums[i];
//     }

//     struct house *A[size];
//     for (int i = 0; i < size; i++) {
//         A[i] = (struct house*)malloc(sizeof(struct house));
//         A[i]->data = Arr[i];
//         A[i]->index = i;
//     }

//     for (int i = 0; i < size; i++) {
//         for (int j = i + 1; j < size; j++) {
//             if (A[i]->data < A[j]->data) {
//                 struct house* temp;
//                 temp = A[i];
//                 A[i] = A[j];
//                 A[j] = temp;
//             }
//         }
//     }

//     if (size > 0) {
//         int total = A[0]->data;
//         int Array_index[size];
//         int count = 1;
//         Array_index[0] = A[0]->index;

//         for (int i = 1; i < size; i++) {
//             if (Check(Array_index, A[i]->index, count, size)) {
//                 total = total + A[i]->data;
//                 Array_index[count] = A[i]->index;
//                 count++;
//             }
//         }

//         // Free allocated memory
//         for (int i = 0; i < size; i++) {
//             free(A[i]);
//         }

//         return total;
//     }

//     // Free allocated memory
//     for (int i = 0; i < size; i++) {
//         free(A[i]);
//     }

//     return 0;
// }
