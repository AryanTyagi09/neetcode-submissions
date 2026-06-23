#include <bits/stdc++.h>
#include <cstring>
using namespace std;

class Solution {
public:
int n;
vector<vector<int>>dp;
int solve(vector<int>&coins,int idx,int amount){
    if(amount==0){
        return 0;
    }
    if(idx==n) return 1e8;
    if(dp[idx][amount]!=-1) return dp[idx][amount];

    int take=1e8;

    if(coins[idx]<=amount){
         take=1+solve(coins,idx,amount-coins[idx]);
    }
    int not_take=solve(coins,idx+1,amount);

    return dp[idx][amount]= min(take,not_take);
}
int coinChange(vector<int>& coins, int amount) {
        n=coins.size();
        dp.assign(n, vector<int>(amount + 1, -1));
      int ans= solve(coins,0,amount);
       return ans >= 1e8 ? -1 : ans;
    }
};