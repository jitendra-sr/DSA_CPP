#include <bits/stdc++.h>
using namespace std;

// Greedy Algorithm for unweighted graphs

// Time Complexity: O(V + E)
// Space Complexity: O(V + E)

// We can also find the actual path by maintaining a parent array and backtracking from the destination node to the source node.

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n=adj.size();
        vector<int> dis(n,INT_MAX); 
        dis[src]=0; // dis[i]==INT_MAX => not visited
        
        queue<int> q; q.push(src);

        while(!q.empty()){
            int node=q.front(); q.pop();
            if(dis[node] == INT_MAX) continue;
            
            for(int nbr:adj[node]){
                if(dis[nbr]==INT_MAX){
                    dis[nbr]=dis[node]+1;
                    q.push(nbr);
                }
            }
        }

        for(int i=0;i<n;i++) {
            if(dis[i]==INT_MAX) dis[i]=-1;
        }
        
        return dis;
    }
};