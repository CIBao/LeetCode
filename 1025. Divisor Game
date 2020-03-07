class Solution {
public:
    bool divisorGame(int n) {
        int dp[n+5];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1; dp[1] = 0; dp[2] = 1;
        for(int i = 3; i <= n; i++)
        {
            for(int j = 1; j*j <= i; j++)
                if(i % j == 0) {
                    int s = i / j;
                    if(!dp[i-j] || !dp[i-s]){
                        dp[i] = 1;
                    }
                }
        }
        if(dp[n])return true;
        return false;
    }
};
