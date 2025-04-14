// 40. Combination Sum II
// https://leetcode.com/problems/combination-sum-ii/

class Solution {
public:
    void backtrack(int ind, int target, vector<int>& arr, vector<int>& path, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(path);
            return;
        }

        for (int i = ind; i < arr.size(); ++i) {
            if (i > ind && arr[i] == arr[i - 1]) continue;
            if (arr[i] > target) break;

            path.push_back(arr[i]);
            backtrack(i + 1, target - arr[i], arr, path, res);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        backtrack(0, target, candidates, path, res);
        return res;
    }
};

// Features
// 1. N-ary structure
// 2. Combinations (k out of n)
// 3. Helps enforce constraints, like "no duplicate combinations", or "use each element only once".
// 4. Think of it this way:
    // Pick/Not-Pick: “Do I want this or not?” → good for binary situations
    // Loop-based: “What options do I have from here?” → good for multi-choice scenarios
