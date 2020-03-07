class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxx= INT_MIN;
        int s = 0;
        for(auto n : nums){
            if(s < 0) s = 0;
            s += n; 
            maxx = max(maxx, s);
        }
        return maxx;
    }
};
