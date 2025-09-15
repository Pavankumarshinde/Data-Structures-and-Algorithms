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
        int k;
        cin >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int i = 0;
        int count = 0;
        int hike = 0;
        while (i < n)
        {
            if (a[i] == 0)
            {
                count++;
                if (count == k)
                {
                    hike++;
                    count = 0;
                    i++;
                }
            }
            else
            {
                count = 0;
            }
            i++;
        }
        cout << hike << endl;
    }

    return 0;
}