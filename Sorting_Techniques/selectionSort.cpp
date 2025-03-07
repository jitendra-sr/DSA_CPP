void selectionSort(vector<int> &arr) {
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        int minInd=i;
        for(int j=i+1;j<n;j++) {
            if(arr[minInd]>arr[j]) minInd=j;
        }
        swap(arr[i],arr[minInd]);
    }
}

// Use Cases
// 1. In-place, Unstable Sorting
// 2. Sorting Small Data Sets (n<=100)
// 3. Number of Swaps Must Be Minimized

// Possible Optimization
// Stablity by Shifting
    // Instead of swapping, we can shift the elements to the right
    // int key = arr[minInd];
    // for (int k = minInd; k > i; k--) {
    //     arr[k] = arr[k - 1];
    // }
    // arr[i] = key;


// Recursive Selection Sort
class Solution {
    void helper(int i, auto& arr, int n){
        if(i>=n-1) return;
        int minInd=i;
        for(int j=i+1;j<n;j++) {
            if(arr[minInd]>arr[j]) minInd=j;
        }
        swap(arr[i],arr[minInd]);
        helper(i+1,arr,n);
    }
  public:
    void selectionSort(vector<int> &arr) {
        int n=arr.size();
        helper(0,arr,n);
    }
};