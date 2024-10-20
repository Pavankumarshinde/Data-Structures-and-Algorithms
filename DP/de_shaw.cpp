#include <iostream>
#include <vector>
using namespace std;
int dp(vector<int> &a, int maxscore,int index,vector<int>sum,vector<int>indexsum)
{
    if(index==a.size())
    {
        int SUM=0;
        for(int i=0;i<sum.size();i++)
        {
            // cout<<sum[i]<<" ";
            SUM+=sum[i];
            
        }
        // cout<<endl;
        int SUMINDEX=0;
        for(int i=0;i<sum.size();i++)
        {
            //  cout<<indexsum[i]<<" ";
            SUMINDEX+=indexsum[i];
            
        }
        // cout<<endl<<endl;
        if(sum.size() *(SUMINDEX) +SUM<= maxscore)
        {
            return sum.size();
        }
        
        return -1;

    }
    int take =0;
    sum.push_back(a[index]);
    indexsum.push_back(index);
    take=dp(a,maxscore,index+1,sum,indexsum);
    sum.pop_back();
    indexsum.pop_back();
    int nottake=0;

    nottake=dp(a,maxscore,index+1,sum,indexsum);
    return max(take ,nottake);

}


class Solution{
    public:
    int no_of_subsequence(vector<int>& a, int maxscore)
    {
        vector<int>sum;
        vector<int>indexsum;

        return dp(a,maxscore,0,sum,indexsum);

    }

};

int main() {
    Solution sol;
    vector<int>a={11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
    int maxscore=800;
    cout<<sol.no_of_subsequence(a,maxscore);
    
    return 0;
}