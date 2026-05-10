class Solution {
public:
int n,m;
int solve(string s,string t,int i,int j,vector<vector<int>>&dp){
    if(j==m) return 1;
    if(i==n) return 0;

    if(dp[i][j]!=-1) return dp[i][j];
    int ans=0;

    if(s[i]==t[j]){
      ans=solve(s,t,i+1,j+1,dp) + solve(s,t,i+1,j,dp);
    }
    else{
        ans=solve(s,t,i+1,j,dp);
    }
    return dp[i][j]=ans;
}

    int numDistinct(string s, string t) {
         n=s.size();
         m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        return solve(s,t,0,0,dp);
        
    }
};
