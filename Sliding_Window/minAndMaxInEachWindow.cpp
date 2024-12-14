// 2762. Continuous Subarrays
// https://leetcode.com/problems/continuous-subarrays/

// Approach 1 - Map (NlogK, K)
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        map<int,int> mp;
        long long cnt=0;
        int l=0,r=0;
        while(r<nums.size()){
            mp[nums[r]]++;
            while(mp.rbegin()->first-mp.begin()->first>2){
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
};

// Approach 2 - monotonic Deque (N, N)
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        deque<int> minDeq, maxDeq;
        // Storing min/max at front and pushing from back
        long long cnt=0;
        int l=0,r=0;
        while(r<nums.size()){
            while(!maxDeq.empty() && nums[maxDeq.back()]<nums[r]) 
                maxDeq.pop_back();
            maxDeq.push_back(r);

            while (!minDeq.empty() && nums[minDeq.back()]>nums[r])
                minDeq.pop_back();
            minDeq.push_back(r);

            while (!maxDeq.empty() && !minDeq.empty() &&
                   nums[maxDeq.front()] - nums[minDeq.front()] > 2) {
                // Deque having less index will shrink
                if (maxDeq.front() < minDeq.front()) {
                    l = maxDeq.front() + 1;
                    maxDeq.pop_front();
                } else {
                    l = minDeq.front() + 1;
                    minDeq.pop_front();
                }
            }

            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
};