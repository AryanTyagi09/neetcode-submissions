class Solution {
public:
    int m, n;

    int solve(string &text1, string &text2, int i, int j, vector<vector<int>>& dp) {
        if(i >= m || j >= n) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(text1[i] == text2[j]){
            return dp[i][j] = 1 + solve(text1, text2, i+1, j+1, dp);
        }
        else{
            int include_i = solve(text1, text2, i+1, j, dp);
            int include_j = solve(text1, text2, i, j+1, dp);

            return dp[i][j] = max(include_i, include_j);
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        m = text1.size();
        n = text2.size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(text1, text2, 0, 0, dp);
    }
};