#include <bits/stdc++.h>
using namespace std;

// Disjoint Set Union (DSU) or Union-Find is a data structure that keeps track of a set of elements partitioned into disjoint subsets.

// Time Complexity: O(α(N)), where α is the inverse Ackermann function grows slower than logN, practically ≤ 4 for all reasonable N (even up to 10^18) and O(m * α(N)) for m operations
// Space Complexity: O(N)

// Path compression is the optimization technique used in the find operation to flatten the structure of the tree whenever find is called, making future queries faster by storing the root of the set directly in the parent array.

// DSU using Rank
// Rank approximates the height of the tree (estd upper bound), decides which root becomes the parent when merging two sets
struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0;i<n;i++) parent[i] = i;
    }
    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;
        if (rank[u] < rank[v]) swap(u, v);
        parent[v] = u;
        if (rank[u] == rank[v]) rank[u]++;
    }
};

// DSU using size
struct DSU {
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);  // Initialize parent to itself
    }
    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]); // Path compression
    }
    void unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;
        if (size[u] < size[v]) swap(u, v);
        parent[v] = u;
        size[u] += size[v];
    }
};