// long long int fact(int x) {
//     long long int facto = 1;
//     for (int i = x; i > 0; i--) {
//         facto *= i;
//     }
//     return facto;
// }

// int uniquePaths(int m, int n) {
//     return (int)((fact(m - 1 + n - 1)) / (fact(m - 1) * fact(n - 1)));
// }
#include<stdio.h>

int S(int N,int M)
{
    if(N<=0 || M<=0)
    {
        return 1;
    }
    return S(N,M-1)+S(N-1,M);
}
int main()
{
    // int N=6,M=5;
    // // for( inmt )
    // for(int i=0;i<N;i++)
    // {
    //     for(int j=0;j<M;j++)
    //     {
    //         return 
    //     }
    // }
    printf("%d ",S(3,2));
}