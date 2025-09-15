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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        bool check = false;

        if (a[0] < a[1])
        {
            if (n == 2)
            {
                if (a[1] != 2 * a[0])
                {
                    cout << "NO" << endl;
                    check = true;
                }
            }

            int difference = a[1] - a[0];
            for (int i = 1; i < n; i++)
            {
                if (a[i] - a[i - 1] != difference)
                {
                    check = true;
                    cout << "NO" << endl;
                    break;
                }
            }
        }
        else
        {
            if (n == 2)
            {
                if (a[0] != 2 * a[1])
                {
                    cout << "NO" << endl;
                    check = true;
                }
            }
            int difference = a[0] - a[1];
            for (int i = 1; i < n - 1; i++)
            {
                if (a[i] - a[i + 1] != difference)
                {
                    check = true;
                    cout << "NO" << endl;
                    break;
                }
            }
        }
        if (!check)
            cout << "YES" << endl;
    }
    return 0;
}