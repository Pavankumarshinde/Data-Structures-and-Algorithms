#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int dp(vector<int> &a, int i, int last, int length)
{
    if (i == a.size())
    {
        if (last != -1 && length != last) // unfinished block
            return 0;
        return length; // return the completed block length if last!=-1
    }

    int nottake = dp(a, i + 1, last, length);
    int take = 0;

    if (last == -1)
    {
        take = dp(a, i + 1, a[i], 1); // start new block with a[i]
    }
    else
    {
        if (a[i] == last)
        {
            if (length + 1 == a[i])
            {
                // complete block formed
                take = length + 1 + dp(a, i + 1, -1, 0);
            }
            else
            {
                take = dp(a, i + 1, a[i], length + 1);
            }
        }
    }
    return max(take, nottake);
}

int main()
{
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        cout << dp(a, 0, -1, 0) << endl;
    }
    return 0;
}
