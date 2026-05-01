class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int j=k-1;
      priority_queue<int>pq;
      for(int i=0;i<nums.size();i++)
      {
        pq.push(nums[i]);
      }  
      while(j--)
      {
        pq.pop();
      }
      return pq.top();
    }
};
