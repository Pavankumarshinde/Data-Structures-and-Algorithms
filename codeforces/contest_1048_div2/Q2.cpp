#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for (int test = 0; test < testcases; test++)
    {
        int k;
        long long x;
        cin>>k;
        cin>>x;
        long long a= pow(2,k+1) -x;
        long long b=x;
        vector<int> sol;
        while(a!=b)
        {
            if(a < b)
            {
                b=b-a;
                a=a*2;
            }
            else
            {
                a=a-b;
                b=b*2;
            }
        }
    }

    return 0;
}
