#include <iostream>
#include <vector>
#include<queue>

using namespace std;
class Solution{
    public:
    vector<int> shortedpath(int N,vector<vector<int>> & edges)
    {
        vector<vector<pair<int, int>>> adj(N);
    for (int i = 0; i < edges.size(); i++) {
        adj[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
        adj[edges[i][1]].push_back(make_pair(edges[i][0], edges[i][2]));
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dis(N, INT32_MAX);
    pq.push(make_pair(0, 0)); // {distance, node}
    dis[0] = 0;
    
    while (!pq.empty()) {
        pair<int, int> remove = pq.top();
        pq.pop();
        int u = remove.second;
        
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            int weight = adj[u][i].second;
            if (dis[v] > dis[u] + weight) {
                dis[v] = dis[u] + weight;
                pq.push(make_pair(dis[v], v));
            }
        }
    }
    
    for (int i = 0; i < dis.size(); i++) {
        cout << dis[i] << " ";
    }
    cout << endl;
    
    return dis;

    }

};

int main() {
     int N=6;
    int M=8;
    vector<vector<int>> edges={{0,2,4},{0,1,4},{1,2,2},{2,4,1},{2,3,3},{3,5,2},{2,5,6},{4,5,3}};

    Solution sol;
    sol.shortedpath(N,edges);
    return 0;
}