#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int testcases;
    cin >> testcases;
    for (int test = 0; test < testcases; test++)
    {
        long long a, b;
        cin >> a;
        cin >> b;
        long long maximum = -1;
        for (int i = 1; i <= b; i++)
        {
            if (b % i == 0)
            {
                long long m = b / i + i * a;
                if ((m) % 2 == 0)
                {
                    if (m >= maximum)
                        maximum = max(m, maximum);
                    else
                        break;
                }
            }
        }
        cout << maximum << endl;
    }
    return 0;
}
