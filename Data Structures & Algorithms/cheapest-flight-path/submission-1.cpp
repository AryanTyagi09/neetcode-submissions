class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<int> distance(n, INT_MAX);

        unordered_map<int, vector<pair<int,int>>> adj;

        // Build graph
        for(int i = 0; i < flights.size(); i++) {
            int u    = flights[i][0];
            int v    = flights[i][1];
            int cost = flights[i][2];

            adj[u].push_back({v, cost});
        }

        queue<pair<int,int>> que;
        que.push({src, 0});

        distance[src] = 0;

        int level = 0;

        while(!que.empty() && level <= k) {

            int N = que.size();

            // Important: copy current distances
            vector<int> temp = distance;

            while(N--) {

                int u = que.front().first;
                int d = que.front().second;
                que.pop();

                for(int i = 0; i < adj[u].size(); i++) {

                    int v    = adj[u][i].first;
                    int cost = adj[u][i].second;

                    if(d + cost < temp[v]) {

                        temp[v] = d + cost;

                        que.push({v, d + cost});
                    }
                }
            }

            distance = temp;
            level++;
        }

        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};