// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

#include <stdio.h>
#include <stdlib.h>

struct item
{
    int i;
    int j;
    int value;
};

int main()
{
    int n = 4;
    int Arr[4][4] = {{1, 2, 3, 4}, {6, 7, 8, 9}, {11, 12, 13, 14}, {16, 17, 18, 19, }};
    int B[4][4];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", Arr[i][j]);
            // printf("%d ",Arr[i][j]);
        }
        printf("\n");
    }
    // puts("");
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         printf("(%d %d)=%d ", (j - n / 2) * 0 + (-(i - n / 2) * 1), (j - n / 2) * -1 + (-(i - n / 2) * 0), Arr[i][j]);
    //         // B[(j-n/2)*0+(-(i-n/2)*1) +n/2][(j-n/2)*-1 +(-(i-n/2)*0) +n/2]=Arr[i][j];
    //     }
    //     puts("");
    // }
    puts("");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // printf("(%d %d) ",i,j);
            B[i][j]=Arr[n/2-(j - n / 2) * 1 + (-(i - n / 2) * 0)][(j - n / 2) * 0 + (-(i - n / 2) * -1)+n/2];
        }
        // puts("");

        }
    puts("");
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         printf("(%d %d) ",n/2-(j - n / 2) * -1 + (-(i - n / 2) * 0),(j - n / 2) * 0 + (-(i - n / 2) * 1)+n/2);
    //         // B[][(j-n/2)*-1 +(-(i-n/2)*0) +n/2]=Arr[i][j];
    //     }
    //     puts("");

    //     }
  
            puts("");
        // }
        
          for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d ",B[i][j]);
                // B[(j-n/2)*-1 +(-(i-n/2)*0) +n/2][(j-n/2)*0+(-(i-n/2)*1) +n/2]=Arr[i][j];

            }
            puts("");

        }
}

