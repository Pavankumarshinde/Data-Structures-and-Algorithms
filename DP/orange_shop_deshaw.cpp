#include <iostream>
#include <vector>

using namespace std;
class Solution{
    public:
    int cost(int K,int D,vector<int> towns,vector<int> costs,vector<vector<int>> & C)
    {
        return 0;
    }

};

int main() {
    int K=2;
    int D=2;
    vector<int> towns={1,3};
    vector<int> costs={5,10};
    vector<vector<int>>C={{0,2,4,6,8},{2,0,3,5,7},{4,3,0,4,6},{8,7,6,2,0}};
    Solution sol;
    cout<<sol.cost(K,D,towns,costs,C);
    
    return 0;
}