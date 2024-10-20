// done

/*You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/
#include<stdio.h>
#include<stdlib.h>
// #include<math.h>
int factorial(int x)
{
    int fact=1;
    for(int i=x;i>0;i--)
    {
        fact=fact *i;

    }
    return fact;
}
int main()
{
    int n=3;
    int total=0;
    for(int i=0;i<n+1;i++)
    {
        
        if((n-i)%2==0)
        {
            int j=(n-i)/2;
            total=total + (factorial(i+j)/(factorial(i)*factorial(j)));
            // (i+j)!/i!j!;
        }


    }
    printf("%d ",total);

}
