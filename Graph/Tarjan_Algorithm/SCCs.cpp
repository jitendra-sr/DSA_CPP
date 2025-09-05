#include <bits/stdc++.h>
using namespace std;

// Tarjan's Algorithm to find Strongly Connected Components (SCC) in a directed graph

// Time Complexity: O(V + E)
// Space Complexity: O(V + E)

// Intuition
// 1. We will store nodes in a curr stack and use an array which will indicate wether node is present in curr stack (or recursion call). The process is just similar to finding cycles in directed graph but we form component not when we find it by single node or cycle (back-edge) but when we finish processing and identifying the head of component.
// 2. We will identify the head of scc using low-link and discovery time and pop all nodes from stack till we reach head of scc. These popped nodes will form one scc.
// 3. if low[node]==disc[node] then no back-edge was found by node or any of its descendants to any of its ancestors (having lower disc) hence it is the root of an scc.
// 4. We will only update low-link of a node from its back-edges (edges to ancestor in stack) and not from cross-edge or forward-edge (edges those nodes are not in stack) as they don't form cycle and hence not part of scc.
// Note: We dont need parent node as used in bridges and articulation points as graph will be directed so a node cant reach its parent and if it is reaching to its parent then parent-node will form scc.

// Working Technique
// if low == disc -> head of scc
// if node is visited and present in stack -> back-edge -> scc
// if node is visited and not present in stack -> cross-edge or forward-edge -> no scc
// sscs forms a DAG and edge connecting them will be cross-edge or forward-edge

class Solution {
    vector<vector<int>> adj, sscs;
    vector<int> disc, low; // using discovery time array as visited array
    vector<bool> inStack;
    stack<int> st;
    int timer;

    void dfs(int node){
        disc[node]=low[node]=timer++;
        st.push(node);
        inStack[node]=true;

        for(int& nbr:adj[node]){
            if(disc[nbr]==-1){ // not visited
                dfs(nbr);
                low[node]=min(low[node],low[nbr]);
            }
            else if(inStack[nbr]){ // back-edge
                low[node]=min(low[node],disc[nbr]);
            }
            // else cross-edge or forward-edge -> no scc -> do nothing
        }

        if(low[node]==disc[node]){ // head of scc
            vector<int> cmp;
            while(true){
                int top=st.top(); st.pop();
                inStack[top]=false;
                cmp.push_back(top);
                if(top==node) break;
            }
            sscs.push_back(cmp);
        }
    }
public:
    vector<vector<int>> findSCCs(int n, vector<vector<int>>& edges) {
        adj.assign(n,{});
        for(auto& e:edges){
            adj[e[0]].push_back(e[1]);
        }

        disc.assign(n,-1);
        low.assign(n,-1);
        inStack.assign(n,false);
        st=stack<int>();
        timer=0;
        sscs.clear();

        for(int i=0;i<n;i++){
            if(disc[i]==-1){
                dfs(i);
            }
        }

        return sscs;
    }
};