#include <bits/stdc++.h>
using namespace std;

// Tarjan's Algorithm to find articulation points in an undirected graph

// Time Complexity: O(V + E)
// Space Complexity: O(V + E)

class Solution {
    vector<vector<int>> adj;
    vector<int> tin, low;
    vector<bool> vis, isCutPoint;
    int timer;

    void dfs(int node, int parent){
        vis[node]=true;
        tin[node]=low[node]=timer++;

        int children=0; // special case for root as normal condition won't work.
        // Counts no. of disconnected children assuming the node is only connecting link
        // (kind of different components if common node doesn't exist)

        for(int& nbr:adj[node]){
            if(nbr==parent) continue;

            else if(!vis[nbr]){
                children++;
                dfs(nbr,node);
                low[node]=min(low[node],low[nbr]); 

                if(low[nbr]>=tin[node] && parent!=-1){
                    isCutPoint[node]=true;
                }
            }
            else low[node]=min(low[node],tin[nbr]);
        }
        
        if(parent==-1 && children>1) isCutPoint[node]=true;
    }
public:
    vector<int> criticalPoints(int n, vector<vector<int>>& edges) {
        adj.assign(n,{});
        for(auto& e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        tin.assign(n,-1);
        low.assign(n,-1);
        vis.assign(n,false);
        isCutPoint.assign(n,false); // marking of cut-points
        timer=0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,-1);
            }
        }
        
        vector<int> res; // list of cut-points
        for(int i=0;i<n;i++){
            if(isCutPoint[i]) res.push_back(i);
        }

        return res;
    }
};