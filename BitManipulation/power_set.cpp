#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
class Solution{
    public:
    void power_set(vector<int>&nums)
    {
        int n=nums.size();
        vector<vector<int>>ans;
        for(int i=0;i< 1<<n;i++)
        {
            // cout<<i<<" ";
            vector<int> temp;
            for(int j=0;j<n;j++)
            {
                if(i & 1<<j)
                {
                    temp.push_back(nums[j]);

                }
            }
            ans.push_back(temp);

        }
        for(int i=0;i<ans.size();i++)
        {
            for(int j=0;j<ans[i].size();j++)
            {
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }

    }
};
int main() {
    vector<int>nums={1,2,3};
    Solution sol;
    sol.power_set(nums);
    
    return 0;
}