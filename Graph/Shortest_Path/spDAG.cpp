#include <bits/stdc++.h>
using namespace std;

// Greedy + DP approach for Directed Acyclic Graphs (DAG)

// Time Complexity: O(V + E)
// Space Complexity: O(V + E)

class Solution {
    void dfs(int node, auto& adj, auto& vis, auto& topo){
        vis[node]=true;
        
        for(auto& nbr:adj[node]){
            if(!vis[nbr.first]) {
                dfs(nbr.first,adj,vis,topo);
            }
        }
        
        topo.push_back(node);
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        for(auto& it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        vector<int> topo;
        vector<bool> vis(V);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,topo);
            }
        }
        
        vector<int> dis(V,INT_MAX);
        dis[0]=0; // Source Node
        
        while(!topo.empty()){
            int node=topo.back(); topo.pop_back();
            if(dis[node]==INT_MAX) continue; // Node not reachable

            for(auto& nbr:adj[node]){
                int d=dis[node]+nbr.second;
                if(d<dis[nbr.first]){
                    dis[nbr.first]=d;
                }
            }
        }
        
        for(int i=0;i<V;i++) {
            if(dis[i]==INT_MAX) dis[i]=-1;
        }
        
        return dis;
    }
};