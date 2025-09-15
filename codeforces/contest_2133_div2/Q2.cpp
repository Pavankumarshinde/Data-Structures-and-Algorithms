#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for (int test = 0; test < testcases; test++)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        long long sol = 0;
        int i = n - 1;
        for (i; i > 0; i -= 2)
        {
            sol += max(a[i], a[i - 1]);
        }
        if (i == 0)
        {
            sol += a[0];
        }
        cout << sol << endl;
    }
}