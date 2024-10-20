#include <iostream>
#include <vector>

using namespace std;

int dp(int a,int b,vector<vector<int>> &data)
{
    if(b>a)
    {
        return 1;
    }
    if(data[a][b]!=-1)
    {
        return data[a][b];
    }
    return data[a][b]=1+min(dp(a/b,b,data),dp(a,b+1,data));
}
int main() {
    int testcases;
    cin>>testcases;
    
    for(int i=0;i<testcases;i++)
    {
        int a,b;
        cin>>a>>b;
        vector<vector<int>>data(a+1,vector<int>(b+1,-1));
        cout<<dp(a,b,data)<<endl;
    }
    
    return 0;
}