#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for (int t = 0; t < testcases; t++)
    {
        int n;
        cin >> n;
        // cout<<n;c
        int mini = 10;
        while (n != 0)
        {
            int reminder = n % 10;
            // if (reminder != 0)
            mini = min(mini, reminder);

            n = n / 10;
        }
        cout << mini << endl;
    }

    return 0;
}