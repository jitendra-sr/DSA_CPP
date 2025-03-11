// # The lower bound of an element x in a sorted array is the first position (index) where x could be inserted without breaking the order.
//     1. Smallest index where arr[index] ≥ target.
//     2. If target exists in the array, it gives the first occurrence of target.
//     3. If x is not present, it returns the index where x could be inserted to maintain the sorted order.
//     4. If target is less than all elements in array, the lower bound is the first index (i.e., target would be inserted at the beginning).
//     5. If target is greater than all elements in array, the lower bound is the array length (i.e., target would be inserted at the end).

class Solution {
    // int lb = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
  public:
    int lowerBound(vector<int>& arr, int target) {
        int l=0, r=arr.size()-1, mid;
        int lb=arr.size();
        while(l<=r){
            mid=l+(r-l)/2;
            if(arr[mid]>=target){
                lb=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return lb;
    }
};