class Solution {
private: 
    void recurPermute(vector<int>& perm, vector<int> &nums, vector<vector<int>> &res, vector<bool> &vis) {
        if(perm.size() == nums.size()) {
            res.push_back(perm); 
            return; 
        }

        for(int i = 0;i<nums.size();i++) {
            if (vis[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1]) continue;

            perm.push_back(nums[i]);
            vis[i] = true; 
            recurPermute(perm, nums, res, vis);
            vis[i] = false;
            perm.pop_back(); 
        } 
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(begin(nums),end(nums));
        vector<vector<int>> res; 
        vector<bool> vis(nums.size());
        vector<int> perm;
        recurPermute(perm, nums, res, vis); 
        return res; 
    }
};

// Logic behind skipping the repeated elements - 

// vis[i-1] == true:
// This means that the previous identical number has already been used in the current permutation path ie. we're at the next level of the recursive tree and we will keep generating the permutation by taking current number as it would lead to a single different permutation which have all numbers.

// !vis[i - 1] == false:
// This means that the previous identical number is not used in the current permutation path ie. we're still at the same level of the recursive tree. We will skip the current duplicate to avoid making the same permutation again as previous number has already generated that permutation and marked it as false.
