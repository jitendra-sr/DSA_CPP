#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int m,n;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void dfs(int x, int y, auto& board){
    board[x][y]='#';
    for(int i=0;i<4;i++){
        int nx=x+dir[i][0], ny=y+dir[i][1];
        if(nx>=0 && nx<m && ny>=0 && ny<n && board[nx][ny]=='O') {
            dfs(nx,ny,board);
        }
    }
}

map<char,pair<int,int>> dir = {{'U',{-1,0}}, {'D',{1,0}}, {'R',{0,1}}, {'L',{0,-1}}};
int n,m;

ll sumOfDigits(ll n) {
    ll sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
ll gcd(ll a, ll b) {
    if(a < b) swap(a, b);
    while (b != 0) {
        ll rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}
void bfs(pair<int,int> src, pair<int,int> dest, vector<vector<char>>& grid) {
    vector<vector<char>> parent(n, vector<char>(m, ' '));
    queue<pair<int,int>> q; q.push(src);
    bool flag = false;
    while(!q.empty()) {
        auto& [x, y] = q.front(); q.pop();
        if(x == dest.first && y == dest.second){
            flag = true;
            break;
        }
        for(auto& [d, p] : dir) {
            int nx = x + p.first, ny = y + p.second;
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#') {
                grid[nx][ny] = '#';
                parent[nx][ny] = d;
                q.push({nx, ny});
            }
        }
    }
    if(!flag) {
        cout << "NO" << endl;
        return;
    }
    string path;
    pair<int,int> curr = dest;
    while(curr != src) {
        char move = parent[curr.first][curr.second];
        path.push_back(move);
        int dx = dir[move].first;
        int dy = dir[move].second;
        curr = {curr.first - dx, curr.second - dy};
    }
    reverse(path.begin(), path.end());
    cout << "YES" << endl;
    cout << path.size() << endl;
    cout << path << endl;
}
bool dfs(int i, int j, int pi, int pj, char color, auto& grid, auto& vis){
    vis[i][j]=true;

    for(auto& [d, p] : dir) {
        int nx = i + p.first, ny = j + p.second;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] != color) continue;
        if(!vis[nx][ny]) {
            bool res = dfs(nx, ny, i, j, color, grid, vis);
            if(res) return true;
        }
        else if(nx != pi || ny != pj) { // cycle detected
            return true;
        }
    }

    return false;
}