#include <bits/stdc++.h>
using namespace std;

// Kosaraju's Algorithm to find Strongly Connected Components (SCC) in a directed graph

// Time Complexity: O(V + E)
// Space Complexity: O(V + E)

// Intuition
// 1.In general if we traverse the graph then it may happen that all nodes forming cycle or sccs get visited in once as whole graph may be connected. 
// 2. To find sccs we have to visit each scc one by one and no scc should visit another scc.
// 3. We have to traverse the graph in an order reverse of topological order so that when the last scc is traversed it should not traverse its neighbouring sccs and if there is directd edge to another scc then that scc should have already been processed.
// 4. We first find the topological order and then reverses the whole graph to reverse the direction of traversal (scc dont get affected as they are strongly connected).
// 5. Now if we traverse the reversed graph in original direction by using topological order then we will get each sccs one by one and no scc will visit another one.

class Solution {
    vector<vector<int>> adj, revAdj, sccs;
    vector<bool> vis;
    stack<int> st;

    void topoOrder(int node) {
        vis[node] = true;
        for (int& nbr : adj[node])
            if (!vis[nbr]) topoOrder(nbr);
        st.push(node); // push after all its descendants are processed
    }

    void dfs(int node, vector<int>& cmp) {
        vis[node]=true;
        cmp.push_back(node);
        for(int& nbr:revAdj[node]){
            if(!vis[nbr]){
                dfs(nbr,cmp);
            }
        }
    }
public:
    vector<vector<int>> findSCCs(int n, vector<vector<int>>& edges) {
        adj.assign(n,{}); revAdj.assign(n,{});
        for(auto& e:edges){
            adj[e[0]].push_back(e[1]);
            revAdj[e[1]].push_back(e[0]);
        }

        // Order the nodes in decreasing order of finish time (latest finished first)
        // ie. topological order but for directed graph which may have cycles
        vis.assign(n,false);
        st=stack<int>();
        for(int i=0;i<n;i++){
            if(!vis[i]){
                topoOrder(i);
            }
        }
        
        // Process in reverse graph in order defined by above stack
        fill(vis.begin(), vis.end(), false);
        while (!st.empty()) {
            int node = st.top(); st.pop();
            if (!vis[node]) {
                vector<int> cmp;
                dfs(node, cmp);
                sccs.push_back(cmp);
            }
        }
        
        return sccs;
    }
};