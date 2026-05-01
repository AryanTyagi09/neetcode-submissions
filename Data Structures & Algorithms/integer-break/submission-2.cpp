class Solution {
public:
int solve(int n,vector<int>&dp){
    if(n==1)
    return 1;
    if(dp[n]!=-1)
    return dp[n];
    

    int res=INT_MIN;
    for(int i=1;i<=n-1;i++){
        int pro=i*max(n-i,solve(n-i,dp));
        res=max(res,pro);
    }
    return dp[n]= res;
}
    int integerBreak(int n) {
        vector<int> dp(n+1, -1); 
         return solve(n,dp);
    }
};