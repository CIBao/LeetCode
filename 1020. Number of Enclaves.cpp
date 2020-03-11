class Solution {
public:
    
    int DFS(int x, int y,vector<vector<int>>& grid, int& cnt){
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size())
            return 0;
        if(grid[x][y]==0)return 1;
        cnt++;
        grid[x][y] = 0;
        int up = DFS(x, y+1, grid, cnt);
        int down = DFS(x, y-1, grid, cnt);
        int left = DFS(x-1, y, grid, cnt);
        int right = DFS(x+1, y, grid, cnt);
        return up&&down&&left&&right;
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == 1) {
                    int cnt = 0;
                    res += DFS(i, j, grid, cnt)*cnt ;
                }
        return res;
    }
};
