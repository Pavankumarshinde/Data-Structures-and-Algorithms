#include <iostream>
#include <vector>

using namespace std;
class Solution{
    public:
    vector<vector<int>> shortestPathFromAnyNodeToAnyNode(int N,vector<vector<int>> & edges)
    {
        vector<vector<int>>adj(N,vector<int>(N,1e6));
        for(int i=0;i<edges.size();i++)
        {
            
            adj[edges[i][0]][edges[i][1]]=edges[i][2];
        }
        for(int i=0;i<N;i++)
        {
            adj[i][i]=0;
        }
         for(int i=0;i<adj.size();i++)
            {
                for(int j=0;j<adj[0].size();j++)
                {
                
                        cout<<adj[i][j]<<" ";


                }
                cout<<endl;
            }

        for(int k=0;k<N;k++)
        {
            for(int i=0;i<adj.size();i++)
            {
                for(int j=0;j<adj[0].size();j++)
                {
                
                        // via k;
                        if(adj[i][j]>adj[i][k]+adj[k][j])
                        {
                            adj[i][j]=adj[i][k]+adj[k][j];

                        }
                    


                }
            }
        }
        for(int i=0;i<adj.size();i++)
            {
                for(int j=0;j<adj[0].size();j++)
                {
                
                        cout<<adj[i][j]<<" ";


                }
                cout<<endl;
            }
        return adj;

    }

};

int main() {
    int N=4;
    vector<vector<int>> edges{{0,1,2},{1,0,1},{1,2,3},{3,1,5},{3,2,4},{3,0,3}};
    Solution sol;
    sol.shortestPathFromAnyNodeToAnyNode(N,edges);
    return 0;
}