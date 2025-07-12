#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<climits>

using namespace std;
using ll = long long;

ll sumOfDigits(ll n);
ll gcd(ll a, ll b);

void bfs(pair<int,int> src, pair<int,int> dest, vector<vector<char>>& grid, int n, int m) {
    vector<vector<char>> parent(n, vector<char>(m, ' '));
    unordered_map<char, pair<int,int>> dir = {{'U', {-1, 0}}, {'D', {1, 0}}, {'L', {0, -1}}, {'R', {0, 1}}};
    
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

int main(){
    int n,m; cin>>n>>m;
    vector<vector<char>> grid(n, vector<char>(m));
    pair<int,int> src, dest;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if(grid[i][j]=='A') src={i, j};
            if(grid[i][j]=='B') dest={i, j};
        }
    }
    bfs(src, dest, grid, n, m);

    return 0;
}

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