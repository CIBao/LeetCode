class Solution {
public:
    long long res = 0;
    void DFS(vector<int>& nums, int pos, long long S){
        if(pos == nums.size()){
            if(S==0)res++;
            return;
        }
        DFS(nums, pos+1, S+nums[pos]);
        DFS(nums, pos+1, S-nums[pos]);
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        DFS(nums, 0, S);
        return res;
    }
};
