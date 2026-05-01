class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        vector<int>ans;
        for(int i=0;i<prerequisites.size();i++)
        {
            int a=prerequisites[i][0];
            int b=prerequisites[i][1];
            
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

        // BFS
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);

            // FIXED LOOP
            for (int i = 0; i < adj[curr].size(); i++) {
                int neighbor = adj[curr][i];
                indegree[neighbor]--;

                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        if (ans.size() == numCourses)
            return ans;

        return {}; 
    }
    
         
};
