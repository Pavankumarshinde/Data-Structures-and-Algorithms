#include <iostream>
#include <vector>

using namespace std;
struct info{
    int total;
    int lastnode;
};
info pathsum(int i, vector<int> &values,vector<vector<int>>&adj)
{
    
    int maxi=0;
    if(adj[i].size()==0)
    {
        info X;
        X.lastnode=-1;
        X.total=0;
        return X;
    }
    for(int j=0;j<adj[i].size();j++)
    {
        maxi=max(maxi,values[i-1]+pathsum(adj[i][j],values,adj).total);

    }
    info X;
    X.lastnode=i;
    X.total=maxi;
    return X;


}
class Solution{
    public:
    int maximum_path_value_with_teleporation(int N, vector<int> & values, vector<vector<int>> & edges)
    {
        vector<vector<int>>adj(N+1);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        info first=pathsum(1,values,adj);
        
        return 0;
    }

};

int main() {
    int N=5;
    vector<int>values={10,20,30,40,50};
    vector<vector<int>>edges={{1,2},{2,5},{2,4},{1,3}};
    Solution sol;
    cout<<sol.maximum_path_value_with_teleporation(N,values,edges);
    

    return 0;
}