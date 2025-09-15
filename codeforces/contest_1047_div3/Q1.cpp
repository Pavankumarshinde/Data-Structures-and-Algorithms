#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int testcases;
    cin >> testcases;
    for (int test = 0; test < testcases; test++)
    {
        long long k, x;
        cin >> k;
        cin >> x;
        for (int i = 0; i < k; i++)
        {
            x = x * 2;
        }
        cout << x << endl;
    }
    return 0;
}
