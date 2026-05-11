
class Solution {
public:
int m,n;


    bool solve(int i, int j, string& s, string& p,vector<vector<int>>&dp) {
        if (j == p.length())
            return i == s.length();
            
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        bool ans = false;

        bool first_match = (i < s.length() && (p[j] == s[i] || p[j] == '.'));

        if (j + 1 < p.length() && p[j + 1] == '*') {
            int not_take = solve(i, j + 2, s, p,dp);
            int take=    (first_match && solve(i + 1, j, s, p,dp));
            return dp[i][j]= not_take || take;
        }
          return dp[i][j]= first_match && solve(i + 1, j + 1, s, p,dp);
        
    }
    
        bool isMatch(string s, string p) {
            m=s.length();
            n=p.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(0, 0, s, p,dp);
    }
};

