#include <iostream>
#include <vector>
#include<stack>
using namespace std;
void dfs(int i,vector<vector<pair<int,int>>>adj, vector<int>& visited,stack<int>&Stack)
{
    visited[i]=1;
    for(int j=0;j<adj[i].size();j++)
    {
        if(!visited[adj[i][j].first])
        {
             dfs(adj[i][j].first,adj,visited,Stack);
        }
       
    }
    Stack.push(i);
}
stack<int> topologicalsort(vector<vector<pair<int,int>>>adj)
{
    stack<int>Stack;
    vector<int>visited(adj.size(),0);
    for(int i=0;i<adj.size();i++)
    {
        if(!visited[i])
        {
            dfs(i,adj,visited,Stack);

        }

    }
    // vector<int>topo;
    // while(!Stack.empty())
    // {
    //     topo.push_back(Stack.top());
    //     Stack.pop();

    // }
    return Stack;
}
class Solution{
    public:
    vector<int>shortpathinDAG(int N,int M,vector<vector<int>> & edges)
    {
        vector<vector<pair<int,int>>>adj(N);
        for(int i=0;i<M;i++)
        {
            adj[edges[i][0]].push_back(make_pair(edges[i][1],edges[i][2]));

        }
        // for(int i=0;i<adj.size();i++)
        // {
        //     for(int j=0;j<adj[i].size();j++)
        //     {
        //         cout<<adj[i][j].first<<"-"<<adj[i][j].second<<" ";
        //     }
        //     cout<<endl;
        // }
        stack<int> topo=topologicalsort(adj);
        // for(int i=0;i<topo.size();i++)
        // {
        //     cout<<topo[i]<<" ";
        // }
        // return topo;
        vector<int>dis(adj.size(),INT32_MAX);
        dis[0]=0;
        while(!topo.empty())
        {
            for(int j=0;j<adj[topo.top()].size();j++)
            {
                dis[adj[topo.top()][j].first]=min(dis[adj[topo.top()][j].first],dis[topo.top()]+adj[topo.top()][j].second);
            }
            topo.pop();

        }
        cout<<endl;
        for(int i=0;i<dis.size();i++)
        {
            cout<<dis[i]<<" ";
        }
        return dis;

       

    }

};

int main() {
    int N=6;
    int M=7;
    vector<vector<int>> edges={{0,1,2},{0,4,1},{4,5,4},{4,2,2},{1,2,3},{2,3,6},{5,3,1}};
    Solution sol;
    sol.shortpathinDAG(N,M,edges);
    
    return 0;
}