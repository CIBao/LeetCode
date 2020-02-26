//卡特兰数
class Solution {
public:
    int numTrees(int n) {
        if(n<2) return 1;
        int dp[n+5];
        dp[0] = dp[1]=1;
        for(int i = 2; i <= n; i++){
            dp[i] = 0;
            for(int j = 0; j < i; j++)
                dp[i] += dp[j] * dp[i-j-1];
        }
        return dp[n];
    }
};
