#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;
class Solution
{

public:
    int binary_to_decimal(string s)
    {
        int poweroftwo=1;
        int ans=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]=='1')
            {
                 ans+=poweroftwo*1;


            }
           

            poweroftwo*=2;
        }
        return ans;

    }
    string decimal_to_binary(int num)
    {
        if(num==0)
        {
            return "0";
        }
        string s;

        while(num!=1)
        {
            if(num%2==1)
            {
                s.push_back('1');
            }
            else
            {
                s.push_back('0');
            }
            num=num/2;
        }
        s.push_back('1');
        reverse(s.begin(),s.end());
        return s;

    }
};



int main() {
    Solution sol;
    cout<<sol.binary_to_decimal("110")<<endl;
    cout<<sol.decimal_to_binary(0);
    
    return 0;
}