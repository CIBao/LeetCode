class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minn = 1<<30;
        int maxx = 0;
        for(auto n: prices)
            minn = min(minn, n),
            maxx = max(maxx, n-minn);
        return maxx;
    }
};
