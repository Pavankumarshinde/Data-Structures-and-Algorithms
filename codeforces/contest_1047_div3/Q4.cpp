#include <bits/stdc++.h>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for (int test = 0; test < testcases; test++)
    {
        int n;
        cin >> n;
        vector<int> b(n);
        map<int, vector<int>> hashmap;
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            hashmap[b[i]].push_back(i);
        }

        vector<int> sol(n);
        bool check = false;
        int x = 0;

        for (auto &h : hashmap)
        {
            if (h.second.size() % h.first != 0)
            {
                check = true;
                break;
            }
            int a = h.second.size() / h.first;
            x++;
            for (int k = 0; k < (int)h.second.size(); k++)
            {
                if (k % a == 0 && k > 0 && a > 1)
                    x = x + 1;
                sol[h.second[k]] = x;
            }
        }

        if (check)
            cout << -1 << endl;
        else
        {
            for (int e : sol)
                cout << e << " ";
            cout << endl;
        }
    }
    return 0;
}
