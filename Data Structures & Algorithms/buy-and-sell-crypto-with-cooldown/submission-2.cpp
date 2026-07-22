class Solution {
public:
int solve(vector<int>&prices,int i,int n,bool buy,vector<vector<int>>&dp){
    if(i>=n) return 0;
    if(dp[i][buy]!=-1) return dp[i][buy];
    if(buy){
      int take=solve(prices,i+1,n,false,dp)-prices[i];
      int not_take=solve(prices,i+1,n,true,dp);

      return dp[i][buy] =max(take,not_take);
    }
    else{
      int sell=prices[i]+solve(prices,i+2,n,true,dp);
      int not_sell=solve(prices,i+1,n,false,dp);

      return dp[i][buy]= max(sell,not_sell);
    }

}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
         return solve(prices, 0,n,true,dp);
    }
};
