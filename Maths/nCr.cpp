using ll=long long;

// 1. Given Row and Column, to find nCr
ll nCr(int n, int r) {
    if (r > n) return 0;
    if (r > n - r) r = n - r; // Optimization (nCr = nC(n-r))

    ll res = 1;
    for (int i = 0; i < r; i++) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

// 2. To get a row of Pascal's Triangle
vector<ll> getRow(int rowIndex) {
    vector<ll> arr(rowIndex+1); arr[0]=1;
    for(int i=1;i<=rowIndex;i++){
        arr[i]=arr[i-1]*(rowIndex-i+1) / i;
    }
    return arr;
}
