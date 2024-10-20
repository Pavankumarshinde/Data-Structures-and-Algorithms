#include <iostream>
#include <vector>

using namespace std;
int memorize_fibo(int n, vector<int> &array)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }
    if (array[n] != -1)
    {
        return array[n];
    }
    else
    {
        return array[n] = (memorize_fibo(n - 1, array) + memorize_fibo(n - 2, array));
    }
}
int tabular_fibo(int n, vector<int> &array)
{
    array[0]=0;
    array[1]=1;
    for(int i=2;i<=n;i++)
    {
        array[i]=array[i-1]+array[i-2];
    }
    return array[n];

}
int Best_fico(int n)
{
    if(n<=1)
    {
        return n;
    }
    int pre=1;
    int pre2=0;
    int current_fibo=1;
    for(int i=2;i<=n;i++)
    {
        current_fibo= pre2+pre;
        pre2=pre;
        pre=current_fibo;
    }
    return current_fibo;
}
class Solution
{
public:
    int fib(int n)
    {
        vector<int> array(n + 1, -1);

        // return memorize_fibo(n, array);
        // return tabular_fibo(n,array);
        return Best_fico(n);
    }
};
int main()
{
    Solution sol;
    cout << sol.fib(8);
}