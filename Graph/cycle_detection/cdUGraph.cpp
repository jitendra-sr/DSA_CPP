#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(V + E)
// Space Complexity: O(V + E)

class DFS_Solution {
    bool dfs(int node, int parent, auto& adj, auto& vis){
        vis[node]=true;

        for(int nbr:adj[node]){
            if(!vis[nbr]){
                bool res=dfs(nbr,node,adj,vis);
                if(res) return true;
            }
            else if(nbr!=parent) return true;
        }
        
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto& it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<bool> vis(V);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                bool res=dfs(i,i,adj,vis);
                if(res) return true;
            }
        }
        
        return false;
    }
};

class BFS_Solution {
    bool bfs(int st, auto& adj, auto& parent){
        queue<int> q; q.push(st);
        parent[st]=st;
        
        while(!q.empty()){
            int node=q.front(); q.pop();
            
            for(int nbr:adj[node]){
                if(parent[nbr]==-1){
                    q.push(nbr);
                    parent[nbr]=node;
                }
                else if(nbr!=parent[node]) return true;
            }
        }
        
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto& it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> parent(V,-1); // parent[i]==-1 => not visited
        for(int i=0;i<V;i++){
            if(parent[i]==-1){
                bool res=bfs(i,adj,parent);
                if(res) return true;
            }
        }
        
        return false;
    }
};