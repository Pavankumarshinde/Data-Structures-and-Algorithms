#include <iostream>
#include <vector>
#include<queue>

using namespace std;
class Solution{
    public:
    vector<int>shortedpath(int N,vector<vector<int>> & edges)
    {
        vector<vector<int>>adj(N);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][1]].push_back(edges[i][0]);
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        // starting node is zero.

        vector<int>dis(N,INT32_MAX);
        vector<int>visited(N,0);
        dis[0]=0;

        queue<int>Que;
        Que.push(0);
        visited[0]=1;
        while(!Que.empty())
        {
            vector<int>temp;
            while(!Que.empty())
            {
                temp.push_back(Que.front());
                Que.pop();
            }
            for(int i=0;i<temp.size();i++)
            {
                for(int j=0;j<adj[temp[i]].size();j++)
                {
                    if(!visited[adj[temp[i]][j]])
                    {
                        Que.push(adj[temp[i]][j]);
                        dis[adj[temp[i]][j]]=min(dis[adj[temp[i]][j]], 1+dis[temp[i]]);
                        visited[adj[temp[i]][j]]=1;


                    }
                    
                }
            }

        }
        for(int i=0;i<dis.size();i++)
        {
            cout<<dis[i]<<" ";
            
        }

        return dis;

    }

};

int main() {
    int N=6;
    int M=8;
    vector<vector<int>> edges={{0,2},{0,1},{1,2},{2,4},{2,3},{3,5},{2,5},{4,5}};

    Solution sol;
    sol.shortedpath(N,edges);
    return 0;
}