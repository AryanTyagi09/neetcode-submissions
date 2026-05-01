class Solution {
public:
int robl(vector<int>& nums,int l,int r){
       int len = r - l + 1;
        if (len == 1) return nums[l];
    vector<int>dp(len,-1);
    dp[0] = nums[l];
    dp[1] = max(nums[l], nums[l+1]);
        
        for (int i = 2; i < len; i++) {
            dp[i] = max(nums[l + i] + dp[i-2], dp[i-1]);
        }
        
        return dp[len-1];
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];

        if(n==2)  return max(nums[0],nums[1]);

        int case1=robl(nums,0,n-2);
        int case2=robl(nums,1,n-1);

        return max(case1,case2);
    }
};
