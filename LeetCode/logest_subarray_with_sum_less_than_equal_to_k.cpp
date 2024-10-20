#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    int lengthOfLongestSubarray(vector<int> &arr, int k)
    {
        int l=0;
        int r=0;
        int sum=0;
        int maxlength=0;
        while(r<arr.size())
        {
            sum=sum+arr[r];
            while(sum>k)
            {
                sum=sum-arr[l];
                l++;
            }
            if(sum<=k)
            {
                maxlength=max(maxlength,r-l+1);
            }
            r++;
        }
        return maxlength;
    }
};

int main()
{
    vector<int> arr = {2, 5, 1, 10, 10};
    int k = 14;
    Solution sol;
    cout << sol.lengthOfLongestSubarray(arr, k);

    return 0;
}