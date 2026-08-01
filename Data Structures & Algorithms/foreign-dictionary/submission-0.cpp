class Solution {
public:
    bool solve(string s, string t, vector<vector<int>>& adj) {

        int len = min(s.size(), t.size());

        for (int i = 0; i < len; i++) {

            if (s[i] != t[i]) {
                adj[s[i] - 'a'].push_back(t[i] - 'a');
                return true;
            }
        }

        if (s.size() > t.size())
            return false;

        return true;
    }

    string foreignDictionary(vector<string>& words) {

        int n = words.size();

        vector<vector<int>> adj(26);
        vector<bool> present(26, false);

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < words[i].size(); j++) {
                present[words[i][j] - 'a'] = true;
            }
        }

      
        for (int i = 0; i < n - 1; i++) {
            if (!solve(words[i], words[i + 1], adj))
                return "";
        }

       
        vector<int> indegree(26, 0);

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                int v = adj[i][j];
                indegree[v]++;
            }
        }

        queue<int> q;

     
        for (int i = 0; i < 26; i++) {
            if (present[i] == true && indegree[i] == 0) {
                q.push(i);
            }
        }

        string ans = "";

        while (!q.empty()) {

            int u = q.front();
            q.pop();

            ans += char(u + 'a');

            for (int i = 0; i < adj[u].size(); i++) {

                int v = adj[u][i];

                indegree[v]--;

                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

       
        int cnt = 0;

        for (int i = 0; i < 26; i++) {
            if (present[i] == true) {
                cnt++;
            }
        }

       
        if (ans.size() != cnt)
            return "";

        return ans;
    }
};
