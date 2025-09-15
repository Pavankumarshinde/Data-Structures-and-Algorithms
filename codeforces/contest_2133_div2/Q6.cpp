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
        bool check = false;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<int> sol;
        for (int i = 0; i < n; i++)
        {
            int k = i;
            for (int j = n - 1; j >= k; j--)
            {
                if (a[j] >= (j - i + 1))
                {
                    sol.push_back(j + 1);
                    k = j + a[j] - 1;
                    i = j + a[j] - 1;
                    break;
                }
            }
            if (k == i)
            {
                check = true;
                cout << "-1" << endl;
            }
        }
        if (!check)
        {
            cout << sol.size() << endl;
            for (int i = 0; i < sol.size(); i++)
            {
                cout << sol[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
