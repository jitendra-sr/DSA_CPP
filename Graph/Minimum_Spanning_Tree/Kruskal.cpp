#include <bits/stdc++.h>
using namespace std;

// Greedy Algorithm for MST

// Time Complexity: O(E log E) for sorting edges, O(E * α(V)) for union-find operations
// Space Complexity: O(V + E) for storing edges and union-find structure

class Solution {
    struct DSU {
        vector<int> parent, rank;
        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; ++i) parent[i] = i;
        }
        int find(int x) {
            if(parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        }
        bool unite(int u, int v) {
            u = find(u), v = find(v);
            if (u == v) return false; // Already in the same set
            if (rank[u] < rank[v]) swap(u, v);
            parent[v] = u;
            if (rank[u] == rank[v]) rank[u]++;
            return true; // Successfully united
        }
    };
    public:
    int kruskalMST(int V, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), [](const auto& a, const auto& b) {
            return a[2] < b[2]; // Sort edges by weight
        });

        DSU ds(V);
        vector<vector<int>> mst;
        int totalWt = 0;

        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (ds.unite(u, v)) {
                mst.push_back(e);
                totalWt += w;
                if ((int)mst.size() == V - 1) break;
            }
        }

        return totalWt;
    }
};
