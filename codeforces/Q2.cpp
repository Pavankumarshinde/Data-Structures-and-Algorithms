#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
int main()
{
    int testcases;
    cin >> testcases;
    for (int t = 0; t < testcases; t++)
    {
        long long n;
        cin >> n;
        long long i = 10;
        vector<long long> sol;
        while (i <= n)
        {
            long long x = n / (i + 1);
            long long reminder = n % (i + 1);
            if (x != 0 && reminder == 0)
            {
                sol.push_back(x);
            }
            i = i * 10;
        }
        cout << sol.size() << endl;
        reverse(sol.begin(), sol.end());
        for (long long j = 0; j < sol.size(); j++)
        {
            if (j != sol.size() - 1)
            {
                cout << sol[j] << " ";
            }
            else
                cout << sol[j];
        }
        if (sol.size() != 0)
            cout << endl;
    }

    return 0;
}