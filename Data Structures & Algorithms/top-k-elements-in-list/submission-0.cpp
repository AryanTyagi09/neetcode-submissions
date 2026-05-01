class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>freq;
        for(int i=0;i<n;i++)
        {
           freq[nums[i]]++;
           
        }
        priority_queue<pair<int,int>>pq;
        for(auto it =freq.begin();it !=freq.end();it++)
        {
            pq.push({it->second,it->first});
        }
        vector<int>res;
        while(k--)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;

    }
};
