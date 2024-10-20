#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;
int check(vector<int> arr)
{
    sort(arr.begin(),arr.end());
    int x=arr[0];
    x++;
    for(int i=1;i<arr.size();i++)
    {
        if(x!=arr[i])
        {
            return 0; 
        }
        x++;
    }
    return 1;
}
class Solution{
    public:
    int number(vector<int>&A)
    {
        vector<int>array(A.size()+1,-1);
        for(int i=0;i<A.size();i++)
        {
            array[A[i]]=i;
        }
        vector<int>arr;
        int count=0;
        for(int i=0;i<array.size();i++)
        {
            // cout<<array[i]<<" ";
            arr.push_back(array[i]);
            count+=check(arr);
        }

        return count;

    }

};

int main() {
    vector<int> A={1};
    Solution sol;
    // cout<<endl;
    cout<<sol.number(A);
    return 0;
}