#include <iostream>
#include <vector>

using namespace std;
int dp(vector<int> & arr,int index, int sumL,int sumR)
{
    if(index+1==arr.size())
    {
        return abs(sumL-sumR);
    }

    
    
    int change=(arr[index-1] + arr[index+1])/2;
    if(arr.size()/2 >index)
    {
        
        
        int withoutchanged=dp(arr,index+1,sumL+arr[index],sumR);
        int withchange=0;
        if((arr[index-1] + arr[index+1])%2==0)
        {
            arr[index]=change;
            withchange=dp(arr,index+1,sumL+change,sumR);
        }
        
        
        return max(withchange,withoutchanged);

    }
    else
    {
        int withoutchanged=dp(arr,index+1,sumL,sumR+arr[index]);
        int withchange=0;
            if((arr[index-1] + arr[index+1])%2==0)
        {
        arr[index]=change;
        withchange=dp(arr,index+1,sumL,sumR+change);
        }
        
        return max(withchange,withoutchanged);
    }
        
   

    


}
class Solution{
    public:
    int maxdifference(vector<int> &arr)
    {

        return dp(arr,1,arr[0],arr.back());

    }

};

int main() {
    vector<int> arr={5,6,5,2,1,7,9,7,2,5};
    Solution sol;
    cout<<sol.maxdifference(arr);
    return 0;
}