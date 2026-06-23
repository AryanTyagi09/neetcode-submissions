class Solution {
public:
int n;
vector<int>dp;
int solve(vector<int>&nums,int idx){
    if(idx>=n){
        return 0;
    }
    if(dp[idx]!=-1) return dp[idx];
    int rob=nums[idx]+solve(nums,idx+2);
    int skip=solve(nums,idx+1);
    return dp[idx]=max(rob,skip);
}
    int rob(vector<int>& nums) {
         n=nums.size();
         dp.assign(n,-1);
       return  solve(nums,0);
    }
};
