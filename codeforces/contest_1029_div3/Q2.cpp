
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for (int t = 0; t < testcases; t++)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n / 2; i++)
        {
            a[i] = (i + 1) * 2 - 1;
        }
        a[n / 2] = n;
        for (int i = n / 2 + 1; i < n; i++)
        {
            a[i] = 2 * (n - i);
        }
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}