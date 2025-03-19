pair<int, int> findOptimalFactors(int n) {
    for (int i = sqrt(n); i >= 1; i--) {
        if (n % i == 0) {
            return {i, n / i};
        }
    }
    return {1, n};
}
bool searchInArray(vector<int>& arr, int target) {
    int n = arr.size();
    auto [rows, cols] = findOptimalFactors(n);
    int l = 0, r = rows - 1, mid;

    while (l < r) {
        mid = l + (r - l) / 2;
        int lastInRow = arr[mid * cols + (cols - 1)];
        
        if (lastInRow == target) return true;
        if (lastInRow < target) l = mid + 1;
        else r = mid;
    }
    // r will be the row where target should be present
    auto it = lower_bound(arr.begin() + r * cols, arr.begin() + r * cols + cols, target);
    return (it != arr.begin() + r * cols + cols && *it == target);
}
