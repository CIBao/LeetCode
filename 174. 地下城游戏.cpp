//二分加动态规划
//思路不难，细节又是细节

class Solution {
public:
    bool judge(vector<vector<int>>& dungeon, int num)
    {
        int m = dungeon.size();
        int n = dungeon[0].size();
        int a[m+10][n+10]={0};
        int dp[m+10][n+10]={0};
        
        
        for(int i = 0; i < m+2; i++)
        for(int j = 0; j < n+2; j++)
            dp[i][j] = -99999;
        dp[1][1] = num+dungeon[0][0];
        if(dp[1][1]<=0)return false;
        for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++){
            if(i==1&&j==1)continue;
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) +dungeon[i-1][j-1];
            if(dp[i][j]<=0)dp[i][j]=-99999;
        }
        return dp[m][n]>0;
        
    }


    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int l = 1; int r = 1e9;
        while(l < r){
            int m = (l+r)/2;
            if(judge(dungeon, m)) r = m;
            else l = m+1;
        } 
        return l;
        
    }
};
