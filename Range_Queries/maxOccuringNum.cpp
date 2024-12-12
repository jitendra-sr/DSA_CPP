// 2779. Maximum Beauty of an Array After Applying Operation
// https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/description/

// Note: Take care of the size of prefix array.
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        int sz=maxi+k+2;
        vector<int> prefixSum(sz, 0);

        for (int i = 0; i < n; i++) {
            int st = nums[i] - k, end = nums[i] + k;
            if (st <= 0) prefixSum[0] += 1;
            else prefixSum[st] += 1;
            prefixSum[end + 1] -= 1;
        }

        int maxBeauty = 0, sum=0;
        for (int i = 0; i < sz; i++) {
            sum+=prefixSum[i];
            maxBeauty=max(maxBeauty,sum);
        }

        return maxBeauty;
    }
};