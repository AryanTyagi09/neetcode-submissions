class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        // Count frequency of each task
        vector<int> freq(26, 0);
        for (char ch : tasks) {
            freq[ch - 'A']++;
        }

        // Max heap to store frequencies
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push(freq[i]);
            }
        }

        int time = 0;

        while (!pq.empty()) {

            vector<int> temp;
            int workDone = 0;

            // Execute at most (n + 1) tasks in one cycle
            for (int i = 0; i <= n; i++) {

                if (!pq.empty()) {
                    int top = pq.top();
                    pq.pop();

                    top--;
                    workDone++;

                    if (top > 0) {
                        temp.push_back(top);
                    }
                }
            }

            // Push remaining frequencies back into the heap
            for (int i = 0; i < temp.size(); i++) {
                pq.push(temp[i]);
            }

            // Update total time
            if (pq.empty()) {
                time += workDone;
            } else {
                time += (n + 1);
            }
        }

        return time;
    }
};