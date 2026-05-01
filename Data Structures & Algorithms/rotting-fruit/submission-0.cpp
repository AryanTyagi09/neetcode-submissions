class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int r = grid.size();
        int c = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] == 2)
                    q.push({i,j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }

        int minutes = 0;

        int row[4] = {-1,1,0,0};
        int col[4] = {0,0,-1,1};

        while(!q.empty() && fresh > 0){

            int size = q.size();
            minutes++;

            for(int i=0;i<size;i++){

                auto curr = q.front();
                q.pop();

                int x = curr.first;
                int y = curr.second;

                for(int k=0;k<4;k++){

                    int nx = x + row[k];
                    int ny = y + col[k];

                    if(nx>=0 && nx<r && ny>=0 && ny<c && grid[nx][ny]==1){

                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx,ny});
                    }
                }
            }
        }

        if(fresh > 0)
            return -1;

        return minutes;
    }
};