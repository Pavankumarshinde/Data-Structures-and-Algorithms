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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        map<int, int> hashset;
        bool check = false;
        for (int i = 0; i < n; i++)
        {
            if (hashset[a[i]] > 0)
            {
                check = true;
                cout << "YES" << endl;

                break;
            }
            hashset[a[i]]++;
        }
        if (!check)
            cout << "NO" << endl;
    }
    return 0;
}
