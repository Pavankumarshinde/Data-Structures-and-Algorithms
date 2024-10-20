#include <iostream>
#include <vector>

using namespace std;

class DisjointSet {
private:
    vector<int> rank, parent;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int findult_p(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findult_p(parent[node]); // Path compression
    }

    void union_uv(int u, int v) {
        int pu = findult_p(u);
        int pv = findult_p(v);

        if (pu != pv) {
            if (rank[pu] < rank[pv]) {
                parent[pu] = pv;
            } else if (rank[pu] > rank[pv]) {
                parent[pv] = pu;
            } else {
                parent[pv] = pu;
                rank[pu]++;
            }
        }
    }
};

class Solution {
public:
    void disjoint_set(int N, vector<vector<int>>& edges) {
        DisjointSet ds(N);
        for (const auto& edge : edges) {
            ds.union_uv(edge[0], edge[1]);
        }
    }
};

int main() {
    int N = 7;
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {4, 5}, {6, 7}, {5, 6}, {3, 7}};
    Solution sol;
    sol.disjoint_set(N, edges);
    return 0;
}
