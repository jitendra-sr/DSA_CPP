#include <bits/stdc++.h>
using namespace std;

// Dynamic Programming approach for graphs with negative weights

// Time Complexity: O(V * E)
// Space Complexity: O(V)

// Intuition:
// In a graph with V vertices, the longest possible shortest path (without cycles) has V - 1 edges.
// Further relaxation after V - 1 iterations means there's a cycle reducing the distance.

// Optimized: SPFA (Queue-based Bellman-Ford)

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dis(V,INT_MAX); dis[src]=0;
        // Relax edges V-1 times 
        for(int i=0;i<V-1;i++){
            for(auto& edge:edges){
                int node=edge[0], nbr=edge[1], wt=edge[2];
                if(dis[node]==INT_MAX) continue;
                
                int d=wt+dis[node];
                if(d<dis[nbr]){
                    dis[nbr]=d;
                }
            }
        }
 
        // If we can still relax an edge, it means there's a negative weight cycle
        for(auto& edge:edges){
            int node=edge[0], nbr=edge[1], wt=edge[2];
            if(dis[node]==INT_MAX) continue;
            
            int d=wt+dis[node];
            if(d<dis[nbr]) return {-1};
        }
        
        return dis;
    }
};
