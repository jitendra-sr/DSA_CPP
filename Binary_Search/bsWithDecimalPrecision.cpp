// https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1
class Solution {
    bool isPossible(vector<int> &arr, int k, double dis) {
        for (int i = 0; i < arr.size() - 1; i++) {
            int cnt = floor((arr[i + 1] - arr[i]) / dis);
            if (cnt * dis == arr[i + 1] - arr[i]) cnt--; // Handle exact division case
            k -= cnt;
            if (k < 0) return false;
        }
        return k >= 0;
    }
  public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
        int n = stations.size();
        double low = 0.0, high = stations[n - 1] - stations[0];
        double ans = high;
        
        while (high - low > 1e-6) { // Ensure precision up to 10^-6
            double mid = (low + high) / 2.0;
            if (isPossible(stations, k, mid)) {
                ans = mid;
                high = mid;
            } else {
                low = mid;
            }
        }
        return round(ans * 100) / 100.0; // Round to 2 decimal places for final answer if needed.
    }
};