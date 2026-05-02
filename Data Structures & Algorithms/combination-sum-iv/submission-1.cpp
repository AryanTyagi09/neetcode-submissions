class Solution {
public:
    int n;
      

    long long solve(vector<int>& nums, int target, vector<long long> &dp) {
        if (target == 0) return 1;
        if (target < 0) return 0;

        if (dp[target] != -1) return dp[target];

        long long res = 0;

        for (int i = 0; i < n; i++) {
            res += solve(nums, target - nums[i],dp);
        }

        return dp[target] = res;
    }

    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
         vector<long long> dp(target + 1, -1); 
        return solve(nums, target,dp);
    }
};