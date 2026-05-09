class Solution {
public:

    int n, m;

   int row[4]={-1,1,0,0};
   int col[4]={0,0,-1,1};

    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>> &dp) {

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 1;

        for(int k=0;k<4;k++) {

            int ni = i + row[k];
            int nj = j + col[k];

            if (ni >= 0 && nj >= 0 &&
                ni < n && nj < m &&
                matrix[ni][nj] > matrix[i][j]) {

                ans = max(ans,1 + dfs(ni, nj, matrix,dp));
            }
        }

        return dp[i][j] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        n = matrix.size();
        m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        int res = 0;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                res = max(res,dfs(i, j, matrix,dp));
            }
        }

        return res;
    }
};