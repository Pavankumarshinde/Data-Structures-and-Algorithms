#include <iostream>
#include <vector>
#include<map>
#include<algorithm>
#include<cmath>

using namespace std;
bool prime(int n)
{
    if(n==2)
    {
        return 1;
    }
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            return 0;

        }
    }
    return 1;
}
class Solution{
    public:
    int numberofprimefactors(int n)
    {
        map<int,int>mymap;
        int count=0;
        int N=n;
        for(int i=2;i<=N;i++)
        {
            if(mymap[i]==0 )
            {
                int condition=1;
                while(n%i==0 && prime(i))
                {
                    if(condition)
                    {
                        count++;
                    }
                    condition=0;

                    mymap[i]=1;
                    n=n/i;
                    // cout<<n<<" ";
                }

            }
            
        }
        return count;

    }

};

int main() {
    Solution sol;
    
    cout<<sol.numberofprimefactors(15);
    
    return 0;
}