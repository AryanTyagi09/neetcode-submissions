class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build graph
        for (int i = 0; i < prerequisites.size(); i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            adj[b].push_back(a);
            indegree[a]++;
        }

        // Queue for BFS
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;

        // BFS
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            count++;

            // FIXED LOOP
            for (int i = 0; i < adj[curr].size(); i++) {
                int neighbor = adj[curr][i];
                indegree[neighbor]--;

                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return count == numCourses;
    }
};