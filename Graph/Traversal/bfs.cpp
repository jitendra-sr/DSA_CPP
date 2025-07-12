#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(V + E)
// Space Complexity: O(V + E)

class Solution {
    void bfs(int st, auto& adj, auto& vis, auto& res) {
        queue<int> q; q.push(st);
        vis[st]=true;

        while(!q.empty()){
            int node=q.front(); q.pop();
            res.push_back(node);
            
            for(int nbr:adj[node]){
                if(!vis[nbr]){
                    q.push(nbr);
                    vis[nbr]=true;
                }
            }
        }
        
    }
  public:
    vector<int> graph(vector<vector<int>> &adj) {
        int n=adj.size();
        vector<int> res;
        
        vector<bool> vis(n);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bfs(i,adj,vis,res);
            }
        }
        
        return res;
    }
};