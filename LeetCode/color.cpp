
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int numberOfColours(int N, vector<vector<int>> & edges)
    {
        vector<vector<int>> adj(N+1);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int maxi=0;
        for(int i=1;i<adj.size();i++)
        {
            maxi=max(maxi,adj[i].size()+1);
            
        }
        return maxi;
    }

};

int main() {
    Solution sol;
    int N=5;
    vector<vector<int>>edges={{2,1},{3,2},{4,3},{5,4}};
    cout<<sol.numberOfColours(N,edges);
    return 0;
}