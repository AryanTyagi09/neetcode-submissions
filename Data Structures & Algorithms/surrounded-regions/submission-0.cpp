class Solution {
public:
    int r,c;
    int row[4]={-1,1,0,0};
    int col[4]={0,0,-1,1};

    bool valid(int i,int j){
        return i>=0 && i<r && j>=0 && j<c;
    }

    void solve(vector<vector<char>>& board) {

        r = board.size();
        c = board[0].size();

        queue<pair<int,int>> q;

        // top row
        for(int i=0;i<c;i++){
            if(board[0][i]=='O'){
                q.push({0,i});
                board[0][i]='T';
            }
        }

        // left column
        for(int j=1;j<r;j++){
            if(board[j][0]=='O'){
                q.push({j,0});
                board[j][0]='T';
            }
        }

        // bottom row
        for(int i=1;i<c;i++){
            if(board[r-1][i]=='O'){
                q.push({r-1,i});
                board[r-1][i]='T';
            }
        }

        // right column
        for(int j=1;j<r-1;j++){
            if(board[j][c-1]=='O'){
                q.push({j,c-1});
                board[j][c-1]='T';
            }
        }

        // BFS
        while(!q.empty()){
            int newi=q.front().first;
            int newj=q.front().second;
            q.pop();

            for(int k=0;k<4;k++){
                int ni=newi+row[k];
                int nj=newj+col[k];

                if(valid(ni,nj) && board[ni][nj]=='O'){
                    board[ni][nj]='T';
                    q.push({ni,nj});
                }
            }
        }

        // final conversion
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){

                if(board[i][j]=='O')
                    board[i][j]='X';

                else if(board[i][j]=='T')
                    board[i][j]='O';
            }
        }
    }
};