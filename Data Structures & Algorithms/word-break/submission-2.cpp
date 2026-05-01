class Solution {
public:
    unordered_set<string> st;
    
    int n;

    bool solve(int idx, string &s,vector<int>&dp){
        if(idx == n)
            return true;

        if(dp[idx] != -1)
            return dp[idx];

        for(int l = 1; idx + l <= n; l++){
            string temp = s.substr(idx, l);

            if(st.find(temp) != st.end() && solve(idx + l, s,dp)){
                return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        

        for(string &word : wordDict){
            st.insert(word);
        }
        vector<int> dp(n+1,-1);


        return solve(0, s,dp);
    }
};