class Solution {
public:
int row[4]={-1,1,0,0};
int col[4]={0,0,-1,1};
int m,n;

  bool valid(int i,int j){
    return i>=0 && i<n && j>=0 && j<m;
  }
    void islandsAndTreasure(vector<vector<int>>& grid) {
         n=grid.size();
         m=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int ni=q.front().first;
            int nj=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int newi=ni + row[k];
                int newj=nj+col[k];
                if(valid(newi,newj) && grid[newi][newj]==2147483647){
                    q.push({newi,newj});
                    grid[newi][newj]=grid[ni][nj]+1;

                }
            }
        }
        
    }
    
};
