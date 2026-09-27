class Solution {
public:
int r,c;
int row[4]={1,-1,0,0};
int col[4]={0,0,1,-1};
bool valid(int i,int j){
    return i>=0 && i<r && j>=0 && j<c;
}

    int maxAreaOfIsland(vector<vector<int>>& grid) {
      r=grid.size();
      c=grid[0].size();
     queue<pair<int,int>>q;
     int mx=0;
    
     for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j]==1){
                q.push({i,j});
                grid[i][j]=0;
                 int count=0;
                
                while(!q.empty()){
                    count++;
                    int x=q.front().first;
                    int y=q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int nx=x+row[k];
                        int ny=y+col[k];
                        if(valid(nx,ny)&&(grid[nx][ny]==1)){
                            q.push({nx,ny});
                            grid[nx][ny]=0;
                        }
                    }
                }
                mx=max(count,mx);
            }
        }
     }
     return mx;
        
    }
};