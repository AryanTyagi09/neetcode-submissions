class Solution {
public:

    int n;
    int OFFSET = 20000;

    int solve(int i,
              int sum,
              int target,
              vector<int>& nums,
              vector<vector<int>>& dp) {

        
        if(i == n) {

            if(sum == target)
                return 1;

            return 0;
        }

        
        if(dp[i][sum + OFFSET] != -1)
            return dp[i][sum + OFFSET];

        
        int add =
            solve(i + 1,
                  sum + nums[i],
                  target,
                  nums,
                  dp);


        int sub =
            solve(i + 1,
                  sum - nums[i],
                  target,
                  nums,
                  dp);

        return dp[i][sum + OFFSET]
               = add + sub;
    }

    int findTargetSumWays(vector<int>& nums,
                          int target) {

        n = nums.size();

        vector<vector<int>> dp(
            n,
            vector<int>(40001, -1)
        );

        return solve(0, 0, target, nums, dp);
    }
};