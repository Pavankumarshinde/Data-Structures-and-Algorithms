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
        int h;
        int l;
        cin >> h;
        cin >> l;

        vector<vector<int>> leans(l + 1);
        vector<vector<int>> adjHouse;
        vector<vector<int>> HouseRoad(h + 1);
        for (int i = 0; i < l; i++)
        {
            int a;
            int b;
            cin >> a;
            cin >> b;
            leans[i] = {a, b};
            HouseRoad[a].push_back(i);
            HouseRoad[b].push_back(i);
            adjHouse[a].push_back(b);
            adjHouse[b].push_back(a);
        }
    }

    return 0;
}