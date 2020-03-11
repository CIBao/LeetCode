class Solution {
public:
    
    int DFS(int x, int y,vector<vector<int>>& grid){
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size())
            return 0;
        if(grid[x][y]==1)return 1;
        
        grid[x][y] = 1;
        int up = DFS(x, y+1, grid);
        int down = DFS(x, y-1, grid);
        int left = DFS(x-1, y, grid);
        int right = DFS(x+1, y, grid);
        return up&&down&&left&&right;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == 0) 
                    res += DFS(i, j, grid);
        return res;
    }
};
