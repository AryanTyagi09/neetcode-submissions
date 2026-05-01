class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
        return 0;
        
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        int n=nums.size();
        int count=1;
        int maxl=1;
        for(int i=0;i<n-1;i++)
        {
             if(nums[i+1]==nums[i]+1)
             count++;

             else
             count=1;


             maxl=max(count,maxl);
        }
        return maxl;
    }
};
