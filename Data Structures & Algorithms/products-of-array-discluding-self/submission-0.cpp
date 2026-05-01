class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        vector<int> ans(n);

        // Left product
        for(int i = 1; i < n; i++) {
            left[i] = left[i-1] * nums[i-1];
        }

        // Right product
        for(int i = n-2; i >= 0; i--) {
            right[i] = right[i+1] * nums[i+1];
        }

        // Final answer
        for(int i = 0; i < n; i++) {
            ans[i] = left[i] * right[i];
        }

        return ans;
    }
};