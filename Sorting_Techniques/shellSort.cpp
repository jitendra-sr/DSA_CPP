void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Perform insertion sort for the elements at gap intervals
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

// Use Cases
// 1. In-place unstable Sorting
// 2. Sorting small to medium Data Sets
// 3. Nearly Sorted Data
// 4. Avoids Worst-Case O(n²) of Insertion Sort

// Possible Optimization
// Choosing a Better Gap Sequence
    // Hibbard’s sequence: 1, 3, 7, 15, 31, ... (2^k - 1) → Improves performance to O(n^(3/2))
    // Knuth’s sequence: (3^k - 1)/2 → Balances performance and simplicity
    // Sedgewick’s sequence: More optimized for practical cases.