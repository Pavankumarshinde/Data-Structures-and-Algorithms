#include <iostream>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    vector<TreeNode *> next;
};
class Solution{
    public:
    vector<int> solve(vector<vector<int> > &A) 
    {
        vector<vector<int>> adj(A.size()+2);
        for(int i=0;i<A.size();i++)
        {
            adj[A[i][0]].push_back(A[i][1]);
            adj[A[i][1]].push_back(A[i][0]);
        }
        
        return adj[0];  
        
    }
    TreeNode * root=new TreeNode;
    // root->val=1;
    for(int i=0;i<adj[root->val].size();i++)
    {
        
    }
    
    return {};

    

};

int main() {
    Solution sol;
    vector<vector<int>> A={{1,5},{5,3},{3,4},{1,2},{3,6}};
    sol.solve(A);
    
    return 0;
}