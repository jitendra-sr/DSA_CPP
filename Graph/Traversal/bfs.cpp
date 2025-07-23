#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(V + E)
// Space Complexity: O(V + E)

class Solution1 {
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

// https://leetcode.com/problems/number-of-provinces/

// Time Complexity: O(V^2)
// Space Complexity: O(V)

class Solution2 {
    int n;
    void bfs(int i, vector<bool>& vis, vector<vector<int>>& mat){
        queue<int> q; q.push(i);
        vis[i] = true;

        while(!q.empty()){
            int node=q.front(); q.pop();

            for(int j=0;j<n;j++){
                if(!vis[j] && mat[node][j]){
                    q.push(j);
                    vis[j]=true;
                }
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
                bfs(i,vis,mat);
            }
        }

        return cnt;
    }
};