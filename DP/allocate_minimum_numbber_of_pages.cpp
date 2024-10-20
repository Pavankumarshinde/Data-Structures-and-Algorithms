#include <iostream>
#include <vector>

using namespace std;


int dp(vector<int>& pages,int m,int index)
{
    if(index==pages.size())
    {
        return 0;
    }
    int maxi=0;
    int sum=pages[index];
    for(int i=1;>0;i++)
    {
        maxi=max(sum,dp(pages,m-1,index+i));
    }
    return maxi;


}
class Solution{
    public :
    int minimumpages(vector<int>&pages,int m){

    }
};
int main() {
    Solution sol;
    vector <int> pages={12,34,67,90};;
    cout<<sol.minimumpages(pages,3);
    
    return 0;
}