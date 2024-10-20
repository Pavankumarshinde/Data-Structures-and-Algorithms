#include <iostream>
#include <vector>

using namespace std;
int binarysearch(int left,int right, vector<int> & arr, int x, int first)
{
    if(right-left<=1)
    {
        if(abs(first + arr[left] -x)  < abs(first + arr[right] -x))
        {
            return arr[left];
        }
        else return arr[right];
    }
    int mid=(left +right )/2;
    if(arr[mid] + first <=x)
    {
        return binarysearch(mid,right,arr,x,first);
    }
    else
    {
        return binarysearch(left,mid, arr, x,first);
    }
}
class Solution{
    public:
    int printClosest(vector<int> & arr,int x)
    {
        int n=arr.size();
        int closed=INT32_MAX;
        int total=INT32_MAX;
        for(int i=0;i<arr.size()-1;i++)
        {
            int first=arr[i];
            int left=i+1;
            int right=n-1;
            int second=binarysearch(left,right,arr,x,first);
            if(closed > abs(first +second -x))
            {
                closed=abs(first +second -x);
                total=first +second ;
                

            }
            

        }
        return total;

    }

};

int main() {
    Solution sol;
// Output: 22 and 30
    vector<int> arr={10, 22, 28, 29, 30, 40};
    int x = 54;
    cout<<sol.printClosest(arr, x);
    
    
    return 0;
}