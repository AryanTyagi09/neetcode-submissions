class Solution {
public:
int row[4]={1,-1,0,0};
int col[4]={0,0,1,-1};
int r,c;
bool valid(int i,int j){
    return i>=0 &&i<r && j>=0 && j<c;
}
    int orangesRotting(vector<vector<int>>& grid) {
      r=grid.size();
      c=grid[0].size();
     queue<pair<int,int>>q;
     int fresh=0;
     for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j]==2){
                q.push({i,j});

            }
            else if(grid[i][j]==1){
                fresh++;
            }

        }
     }
     int min=0;
     while(!q.empty() && fresh>0){
        int size=q.size();
        while(size--){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nx=x+row[k];
                int ny=y+col[k];

                if(valid(nx,ny) && (grid[nx][ny]==1)){
                    q.push({nx,ny});
                    grid[nx][ny]=2;fresh--;

                }
            }
        }
        min++;
     
 
    }
    if(fresh==0){
        return min;
    }
    return -1;
    }
};