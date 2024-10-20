#include <iostream>
#include <vector>

using namespace std;
int dp(vector<int> & array,int index,int target)
{
    if(target==0)
    {
        return 1;

    }
    if(index==0)
    {
        // return 1;
        if(array[0]==target)
        {
            return 1;
        }
        else
        {
            return 0;
        }

    }
    int take=0;
    if(array[index]<=target)
    {
        take=dp(array,index-1,target-array[index]);

    }

    int donttake=dp(array,index-1,target);

    return take+donttake;
    
}
class Solution{
    public:
   int subsets(vector<int> & array,int k)
   {
    // return dp(array,array.size()-1,k);

    // tabulation
        // vector<vector<int>> data(array.size(),vector<int>(k+1,-1));
        // for(int index=0;index<array.size();index++)
        // {
        //     data[index][0]=1;
        // }
        // for(int target=1;target<=k;target++)
        // {
        //     data[0][target]=0;
        // }
        // if(array[0]<=k)
        // {
        //     data[0][array[0]]=1;

        // }

        // for(int index=1;index<array.size();index++)
        // {
        //     for(int target=1;target<=k;target++)
        //     {
        //         int take=0;
        //         if(array[index]<=target)
        //         {
        //             take=data[index-1][target-array[index]];

        //         }

        //         int donttake=data[index-1][target];

        //         data[index][target]= take+donttake;

        //     }
        // }
        // return data[array.size()-1][k];

        // space optimization.
        vector<int>pre(k+1,-1);
        vector<int>curr(k+1,-1);
        pre[0]=curr[0]=1;
        for(int target=1;target<=k;target++)
        {
            pre[target]=0;
        }
        if(array[0]<=k)
        {
            pre[array[0]]=1;

        }

        for(int index=1;index<array.size();index++)
        {
            for(int target=1;target<=k;target++)
            {
                int take=0;
                if(array[index]<=target)
                {
                    take=pre[target-array[index]];

                }

                int donttake=pre[target];

                curr[target]= take+donttake;

            }
            pre=curr;
        }
        return pre[k];



   }
};
int main() {
    vector<int>array={12, 1, 61, 5, 9, 2,24};
    int k=24;
    Solution sol;
    cout<<sol.subsets(array,k);
    return 0;
}