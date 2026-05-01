class Solution {
public:
    bool solve(string &s, int l, int r, vector<vector<int>>& dp){
        if(l >= r) return true;

        if(dp[l][r] != -1) return dp[l][r];

        if(s[l] == s[r])
            return dp[l][r] = solve(s, l+1, r-1, dp);

        return dp[l][r] = false;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        int maxlen = 0, start = 0;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(solve(s, i, j, dp)){
                    if(j - i + 1 > maxlen){
                        start = i;
                        maxlen = j - i + 1;
                    }
                }
            }
        }

        return s.substr(start, maxlen);
    }
};