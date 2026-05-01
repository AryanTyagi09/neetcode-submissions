class Solution {
public:
    vector<vector<int>> ans;

    void solve(int idx, vector<int>& nums, int target, vector<int>& temp) {
        
        // ✅ found valid combination
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {

            // ❌ skip duplicates
            if (i > idx && nums[i] == nums[i - 1]) continue;

            // ❌ pruning
            if (nums[i] > target) break;

            // ✅ take
            temp.push_back(nums[i]);

            // move forward (cannot reuse)
            solve(i + 1, nums, target - nums[i], temp);

            // backtrack
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // 🔥 important
        vector<int> temp;
        solve(0, candidates, target, temp);
        return ans;
    }
};