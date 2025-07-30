#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(V + E)
// Space Complexity: O(V + E)

// 1. A bipartite graph is a graph whose vertices can be divided into two sets such that:
// Every edge connects a vertex from one set to a vertex in the other set.
// No two vertices within the same set are connected.
// 2. A graph is bipartite if you can color all the nodes using two colors so that no two adjacent nodes have the same color.

// Note: If graph have an odd cycle, then it is not bipartite.

class SolutionBFS {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i]=0;
                queue<int> q; q.push(i);

                while(!q.empty()){
                    int node=q.front(); q.pop();

                    for(int nbr:graph[node]){
                        if(color[nbr]==-1){
                            color[nbr]=1-color[node];
                            q.push(nbr);
                        }
                        else if(color[nbr]==color[node]) return false;
                    }
                }
            }
        }

        return true;
    }
};

class SolutionDFS {
    bool dfs(int node, auto& graph, auto& color){
        for(int nbr:graph[node]){
            if(color[nbr]==-1){
                color[nbr]=1-color[node];
                if(!dfs(nbr,graph,color)) return false;
            }
            else if(color[nbr]==color[node]) return false;
        }
        
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i]=0;
                if(!dfs(i,graph,color)) return false;
            }
        }

        return true;
    }
};