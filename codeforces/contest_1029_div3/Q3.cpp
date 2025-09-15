#include <iostream>
#include <bits/stdc++.h>

using namespace std;
bool condition(map<int, int> &occurance)
{
    for (auto a : occurance)
    {
        if (a.second > 0)
            return false;
    }
    return true;
}
int main()
{
    int testcases;
    cin >> testcases;
    for (int test = 0; test < testcases; test++)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        map<int, int> occurance;
        occurance[a[0]] = 1;
        set<int> s;
        int count = 1;
        s.insert(a[0]);
        for (int i = 1; i < n; i++)
        {
            occurance[a[i]]--;
            if (condition(occurance))
            {
                count++;
                for (auto num : s)
                {
                    occurance[num] = 1;
                }
                continue;
            }
            else
            {
                s.insert(a[i]);
            }
        }
        cout << count << endl;
    }
}