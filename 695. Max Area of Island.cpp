class Solution {
public:
    int mx = 0;
    
    void dfs(vector<vector<int>>& grid,int x, int y, int& cnt){
        grid[x][y] = cnt++;
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        for(int i = 0; i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0&&ny>=0&&nx<grid.size()&&ny<grid[0].size())
                if(grid[nx][ny]==1)
                    dfs(grid, nx, ny, cnt);
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++)
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j]==1){
                int cnt = 2;
                dfs(grid, i, j, cnt);
                mx = max(mx, cnt-2);
            }
        }
        
        return mx;
    }
};
