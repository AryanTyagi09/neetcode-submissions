class Solution {
public:
void dfs(int node,vector<vector<int>>&adj,vector<int>&vis){
    vis[node]=1;
    for(int i=0;i<adj[node].size();i++){
        int next=adj[node][i];
        if(!vis[next]){
            dfs(next,adj,vis);
        }
    }
}
    int countComponents(int n, vector<vector<int>>& edges) {
      vector<vector<int>>adj(n);
      for(int i=0;i<edges.size();i++){
        int a=edges[i][0];
        int b=edges[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
      }
       vector<int>vis(n,0);
       int count=0;
       for(int i=0;i<n;i++){
        if(!vis[i]){
            count++;
            dfs(i,adj,vis);
        }
       }
       return count;


    }
};
