#include <bits/stdc++.h>
using namespace std;

// Dynamic Programming Algorithm for finding shortest paths between all pairs of vertices in a weighted graph with positive or negative edge weights.

// Time Complexity: O(V³)
// Space Complexity: O(V²)

// We can also construct the path using a parent or successor matrix

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &mat) {
        int n=mat.size();
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(mat[i][k]==1e8 || mat[k][j]==1e8) continue;
                    mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
                }
            }
        }
        
        // for(int i=0;i<n;i++) {
        //     if(mat[i][i]<0) cout<<"Negative Cycle Present.";
        // }
    }
};