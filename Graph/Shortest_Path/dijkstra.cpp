#include <bits/stdc++.h>
using namespace std;

// Greedy Algorithm for non-negative weighted graphs

// Time Complexity: O((V+E)logV), dense graph (E≈V²) -> O(V²logV), sparse graph (E≈V) -> O(VlogV)
// Space Complexity: O(V + E)

// We can also find the actual path by maintaining a parent array and backtracking from the destination node to the source node.

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> adj(V);
        for(auto& it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            // adj[it[1]].push_back({it[0],it[2]}); // For undirected graph
        }
        
        vector<int> dis(V,INT_MAX); dis[src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        pq.push({0,src});
        
        while(!pq.empty()){
            auto top = pq.top(); pq.pop();
            int d=top.first, node=top.second;
            if(d>dis[node]) continue;
            
            for(auto& nbr:adj[node]){
                int tot=d+nbr.second;
                if(tot<dis[nbr.first]){
                    dis[nbr.first]=tot;
                    pq.push({tot,nbr.first});
                }
            }
        }
        
        return dis;
    }
};