#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int testcases;
    cin >> testcases;
    for (int test = 0; test < testcases; test++)
    {
        int n;
        cin >> n;
        // long long even = 0;
        // long long odd = 0;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        long long count = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                if (i + 1 < n && a[i] - a[i + 1] > 0)
                {
                    long long temp = (a[i] - a[i + 1]);
                    a[i] -= temp;
                    count += temp;
                }
            }
            else
            {
                if (i + 1 < n && a[i + 1] - a[i] > 0)
                {
                    long long temp = a[i + 1] - a[i];
                    a[i + 1] -= temp;
                    count += temp;
                }
            }
        }
        // cout << endl;
        // for (int i = 0; i < n; i++)
        // {
        //     cout << a[i] << " ";
        // }
        for (int i = 1; i < n - 1; i = i + 2)
        {

            if ((a[i + 1] + a[i - 1]) - a[i] > 0)
            {
                long long temp = a[i + 1] + a[i - 1] - a[i];
                if (a[i + 1] >= temp)
                {
                    a[i + 1] -= temp;
                    count += temp;
                }
                else
                {

                    a[i - 1] = temp - a[i + 1];
                    a[i + 1] = 0;
                    count += temp;
                }
            }
        }
        // cout << endl;
        // for (int i = 0; i < n; i++)
        // {
        //     cout << a[i] << " ";
        // }
        // cout << endl;
        cout << count << endl;
    }
    return 0;
}