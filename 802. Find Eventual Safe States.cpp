class Solution {
public:
    
    bool dfs(vector<vector<int>>& G,vector<int>& dp, int x){
        if(dp[x])  //已经染色
            return dp[x] == 1;
        
        dp[x] = -1; //默认有环，灰色
        for(auto m:G[x]){ 
            if(false == dfs(G, dp, m))
                return false;
        }
        return dp[x] = 1; //无环，黑色
    }
    
    
    vector<int> eventualSafeNodes(vector<vector<int>>& G) {
        vector<int> res;
        vector<int> dp(G.size(), 0);
        for(int i = 0; i < G.size(); i++)
            if(dfs(G, dp, i))
                res.push_back(i);
        return res;
    }
};
