#include <iostream>
#include <vector>
using namespace std;

int dp(vector<int> &data, vector<int> &nums, int n)
{
    if (n == 0)
    {
        return nums[0];
    }
    if (n < 0)
    {
        return 0;
    }
    if (data[n] != -1)
    {
        // cout<<"used";
        return data[n];
    }
    // pick; //not pick
    return data[n] = max(dp(data, nums, n - 2) + nums[n], dp(data, nums, n - 1));
}

class Solution
{
public:
    void rob(vector<int> &nums)
    {
        vector<int> data(nums.size(), -1);
        // return dp(data,nums, nums.size() - 1);
        // return tabulation(nums,nums.size());

        //tebulation.
        // data[0] = nums[0];
        // for (int i = 1; i < nums.size(); i++)
        // {
        //     // pick and dont pick;
            
        //     int pick;
        //     if(i>1)
        //     {
        //         pick=data[i-2]+nums[i];
        //     }
        //     else
        //     {
        //         pick=nums[i];
        //     }
        //     int dont_pick = data[i - 1];
        //     data[i]=max(pick,dont_pick);
        // }
        // cout << (data[nums.size() - 1]);


        //tabulation + space optimizAation.
         int previous1  = nums[0];
         int previous2=0;
         int current=0;
        for (int i = 1; i < nums.size(); i++)
        {
            // pick and dont pick;
            
            int pick;
            if(i>1)
            {
                pick=previous2+nums[i];
            }
            else
            {
                pick=nums[i];
            }
            int dont_pick = previous1;
            current=max(pick,dont_pick);
            previous2=previous1;
            previous1=current;
            
        }
        cout << current;

    }
};

int main()
{
    vector<int> nums = {2, 7, 9, 3, 1};
    Solution sol;
     sol.rob(nums);
    return 0;
}
