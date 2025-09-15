#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int testcases;
    cin >> testcases;
    for (int test = 0; test < testcases; test++)
    {
        int a, b, c, d;
        cin >> a;
        cin >> b;
        cin >> c;
        cin >> d;
        bool check = false;
        if (a < b)
        {
            int divisor = a;
            if (a == 0)
                divisor = 1;
            if (float(b - 2) / divisor > 2 && !check)
            {
                cout << "NO" << endl;
                check = true;
            }
        }
        else
        {
            int divisor = b;
            if (b == 0)
                divisor = 1;
            if (float(a - 2) / divisor > 2 && !check)
            {
                cout << "NO" << endl;
                check = true;
            }
        }

        a = c - a;
        b = d - b;
        if (a < 0 || b < 0 && !check)
        {
            cout << "NO" << endl;
            check = true;
        }
        if (a < b)
        {
            int divisor = a;
            if (a == 0)
                divisor = 1;
            if (float(b - 2) / divisor > 2 && !check)
            {
                cout << "NO" << endl;
                check = true;
            }
        }
        else
        {
            int divisor = b;
            if (b == 0)
                divisor = 1;
            if (float(a - 2) / divisor > 2 && !check)
            {
                cout << "NO" << endl;
                check = true;
            }
        }
        if (!check)
            cout << "YES" << endl;
    }
    return 0;
}