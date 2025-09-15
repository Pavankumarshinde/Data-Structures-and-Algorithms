#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for (int i = 0; i < testcases; i++)
    {
        int n;
        cin >> n;
        string a;
        for (int j = 0; j < n; j++)
        {
            char ch;
            cin >> ch;
            a += ch;
        }
        int m;
        cin >> m;
        string b;
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            b += ch;
        }
        string D;
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            D += ch;
        }
        // cout << n << " " << m << " " << a << " " << b << " " << D << endl;
        for (int i = 0; i < m; i++)
        {
            if (D[i] == 'D')
            {
                a.push_back(b[i]);
            }
            else
            {
                a.insert(a.begin(), b[i]);
            }
        }
        cout << a << endl;
    }

    return 0;
}