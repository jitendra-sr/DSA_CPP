#include <bits/stdc++.h>
using namespace std;

// Greedy Algorithm for non-negative weighted graphs

// Time Complexity: O((V+E)logV), dense graph (E≈V²) -> O(V²logV), sparse graph (E≈V) -> O(VlogV)
// Space Complexity: O(V + E)

// We can also find the actual path by maintaining a parent array and backtracking from the destination node to the source node.

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> adj(V);
        for(auto& it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            // adj[it[1]].push_back({it[0],it[2]}); // For undirected graph
        }
        
        vector<int> dis(V,INT_MAX); dis[src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        pq.push({0,src});
        
        while(!pq.empty()){
            auto top = pq.top(); pq.pop();
            int d=top.first, node=top.second;
            if(d>dis[node]) continue;
            
            for(auto& nbr:adj[node]){
                int tot=d+nbr.second;
                if(tot<dis[nbr.first]){
                    dis[nbr.first]=tot;
                    pq.push({tot,nbr.first});
                }
            }
        }
        
        return dis;
    }
};

// https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/
class Solution2 {
    using ll=long long;;
    using p=pair<ll,ll>;
    const ll mod=1e9+7;
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        if(m==0) return {-1};
        
        vector<vector<p>> adj(n);
        for(auto& it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        vector<ll> dis(n,LLONG_MAX), parent(n,-1), ways(n,0); 
        dis[0]=0; parent[0]=0; ways[0]=1;
        priority_queue<p,vector<p>,greater<>> pq;
        pq.push({0,0}); // {distance, node}
        
        while(!pq.empty()){
            auto& top = pq.top(); pq.pop();
            ll d=top.first, u=top.second;
            if(d>dis[u]) continue;
            
            for(auto& nbr:adj[u]){
                ll v=nbr.first, wt=nbr.second;
                ll tot=d+wt;
                if(tot<dis[v]){
                    dis[v]=tot;
                    parent[v]=u;
                    ways[v]=ways[u];
                    pq.push({tot,v});
                }
                else if(tot==dis[v]){
                    ways[v]=(ways[v]+ways[u])%mod;
                }
            }
        }
        
        if(dis[n-1]==LLONG_MAX) return {-1};
        
        vector<int> path;
        int node=n;
        while(parent[node]!=node){
            path.push_back(node);
            node=parent[node];
        }
        path.push_back(node);

        path.push_back(ways[n-1]); // Count of ways to reach destination with shortest distance
        path.push_back(dis[n-1]); // Shortest distance to destination
        reverse(path.begin(),path.end());
        
        return path;
    }
};