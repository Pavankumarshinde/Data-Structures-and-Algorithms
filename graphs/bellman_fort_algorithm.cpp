#include <iostream>
#include <vector>

using namespace std;
class Solution{
    public:
    vector<int> shortestpath(int N,vector<vector<int>> & edges)
    {
        vector<int>dis(N,1e8);
        dis[0]=0;
        for(int k=0;k<N-1;k++)
        {
            for(int i=0;i<edges.size();i++)
            {
                int u=edges[i][0];
                int v=edges[i][1];
                int wt=edges[i][2];

                if(dis[u] +wt < dis[v])
                {
                    dis[v]=dis[u]+wt;
                }
            }

        }
        
        for(int i=0;i<N;i++)
        {
            cout<<dis[i]<<" ";
        }
        return dis;


    }

};

int main() {
     int N=6;
    int M=8;
    vector<vector<int>> edges={{0,1,4},{0,2,4},{2,1,2},{2,4,1},{2,3,3},{3,5,2},{2,5,6},{4,5,3}};

    Solution sol;
    sol.shortestpath(N,edges);
    return 0;
}