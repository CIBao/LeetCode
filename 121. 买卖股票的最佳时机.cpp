class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)return 0;
        int minn = prices[0], maxx = 0;
        for(int i = 1; i < prices.size(); i++){
            maxx = max(maxx, prices[i] - minn);
            minn = min(minn, prices[i]);
        }
        return maxx;
    }
};
