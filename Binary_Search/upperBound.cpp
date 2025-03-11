// # The upper bound of x in a sorted array is the first position (index) where an element strictly greater than x exists.
//     1. Smallest index where arr[index] > target.
//     2. If target exists multiple times, the upper bound gives the first index after its last occurrence.
//     3. If x is not present, it returns the index where x would be inserted  to maintain the sorted order.
//     4. If target is less than all elements in array, the lower bound is the first index (i.e., target would be inserted at the beginning).
//     5. If target is greater than all elements in array, the lower bound is the array length (i.e., target would be inserted at the end).

class Solution {
    // int ub = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
    public:
    int upperBound(vector<int>& arr, int target) {
        int l=0, r=arr.size()-1, mid;
        int ub=arr.size();
        while(l<=r){
            mid=l+(r-l)/2;
            if(arr[mid]>target){
                ub=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ub;
    }
};