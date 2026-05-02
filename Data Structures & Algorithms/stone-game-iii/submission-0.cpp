class Solution {
public:
    int n;
    

    int solve(vector<int>& stoneValue, int i, vector<int>& dp) {
        if (i >= n) return 0;

        if (dp[i] != -1) return dp[i];

        int res = INT_MIN;
        int sum = 0;

        for (int k = 0; k < 3 && i + k < n; k++) {
            sum += stoneValue[i + k];
            res = max(res, sum - solve(stoneValue, i + k + 1,dp));
        }

        return dp[i] = res;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        vector<int> dp(n+1,-1);

        int diff = solve(stoneValue, 0,dp);

        if (diff > 0) return "Alice";
        if (diff < 0) return "Bob";
        return "Tie";
    }
};