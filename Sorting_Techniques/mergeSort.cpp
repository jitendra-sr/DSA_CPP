class Solution {
    int inversionCount=0;
    void merge(int l, int r, vector<int>& arr){
        int* tmp=new int[r-l+1]; int t=0;
        int mid=(l+r)/2;
        int i=l,j=mid+1;
        while(i<=mid && j<=r){
            if(arr[i]<=arr[j]) tmp[t++]=arr[i++];
            else {
                inversionCount+=mid-i+1;
                tmp[t++]=arr[j++];
            }
        }
        while(i<=mid) tmp[t++]=arr[i++];
        while(j<=r) tmp[t++]=arr[j++];
        for(int i=l;i<=r;i++) arr[i]=tmp[i-l];
        delete[] tmp;
    }
    void mergeSort(int l,int r, vector<int>& arr){
        if(l>=r) return;
        int mid=(l+r)/2;
        mergeSort(l,mid,arr);
        mergeSort(mid+1,r,arr);
        merge(l,r,arr);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(0,nums.size()-1,nums);
        return nums;
    }
};

// Use Cases
// 1. Stable Sorting
// 2. Sorting Large Data Sets
// 3. External Sorting (e.g. Timsort)
// 4. Parallel & Distributed Computing (e.g. Bitonic Sort)
// 6. Sorting Linked Lists
// 7. Inversion Count Problem

class Solution {
    void merge(int l, int r, auto& nums){
        vector<int> tmp(r-l+1); int ind=0;
        int mid=(l+r)/2;
        int i=l, j=mid+1;
        while(i<=mid && j<=r){
            if(nums[i]<=nums[j]) tmp[ind++]=nums[i++];
            else tmp[ind++]=nums[j++];
        }
        while(i<=mid) tmp[ind++]=nums[i++];
        while(j<=r) tmp[ind++]=nums[j++];
        copy(tmp.begin(), tmp.end(), nums.begin() + l);
    }
    void mergeSort(int l, int r, auto& nums){
        if(l>=r) return;
        int mid=(l+r)/2;
        mergeSort(l,mid,nums);
        mergeSort(mid+1,r,nums);
        // merge(l,r,nums); // Performance efficient
        inplace_merge(nums.begin()+l,nums.begin()+mid+1,nums.begin()+r+1); // Space efficient
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(0,nums.size()-1,nums);
        return nums;
    }
};