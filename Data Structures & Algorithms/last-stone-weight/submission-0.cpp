class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        
        for (int x : stones) {
            pq.push(x);
        }

        // Step 2: Process
        while (pq.size() > 1) {
            int y = pq.top(); pq.pop();
            int x = pq.top(); pq.pop();

            if (y != x) {
                pq.push(y - x);
            }
        }

        // Step 3: Result
        return pq.empty() ? 0 : pq.top();
    }
};