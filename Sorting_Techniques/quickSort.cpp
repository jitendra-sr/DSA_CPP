class Solution {
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[low];
        int i = low, j = high;
        while(true){
            while (arr[i] < pivot) i++;
            while (arr[j] > pivot) j--;
            if (i >= j) return j;
            swap(arr[i], arr[j]);
            i++; j--;
        }
        return j;
    }
    void quickSort(vector<int>& arr, int low, int high) {
        if (low >= high) return;
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
};

// Use Cases
// 1. In-place Unstable Sorting
// 2. Sorting Large Data Sets
// 3. Quick Selection Algorithm (Finding kth Smallest/Largest Element)
// 4. QuickSort is faster than MergeSort in practice due to lower constant factors and better cache locality.

// Possible Optimizations
// 1. Choosing a Better Pivot:
    // Randomized QuickSort: Randomly selecting a pivot can help mitigate the risk of consistently bad input ordering.
    // Median of Three: Use the median of the first, middle, and last elements as the pivot. This helps avoid the worst-case scenario of already sorted (or reverse sorted) arrays.
    // Median of Medians: Use the median of medians as the pivot to ensure a balanced partitioning.
// 2. Tail Call Optimization: 
    // Instead of recursively sorting both partitions, always sort the smaller partition first and use a loop for the larger partition Convert the recursive calls to iterative calls to reduce stack space.
// 3. Switching to Insertion Sort for Small Arrays:
    // Use QuickSort for large partitions and switch to Insertion Sort for smaller partitions to reduce overhead.
// 4. Handling Duplicates Efficiently:
    // Three-Way Partitioning (e.g., Dutch National Flag Algorithm): Partition elements into three groups: < pivot, == pivot, > pivot. This helps handle arrays with many duplicate elements efficiently.