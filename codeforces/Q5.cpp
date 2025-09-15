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
        int m;
        int q;

        cin >> n;
        cin >> m;
        cin >> q;
        // cout << n << " " << m << " " << q << endl;
        vector<int> vadim(n);
        for (int i = 0; i < n; i++)
        {
            cin >> vadim[i];
            // cout << vadim[i] << " ";
        }
        sort(vadim.begin(), vadim.end());
        reverse(vadim.begin(), vadim.end());
        // cout << endl;
        vector<int> kostya(m);
        for (int i = 0; i < m; i++)
        {
            cin >> kostya[i];
            // cout << kostya[i] << " ";
        }
        sort(kostya.begin(), kostya.end());
        reverse(kostya.begin(), kostya.end());
        // cout << endl;
        for (int round = 0; round < q; round++)
        {
            int x;
            int y;
            int z;
            cin >> x;
            cin >> y;
            cin >> z;
            int i = 0;
            int j = 0;
            long long total = 0;
            int k = 0;
            while (i < x && j < y && k < z)
            {
                if (vadim[i] < kostya[j])
                {
                    total += kostya[j];
                    j++;
                    k++;
                }
                else
                {
                    total += vadim[i];
                    i++;
                    k++;
                }
            }
            while (j < y && k < z)
            {
                total += kostya[j];
                j++;
                k++;
            }
            while (i < x && k < z)
            {

                total += vadim[i];
                i++;
                k++;
            }
            cout << total << endl;
            // cout << x << " " << y << " " << z << endl;
        }
    }

    return 0;
}