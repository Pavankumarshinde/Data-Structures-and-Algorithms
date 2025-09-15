#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for (int test = 0; test < testcases; test++)
    {
        int a, b;
        cin >> a;
        cin >> b;
        if (a == b)
        {
            cout << 0 << endl;
        }
        else if (a % b == 0 || b % a == 0)
        {
            cout << 1 << endl;
        }
        else
            cout << 2 << endl;
    }
    return 0;
}
