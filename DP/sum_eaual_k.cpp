#include <iostream>
#include <vector>

using namespace std;



int dp(vector<int>& nums,vector<vector<int>> &data,int index,int target)
{
    
    if(target==0)
    {
        return true;
    }
    if(index==0)
    {
        if(nums[0]==target)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if(data[index][target]!=-1)
    {
        return data[index][target];

    }
    // take.
    bool take=false;
    if(nums[index]<=target)
    {
        take=dp(nums,data,index-1,target-nums[index]);
    }
    bool nottake=dp(nums,data,index-1,target);
    
    
    return data[index][target]=take || nottake;  
}
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.size()==1)
        {
            return false;
        }
       
        
        int target=0;
        for(int i=0;i<nums.size();i++)
        {
            target+=nums[i];

        }
        if(target%2!=0)
        {
            return false;
        }
        target=target/2;
        vector<vector<int>> data(nums.size(),vector<int>(target+1,-1));

        // return dp(nums,data,nums.size()-1,target);

        // tabulation.
        // base case.
        for(int i=0;i<nums.size();i++)
        {
            data[i][0]=true;  //target=0;
            
        }
        for(int tar=1;tar<=target;tar++)
        {
            data[0][tar]=false;
        }
        data[0][nums[0]]=true; 

        for(int i=1;i<nums.size();i++)
        {
            for(int tar=1;tar<=target;tar++)
            {
                bool take=false;
                if(nums[i]<=tar)
                {
                    take=data[i-1][tar-nums[i]];
                }
                bool nottake=data[i-1][tar];
                
                
                data[i][tar]=take || nottake;  
            }
        }

        return data[nums.size()-1][target];
        
        
    }
};
int main() {
    
    return 0;
}