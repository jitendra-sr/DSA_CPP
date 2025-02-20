void bubbleSort(vector<int>& arr) {
    int n=arr.size();
    bool swapped;
    for (int i=0;i<n-1;i++) {
        swapped = false;
        for (int j=0;j<n-1-i;j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// Use Cases
// 1. In-place Stable Sorting
// 2. Sorting Small Data Sets (n<=20)
// 3. Nearly Sorted Data (with Early Termination Optimization) 

// Possible Optimization
// Bidirectional Bubble Sort (Cocktail Sort)
    // If the array is nearly sorted, bidirectional swapping (moving both largest and smallest elements towards their correct positions in a single pass) can help improve performance.
    // This is called Cocktail Shaker Sort and avoids unnecessary iterations.


// Recursive Bubble Sort
class Solution {
    void helper(auto& arr, int n){
        if(n<=1) return;
        bool swapped;
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                swap(arr[i],arr[i+1]);
                swapped=true;
            } 
        }
        if(!swapped) return;
        helper(arr,n-1);
    }
  public:
    void bubbleSort(vector<int>& arr) {
        int n=arr.size();
        helper(arr,n);
    }
};
