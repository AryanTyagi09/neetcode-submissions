class Solution {
public:
bool dfs(int src,int dest,vector<vector<int>>&adj,vector<bool>&vis){
   if(src==dest){
    return true;
   }
   vis[src]=1;
   for(int i=0;i<adj[src].size();i++){
    int nei=adj[src][i];
    if(!vis[nei]){
    if(dfs(nei,dest,adj,vis))
        return true;
    }
   }
   return false;
}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
       vector<vector<int>>adj(n+1);
       
       for(int i=0;i<n;i++){
        int a=edges[i][0];
        int b=edges[i][1];
        vector<bool>vis(n+1,0);
        if(!adj[a].empty() && !adj[b].empty() && dfs(a,b,adj,vis)){
            return {a,b};
        }
        else{
        adj[a].push_back(b);
        adj[b].push_back(a);
        }
        
       }
       return {}; 

    }
};
