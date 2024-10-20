#include <iostream>
#include <vector>
#include <queue>
#include<stack>
using namespace std;

void detectcycle(int i, vector<int> & visited,vector<vector<int>> & adj)
{
    queue<vector<int>>Que;
    Que.push({i,-1});
    visited[i]=1;
    while(!Que.empty())
    {
        vector<int> remove=Que.front();
        Que.pop();
        for(int j=0;j<adj[remove[0]].size();j++)
        {
            if(!visited[adj[remove[0]][j]])
            {
                Que.push({adj[remove[0]][j],remove[0]});
                visited[adj[remove[0]][j]]=1;

            }
            else if(remove[1]!=adj[remove[0]][j])
            {
                // return true;
                cout<<"yes cycle";
            }
        }

    }
    // return false;


}
void topologicalsort(int i,vector<int> & visited,vector<vector<int>> & adj)
{

}
void dpdfs(int i,vector<int> & visited,vector<vector<int>> & adj,stack<int>&Stack)
{
    visited[i]=1;
    cout<<i<<" ";
    for(int j=0;j<adj[i].size();j++)
    {
        if(!visited[adj[i][j]])
        {
            dpdfs(adj[i][j],visited,adj,Stack);

        }
        
    }
    Stack.push(i);

}
void dfs(int i,vector<int> & visited,vector<vector<int>> & adj)
{
    stack<int> Stack;
    Stack.push(i);
    visited[i]=1;
    while(!Stack.empty())
    {
        int remove=Stack.top();
        Stack.pop();
        cout<<remove<<" ";

        for(int j=0;j<adj[remove].size();j++)
        {
            if(!visited[adj[remove][j]])
            {
                Stack.push(adj[remove][j]);
                visited[adj[remove][j]]=1;
            }
        }


    }
}

void bfs(int i, vector<int> &visited, vector<vector<int>> &adj) {
    queue<int> Que;
    Que.push(i);
    visited[i] = 1;
    while (!Que.empty()) {
        int remove = Que.front();
        Que.pop();
        cout << remove << " "; // Output the node being processed
        for (int j = 0; j < adj[remove].size(); j++) {
            int neighbor = adj[remove][j];
            if (!visited[neighbor]) {
                Que.push(neighbor);
                visited[neighbor] = 1;
            }
        }
    }
}

class Solution {
public:
    void travelser(int n, int m, vector<vector<int>> &edges) {
        vector<vector<int>> adj(n + 1);
        stack<int> Stack;
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> visited(n + 1, 0);
        for (int i = 1; i <= n; i++) { // Start from 1 for 1-indexed nodes
            if (!visited[i]) {
                // dfs(i, visited, adj);
                (dpdfs(i,visited,adj,Stack));
                
            }
        }
        // cout<<"no cycle";
    }
};

int main() {
    int n = 5;
    int m = 5;

    vector<vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}, {1, 5}};
    Solution sol;
    sol.travelser(n, m, edges);

    return 0;
}
