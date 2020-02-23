class Solution {
public:
    int minDistance(string s1, string s2) {
        if(s1.empty() && s2.empty())return 0;
        if(s1.empty())return s2.size();
        if(s2.empty())return s1.size();
        int len1 = s1.size();
        int len2 = s2.size();
        int dp[len1+5][len2+5]={0};
        for(int i=0;i<=len1;i++)
            dp[i][0] = i;
        for(int i=0;i<=len2;i++)
            dp[0][i] = i;
        for(int i = 1; i<=len1;i++)
        for(int j = 1; j<=len2;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]= min(dp[i-1][j], dp[i][j-1]); //删除
                dp[i][j]= min(dp[i][j]+1, dp[i-1][j-1]); //不变
            } else{
                dp[i][j]= min(dp[i-1][j], dp[i][j-1]); //删除
                dp[i][j]=min(dp[i][j], dp[i-1][j-1])+1; //更换
            }
        }
        return dp[len1][len2];
    }
};
