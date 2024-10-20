#include <iostream>
#include <vector>

using namespace std;
class Solution{
    public:
    int numberOfOperations(vector<int> & a)
    {
        int maxi=0;
        int index=0;
        for(int i=0;i<a.size();i++)
        {
            if( maxi<=a[i])
            {
                maxi=a[i];
                index=i;
            }
        }
        return 0;
    }

};

int main() {
    vector<int> a={0,2,1,3,4,3,1,2,2,1,2};

    
    return 0;
}