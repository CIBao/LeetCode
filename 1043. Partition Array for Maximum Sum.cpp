class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        vector<int> dp(A.size()+1, 0);
        dp[0] = 0;
        for(int i = 1; i <= A.size(); i++){
            int curMax = 0;
            for(int k = 1; k <= min(i, K); k++){
                curMax = max(curMax, A[i-k]);
                dp[i] = max(dp[i], dp[i-k]+ curMax*k);
            }
        }
        return dp[A.size()];
    }
};
