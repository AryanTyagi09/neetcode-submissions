class Solution {
public:

int r,c;

int row[4] = {-1,1,0,0};
int col[4] = {0,0,-1,1};

bool valid(int i,int j){
    return i>=0 && j>=0 && i<r && j<c;
}

int numIslands(vector<vector<char>>& grid) {

    r = grid.size();
    c = grid[0].size();

    int count = 0;
    queue<pair<int,int>> q;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){

            if(grid[i][j]=='1'){

                count++;
                q.push({i,j});
                grid[i][j]='0';

                while(!q.empty()){

                    auto [x,y] = q.front();
                    q.pop();

                    for(int k=0;k<4;k++){

                        int nx = x + row[k];
                        int ny = y + col[k];

                        if(valid(nx,ny) && grid[nx][ny]=='1'){
                            grid[nx][ny]='0';
                            q.push({nx,ny});
                        }
                    }
                }
            }
        }
    }

    return count;
}
};