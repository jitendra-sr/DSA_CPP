#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(V + E)
// Space Complexity: O(V + E)

class DFS_Solution1 {
    bool dfs(int node, auto& adj, auto& vis, auto& dfsCall){
        vis[node]=true;
        dfsCall[node]=true;

        for(int nbr:adj[node]){
            if(!vis[nbr]){
                bool res=dfs(nbr,adj,vis,dfsCall);
                if(res) return true;
            }
            else if(dfsCall[nbr]) return true;
        }
        dfsCall[node]=false;
        
        return false;
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for(auto& it:edges){
            adj[it[0]].push_back(it[1]);
        }
        
        vector<bool> vis(V), dfsCall(V);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                bool res=dfs(i,adj,vis,dfsCall);
                if(res) return true;
            }
        }
        
        return false;
    }
};

class DFS_Solution2 {
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& state) {
        state[node] = 1; // Visiting
    
        for (int neighbor : adj[node]) {
            if (state[neighbor] == 0) {
                bool res = dfs(neighbor, adj, state);
                if(res) return true;
            } 
            // state[neighbour] == state[parent]
            else if (state[neighbor] == 1) return true;
        }
    
        state[node] = 2; // Visited
        return false;
    }   
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for(auto& it:edges){
            adj[it[0]].push_back(it[1]);
        }
        
        vector<int> state(V, 0); // 0 = unvisited, 1 = visiting, 2 = visited
        for (int i = 0; i < V; ++i) {
            if (state[i] == 0) {
                if (dfs(i, adj, state)) return true;
            }
        }

        return false;
    }
};

class Kahn_Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
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
	    
        int count=0;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            count++;

            for (int nbr : adj[node]) {
                inDegree[nbr]--;
                if (inDegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
        
        return count!=V ;
    }
};