#include <stdio.h>

int main()
{

    int Arr[] = {10, 9, 2, 5, 3, 7, 101, 18};

    int size = sizeof(Arr) / sizeof(Arr[0]);
    // for (int k = 0; k < size; k++)
    {

        for (int i = 0; i < size; i++)
        {
            int A[size];
            int count = 0;
            A[count] = Arr[i];

            for (int j = i + 1; j < size; j++)
            {
                if (Arr[j] > Arr[j-1])
                {
                    count++;
                    A[count] = Arr[j];
                }
                else
                {
                    break;
                }
            }
            for(int k=0;k<count+1;k++)
            {
                printf("%d ",A[k]);

            }
            puts("");
        }
    }
}