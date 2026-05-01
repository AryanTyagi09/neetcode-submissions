class Solution {
public:
void dfs(int i,vector<vector<int>>adj,vector<bool>&visited)
{
   visited[i]=true;
   for(int j=0;j<adj[i].size();j++)
   {
    int neig=adj[i][j];
    if(!visited[neig])
    {
        dfs(neig,adj,visited);
    }
   }
}
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
            int a=edges[i][0];
            int b=edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);

        }
        vector<bool>visited(n,false);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                
                dfs(i,adj,visited);
                count++;
            }
        }
        return count;

    }
};
