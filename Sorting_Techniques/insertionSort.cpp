void insertionSort(vector<int>& arr) {
    int n=arr.size();
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

// Use Cases
// 1. In-place Stable Sorting
// 2. Sorting Small Data Sets (n<=50)
// 3. Nearly Sorted Data (Adaptive Sorting)
// 4. Used in Hybrid Sorting Algorithms (e.g. Timsort, Introsort)
// 5. Sorting Linked Lists

// Possible Optimization
// Shell Sort (Generalized Insertion Sort)
    // Uses gap-based insertion to improve efficiency, reducing the time complexity to around 𝑂(𝑛^1.25) in practical use.

    
// Recursive Insertion Sort
class Solution {
    void helper(auto& arr, int n){
        if(n<=1) return;
        helper(arr,n-1);
        int key=arr[n-1];
        int j=n-2;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
        
    }
  public:
    void insertionSort(vector<int>& arr) {
        int n=arr.size();
        helper(arr,n);
    }
};
 