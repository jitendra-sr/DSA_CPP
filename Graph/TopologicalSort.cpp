#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(V + E)
// Space Complexity: O(V + E)

// Topological sort is the linear ordering of vertices in a directed acyclic graph (DAG) such that for every directed edge u -> v, vertex u comes before vertex v in the ordering.
// Linear ordering can't be done in a cyclic graph, hence it also detects if there is a cycle in a graph.

class DFS_Solution {
    void dfs(int node, auto& adj, auto& vis, auto& res){
        vis[node]=true;
        
        for(int nbr:adj[node]){
            if(!vis[nbr]) {
                dfs(nbr,adj,vis,res);
            }
        }
        
        res.push_back(node);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto& it:edges){
            adj[it[0]].push_back(it[1]);
        }
        
        vector<int> res;
        vector<bool> vis(V);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,res);
            }
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
};

class Kahn_Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto& it:edges){
            adj[it[0]].push_back(it[1]);
        }
        
        vector<int> inDegree(V,0);
	    for(int i=0;i<V;i++) {
	        for(int j:adj[i]) {
	            inDegree[j]++;
	        }
	    }
	    
	    queue<int> q;
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
	    
        vector<int> res;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            res.push_back(node);

            for (int nbr : adj[node]) {
                inDegree[nbr]--;
                if (inDegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
        
        if(res.size()!=V) return {};
        return res;
    }
};