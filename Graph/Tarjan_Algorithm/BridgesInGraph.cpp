#include <bits/stdc++.h>
using namespace std;

// Tarjan's Algorithm to find Bridges in an undirected graph

// Time Complexity: O(V + E)
// Space Complexity: O(V + E)

// Intuition
// If a edge is not part of any cycle, then it is a bridge.
// If a back-edge found by a node, then the edge (nbr ie. ancestor-node) is not a bridge as it is a cycle and we already have one a connecting edge coming from parent of node.

// 1. In algorithm we use this notion via low[] array. If a node's low-link value is greater than the discovery time of its parent, then it means no back-edge was found and this (parent-node) is the only connecting edge, hence a bridge.
// 2. low-link will only less or equal to discovery time of a node when it finds a back-edge to an ancestor (having lower tin) apart from its parent which signifies a cycle and hence no bridge.
// 3. If a back-edge is found then we propagate it to all nodes in cycle so that they also know they are part of cycle and they can also update their low-link values accordingly so that all edges in cycle are not considered as bridges.
// 4. We don't update low-link  of a node from its immediate parent (which is also a nbr) as we check whether current edge is bridge or not. If we update low-link from parent, then we can't say whether is happened due to back-edge or parent edge and no edge will be considered as bridge.
// 5. A better analogy is that consider discovery time as level and low-link as the lowest level reachable (ie. above==ancestor) from a node. If a node have low-link lower than or equal to its parent, then it means that node is connected with ancestors above via back-edge and using that edge the node will still be connected if we remove the current parent-node edge.

class Solution {
    vector<vector<int>> adj, res;
    vector<int> tin, low;
    vector<bool> vis; // optional, discovery array can also be used to check visited or not
    int timer;

    void dfs(int node, int parent){
        vis[node]=true;
        tin[node]=low[node]=timer++;

        for(int& nbr:adj[node]){
            if(nbr==parent) continue; // immediate parent is not a back-edge.

            else if(!vis[nbr]){
                dfs(nbr,node);
                low[node]=min(low[node],low[nbr]); 
                // propagate back-edge (if found) info to all nodes in cycle

                if(low[nbr]>tin[node]){ // Bridge found
                    res.push_back({node,nbr});
                }
            }
            else low[node]=min(low[node],tin[nbr]); // back edge to an ancestor, memorize it
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edges) {
        adj.assign(n,{});
        for(auto& e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        tin.assign(n,-1); // Discovery (or insertion) time
        low.assign(n,-1); // lowest reachable discovery time ie. ancestor
        vis.assign(n,false);
        timer=0;
        res.clear(); // list of bridges or cut edges

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,-1);
            }
        }

        return res;
    }
};