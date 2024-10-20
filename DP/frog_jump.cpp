#include<iostream>
#include<vector>


// There is a frog on the '1st' step of an 'N' stairs long staircase. The frog wants to reach the 'Nth' stair. 'HEIGHT[i]' is the height of the '(i+1)th' stair.If Frog jumps from 'ith' to 'jth' stair, the energy lost in the jump is given by absolute value of ( HEIGHT[i-1] - HEIGHT[j-1] ). If the Frog is on 'ith' staircase, he can jump either to '(i+1)th' stair or to '(i+2)th' stair. Your task is to find the minimum total energy used by the frog to reach from '1st' stair to 'Nth' stair.

// For Example
// If the given ‘HEIGHT’ array is [10,20,30,10], the answer 20 as the frog can jump from 1st stair to 2nd stair (|20-10| = 10 energy lost) and then a jump from 2nd stair to last stair (|10-20| = 10 energy lost). So, the total energy lost is 20.

using namespace std;
int dp(vector <int> &array,int n,vector<int> &data,int &k)
{
    if(n>=array.size()-1)
    {
        return 0;
    }
    if(data[n]!=-1)
    {
        return data[n];
    }
    int minimum=100000;
    for(int kk=1;kk<=k;kk++)
    {
        if(kk+n>array.size())
        {
            break;
        }
        int Returned=(dp(array,n+kk,data,k));
        {

        minimum=min((Returned+ abs(array[n]-array[n+kk])),minimum);


        }
        
    }
    
    // return data[n]=min(dp(array,n+1,data,k)+ abs(array[n]-array[n+1]),dp(array,n+2,data,k)+abs(array[n]-array[n+2]));
    return data[n]=minimum;

}
class Solution{
    public:
    void frogjump(vector<int> & array,int k)
    {
        vector<int> data(array.size()+1,-1);
        int x=dp(array,0,data,k);
        cout<<x;


    }

};
int main()
{
    vector<int> array={4,8,3,10,4,4 };
    Solution sol;
    sol.frogjump(array,2);
    
}