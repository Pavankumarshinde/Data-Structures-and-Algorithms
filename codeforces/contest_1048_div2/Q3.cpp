#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        int k;
        long long b;
        cin >> k >> b;
        long long a = (1LL << (k + 1)) - b;

        deque<int> sol;
        while (a != b)
        {
            if (a < b)
            {
                sol.push_front(2);
                b -= a;
                a <<= 1;
            }
            else
            {
                sol.push_front(1);
                a -= b;
                b <<= 1;
            }
        }

        if (sol.empty())
        {
            cout << 0 << "\n";
        }
        else
        {
            cout << sol.size() << "\n";
            for (int x : sol)
                cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
