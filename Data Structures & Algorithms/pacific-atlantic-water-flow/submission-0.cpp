class Solution {
public:

vector<vector<int>> direction{{1,0},{-1,0},{0,-1},{0,1}};

void dfs(vector<vector<int>>& heights,int i,int j,int prev,
         vector<vector<bool>>& visited)
{
    int m = heights.size();
    int n = heights[0].size();

    if(i<0 || i>=m || j<0 || j>=n)
        return;

    if(visited[i][j] || heights[i][j] < prev)
        return;

    visited[i][j] = true;

    for(int k=0;k<direction.size();k++)
    {
        int ni = i + direction[k][0];
        int nj = j + direction[k][1];

        dfs(heights,ni,nj,heights[i][j],visited);
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

    int m = heights.size();
    int n = heights[0].size();

    vector<vector<int>> ans;

    vector<vector<bool>> pacific(m,vector<bool>(n,false));
    vector<vector<bool>> atlantic(m,vector<bool>(n,false));

    for(int j=0;j<n;j++)
    {
        dfs(heights,0,j,INT_MIN,pacific);
        dfs(heights,m-1,j,INT_MIN,atlantic);
    }

    for(int i=0;i<m;i++)
    {
        dfs(heights,i,0,INT_MIN,pacific);
        dfs(heights,i,n-1,INT_MIN,atlantic);
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(pacific[i][j] && atlantic[i][j])
                ans.push_back({i,j});
        }
    }

    return ans;
}
};