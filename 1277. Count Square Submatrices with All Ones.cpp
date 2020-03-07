class Solution {
public:
    int countSquares(vector<vector<int>>& m) {
        int M = m.size(); int N = m[0].size();
        vector<vector<int>> dp(M+5, vector<int>(N+5,0));
        int s = 0;
        for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            if(m[i][j]){
                dp[i+1][j+1] = min(dp[i+1][j], min(dp[i][j+1], dp[i][j])) + 1;
                s += dp[i+1][j+1];
            }
        return s;
            
    }
};
