#include <iostream>
#include <vector>

using namespace std;
class Solution{
    public:
    int maximumsum(vector<int> & arr)
    {
        int sum=0;
        int right=0;
        int maxi=INT32_MIN;
        while(right <arr.size())
        {
            sum+=arr[right];
            maxi=max(maxi,sum);

            if(sum<0)
            {
                sum=0;
            }
            right++;
        }
        return maxi;

    }

};

int main() {
    Solution sol;
    vector<int>arr={4,3,-7,11,-2,4};
    cout<<sol.maximumsum(arr);
    
    return 0;
}