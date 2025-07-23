#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(V + E)
// Space Complexity: O(V + E)

class Solution1 {
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

// https://leetcode.com/problems/number-of-provinces/

// Time Complexity: O(V^2)
// Space Complexity: O(V)

class Solution2 {
    int n;
    void dfs(int i, auto& vis, auto& mat){
        vis[i]=true;
        for(int j=0;j<n;j++){
            if(!vis[j] && mat[i][j]){
                dfs(j,vis,mat);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& mat) {
        n=mat.size();
        int cnt=0;

        vector<bool> vis(n);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,vis,mat);
            }
        }

        return cnt;
    }
};