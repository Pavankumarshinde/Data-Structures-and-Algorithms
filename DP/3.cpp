#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for (int i = 0; i < testcases; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int A = b;
        int B = a;
        if (b > a)
        {
            A = a;
            B = b;
        }

        if (A < c < B && A < d < B)
        {
            cout << "NO" << endl;
        }
        if (A < c < B && !(A < d < B))
        {
            cout << "YES" << endl;
        }
        if (A < d < B && !(A < c < B))
        {
            cout << "YES" << endl;
        }
        if (!(A < d < B) && !(A < c < B))
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}