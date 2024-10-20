#include <iostream>
#include <vector>

using namespace std;

int dp(vector<vector<int>> &data,vector<int> & A,vector<int> & B,int mini,int maxi,int minsum,int maxsum,int i,int j)
{
    if(i>=A.size() || j>=B.size())
    {
        while(i<A.size())
        {
            mini=min(mini,A[i]);
            minsum=minsum+mini;
            maxi=max(maxi,A[i]);
            maxsum=maxsum+maxi;
            i++;

        }
        while(j<B.size())
        {
            mini=min(mini,B[j]);
            minsum=minsum+mini;
            maxi=max(maxi,B[j]);
            maxsum=maxsum+maxi;
            j++;

        }
        return maxsum-minsum;


    }


    if(data[i][j]!=-1)
    {
        return data[i][j];
    }
     
    return data[i][j]=max(dp(data,A,B,min(mini,A[i]),max(maxi,A[i]),minsum+min(mini,A[i]),maxsum+max(maxi,A[i]),i+1,j),dp(data,A,B,min(mini,B[j]),max(maxi,B[j]),minsum+min(mini,B[j]),maxsum+max(maxi,B[j]),i,j+1));
    
    

}
class Solution{
    public:
    int hybrid_maximum(vector<int> & A, vector<int> & B)
    {
        vector<vector<int>> data(A.size(),vector<int>(B.size(),-1));
        return dp(data,A,B,INT32_MAX,INT32_MIN,0,0,0,0);
        
    }

};

int main() {
    Solution sol;
    vector<int> A={1,2,3};
    vector<int> B={4,1};
    cout<<sol.hybrid_maximum(A,B);
    
    return 0;
}