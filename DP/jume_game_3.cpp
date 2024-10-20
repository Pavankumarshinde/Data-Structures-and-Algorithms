bool dp(vector<int>& arr, int start)
{
    cout<<start<<" ";
    
    if(start<0 || start>=arr.size() || arr[start]==-1)
    {
        return false;
    }
    if(arr[start]==0)
    {
        return true;
    }
    int jump=arr[start];
    arr[start]=-1;
    return dp(arr,start-jump) || dp(arr,start+jump);
    

}
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        return dp(arr,start);
        
    }
};