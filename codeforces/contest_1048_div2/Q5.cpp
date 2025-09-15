#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testcases;
    cin >> testcases;
    for (int test = 0; test < testcases; test++)
    {
        int n, k;
        cin >> n >> k; // ✅ read both n and k
        vector<int> p(n - 1);
        for (int i = 0; i < n - 1; i++)
        {
            cin >> p[i];
        }

        sort(p.begin(), p.end());

        int s = 1;
        int count = 1;
        cout << count << " "; // ✅ initial print

        for (int i = 0; i < p.size(); i++)
        {
            if (p[i] <= s)
            {
                count++;
            }
            else
            {
                cout << count << " ";
                s = s + count;
                count = 1;
            }
        }
        cout << count << " ";

        cout << "\n"; // ✅ only one newline per test
    }

    return 0;
}
