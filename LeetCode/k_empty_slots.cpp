#include <iostream>
#include <vector>
#include<map>



using namespace std;
class Solution{
    public:
    int Kslots(vector<int>&arr,int k)
    {
        // vector<int>ans(arr.size()-k+1,INT_MAX);
        int mini=INT32_MAX;
        for(int i=k+1;i<arr.size();i++)
        {
            int maxi=max(arr[i-(k+1)],arr[i]);
            int j=i-k;
            for(j;j<i;j++)
            {
                if(maxi>arr[j])
                {
                    maxi=INT32_MAX;
                    break;
                }
            }
            if(maxi!=INT32_MAX)
            {
                if(j==i)
            {
                mini=min(maxi,mini);
            }

            }
            

        }
        if(mini==INT32_MAX)
        {
            return -1;
        }
        return mini;

    }

};

int main() {
    vector<int> arr={1, 2, 3};
    Solution sol;
    cout<<sol.Kslots(arr,1);
    
    return 0;
}