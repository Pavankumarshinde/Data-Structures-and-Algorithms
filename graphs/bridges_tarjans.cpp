#include <iostream>
#include <vector>

using namespace std;
int t=0;
void dfs(int parent,int i,vector<vector<int>> & adj,vector<int> & visited,vector<int> & times,vector<int> & lowesttime)
{
    t++;
    times[i]=t;
    lowesttime[i]=t;
    visited[i]=1;
    for(int j=0;j<adj[i].size();j++)
    {
        if(!visited[adj[i][j]])
        {
            dfs(i,adj[i][j],adj,visited,times,lowesttime);
        }

    }
    for(int j=0;j<adj[i].size();j++)
    {
        
        if(adj[i][j]!=parent)
        {
            lowesttime[i]=min(lowesttime[i],lowesttime[adj[i][j]]);
        }

    }
    if(parent!=-1)
    {
         if(lowesttime[i]>lowesttime[parent])
    {
        cout<<i<<" "<<parent<<endl;
    }

    }
   
}
class Solution{
    public:
    vector<vector<int>> bridges(int N,vector<vector<int>> &edges)
    {
        t=0;
        vector<vector<int>>adj(N+1);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int>times(N+1);
        vector<int>lowesttime(N+1);
        vector<int>visited(N+1,0);
        for(int i=1;i<N+1;i++)
        {
            if(!visited[i])
            {
                dfs(-1,i,adj,visited,times,lowesttime);
            }
        }
    
        return adj;

    }
};

int main() {
    int N=12;
    
    vector<vector<int>> edges={{1,2},{2,3},{3,4},{4,1},{4,5},{5,6},{6,7},{7,8},{8,9},{9,6},{8,10},{10,11},{11,12},{12,10}};
    Solution sol;
    sol.bridges(N,edges);
    return 0;
}