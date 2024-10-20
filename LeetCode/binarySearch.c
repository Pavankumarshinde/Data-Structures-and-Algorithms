#include <stdio.h>

int main()
{
    int array[5] = {1, 2, 3, 4, 5};
    int n = 5;
    int i=0;
    int x = 2;
    int a = 0, b = 4; 
    while(1)
    {
        i = (a + b) / 2;
    
        if (array[i] > x)
        {
            a = a;
            b = i - 1;
        }
        else if (array[i] < x)
        {
            a = i + 1;
            b = b;
        }
        else
        {
            printf("%d is at %d", x, i);
            break;
        }
        
    }
}
