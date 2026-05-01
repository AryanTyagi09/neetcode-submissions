class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
      if(edges.size()!=n-1)
      return false;
      vector<vector<int>>adj(n);

      for(int i=0;i<edges.size();i++)
      {
        int a=edges[i][0];
        int b=edges[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
      }

      queue<int>q;
      q.push(0);
      vector<int>visited(n,false);
      visited[0]=true;
      int count=0;

      while(!q.empty())
      {
        int curr=q.front();
        q.pop();
        count++;
        for(int i=0;i<adj[curr].size();i++)
        {
            int neig=adj[curr][i];
            if(!visited[neig])
            {
                visited[neig]=true;
                q.push(neig);
            }
        }
      }
      return  count==n;
    }
};
