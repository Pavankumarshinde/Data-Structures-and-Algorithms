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
        int x;
        cin >> n;
        cin >> x;
        vector<int> door(n);
        for (int i = 0; i < n; i++)
        {
            cin >> door[i];
        }
        int i = 0;
        while (i < n && door[i] == 0)
        {
            i++;
        }
        i = i + x;
        bool check = false;
        while (i < n)
        {
            if (door[i] == 1)
            {
                check = true;
                cout << "No" << endl;
                break;
            }
            i++;
        }
        if (!check)
            cout << "YES" << endl;
    }
    return 0;
}