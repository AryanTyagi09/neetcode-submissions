class Solution {
public:
int n; 
vector<int>dp;
int solve(int idx,vector<int>&cost){
    if(idx>=n){
        return 0;
    }
    if(dp[idx]!=-1) return dp[idx];
    int a=cost[idx]+solve(idx+1,cost);
    int b=cost[idx]+solve(idx+2,cost);
    return dp[idx]=min(a,b);
}
    int minCostClimbingStairs(vector<int>& cost) {
       
      n=cost.size();
      dp.assign(n,-1);
      
      return min(solve(0,cost),solve(1,cost));


    }
};
