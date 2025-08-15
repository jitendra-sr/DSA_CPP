#include<bits/stdc++.h>
using namespace std;

// Greedy Algorithm for MST

// Time Complexity: O((V+E)logV), dense graph (E≈V²) -> O(V²logV), sparse graph (E≈V) -> O(VlogV)
// Space Complexity: O(V + E)

class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        for (auto& it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // key stores the minimum weight edge to connect the node to the MST
        vector<int> key(V, INT_MAX), parent(V, -1); 
        vector<bool> vis(V, false);
        key[0] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, 0});

        int totalWt = 0;
        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (vis[node]) continue;
            vis[node] = true;
            totalWt += d;

            for (auto& nbr : adj[node]) {
                int v = nbr.first, wt = nbr.second;
                if (!vis[v] && wt < key[v]) { // !vis[v] is redundant as wt < key[v] is sufficient
                    key[v] = wt;
                    parent[v] = node;
                    pq.push({key[v], v});
                }
            }
        }

        vector<tuple<int,int,int>> mst;
        for (int v = 1; v < V; v++) { // start from 1, as 0 is root
            mst.push_back({parent[v], v, key[v]});
        }
        // MST can also be created directly while popping from pq if we utilize the parent array or by making pq entry as a tuple (weight, node, parent).

        // totalWt = 0;
        // for (int d : key) {
        //     if (d == INT_MAX) {
        //         cout << "Graph is disconnected, MST not possible\n";
        //         return -1;
        //     }
        //     totalWt += d;
        // }

        return totalWt;
    }
};
