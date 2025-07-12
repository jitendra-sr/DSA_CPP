#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(V + E)
// Space Complexity: O(V + E)

class Solution {
    void dfs(int node, auto& adj, auto& vis, auto& res){
        res.push_back(node);
        vis[node]=true;
        
        for(int nbr:adj[node]){
            if(!vis[nbr]) {
                dfs(nbr,adj,vis,res);
            }
        }

    }
  public:
    vector<int> graph(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> res;
        
        vector<bool> vis(n);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis,res);
            }
        }
        
        return res;
        
    }
};