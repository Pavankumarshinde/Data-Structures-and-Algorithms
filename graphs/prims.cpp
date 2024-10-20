#include <iostream>
#include <vector>
#include<queue>
using namespace std;
class Solution{
    public:
    vector<vector<int>>prims(int N,vector<vector<int>> & edges)
    {
        vector<vector<pair<int,int>>>adj(N);
        vector<vector<int>>mst;
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(make_pair(edges[i][1],edges[i][2]));
            adj[edges[i][1]].push_back(make_pair(edges[i][0],edges[i][2]));

        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,0,-1});
        vector<int>visited(N,0);
        while(!pq.empty())
        {
            vector<int> remove=pq.top();
             pq.pop();
            
            if(visited[remove[1]]==1)
            {
                continue;
            }        
                visited[remove[1]]=1;
                if(remove[2]!=-1)
                {
                    mst.push_back({remove[1],remove[2],remove[0]});

                }      
            for(int i=0;i<adj[remove[1]].size();i++)
            {
                if(!visited[adj[remove[1]][i].first])
                {
                    pq.push({adj[remove[1]][i].second,adj[remove[1]][i].first,remove[1]});
                }
            }

        }
        for(int i=0;i<mst.size();i++)
        {
            
                cout<<mst[i][0]<<" "<<mst[i][1]<<" "<<mst[i][2]<<endl;
            
        }

        return mst; 
    }

};

int main() {
    int N=5;
    vector<vector<int>>edges={{0,1,2},{0,2,1},{2,1,1},{2,4,2},{3,4,1},{2,3,2}};
    Solution sol;
    sol.prims(N,edges);
    return 0;
}