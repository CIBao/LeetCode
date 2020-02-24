class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& maze) {
        if(maze[0][0]==1)return 0;
        int m = maze.size();
        int n = maze[0].size();
        long long dp[m+15][n+15];
        for(int i =0; i<=m; i++)
        for(int j =0; j<=n; j++){
            dp[i][j]=0;
        }
        dp[1][1] = 1;
        for(int i =1; i<=m; i++)
        for(int j =1; j<=n; j++){
            if(i==1&&j==1)continue;
            if(maze[i-1][j-1] == 1)dp[i][j]=0;
            else dp[i][j] = dp[i-1][j] + dp[i][j-1]; 
        }
        return (int)dp[m][n];
    }
};
