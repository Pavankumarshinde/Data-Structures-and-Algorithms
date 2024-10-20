#include <iostream>
#include <vector>
#include<map>

using namespace std;
int dp(map<char,vector<int>> & data, string & code,int index,int current,int n)
{
    if(index==code.size())
    {
        return code.size();
    }

    vector<int> positions=data[code[index]];
    int mini=INT32_MAX;
    for(int j=0;j<positions.size();j++)
    {
            if(positions[j]>=current)
            {
                if(positions[j]-current < n-positions[j] + current)
                {
                   mini=min(mini, positions[j]-current+ dp( data,code, index+1,positions[j],n));
                }
                else
                {
                    mini=min(mini, n-positions[j] + current+ dp( data,code, index+1,positions[j],n));

                }

            }
            else
            {
                if(current- positions[j] < n-current + positions[j])
                {
                   mini=min(mini, current- positions[j]+ dp( data,code, index+1,positions[j],n));
                }
                else
                {
                    mini=min(mini, n-current + positions[j]+ dp( data,code, index+1,positions[j],n));

                }

            }
    }
    return mini;

}
class Solution{
    public:
    int steps(string & s, string &code)
    {
        map<char,vector<int>>data;
        for(int i=0;i<s.size();i++)
        {
            data[s[i]].push_back(i);
        }
        return dp(data,code,0,0,s.size());
    }
    

};

int main() {
    string s="hello";
    string code="hoe";
    Solution sol;
    cout<<sol.steps(s,code);
    return 0;
}