#include <iostream>
#include <bits/stdc++.h>

using namespace std;
static bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}
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
        vector<pair<int, int>> h(n);

        for (int i = 0; i < n; i++)
        {
            cin >> h[i].first;
            h[i].second = i + 1;
        }
        sort(h.begin(), h.end(), compare);
        int i = 0;
        while (k != h[i].second)
        {
            i++;
        }
        // int t = 0;
        int timetook = 0;
        bool check = false;
        for (; i < n - 1; i++)
        {

            timetook += h[i + 1].first - h[i].first;
            if (h[i].first < timetook)
            {
                check = true;
                cout << "NO" << endl;
                break;
            }
        }
        if (check == false)
            cout << "YES" << endl;
    }

    return 0;
}