/*
  https://leetcode.com/problems/minimum-falling-path-sum-ii/
  我的思路：
  从底向上，每一层都是累计当前最低
  O(mn^2)
  大神的思路:
  fm, sm代表累加第一最小和第二累加最小
  除非最小的位置相同了，才用sm
  O(mn)

*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& a) {
        int res = 1<<30, m = a.size(), n = a[0].size();
        for(int i = m - 2; i >= 0; i--){
            for(int j = 0; j < n; j++){
                int minn = 1<<30;
                for(int k = 0; k < n; k++){
                    if(j==k)continue;
                    minn = min(minn, a[i+1][k]);
                }
                a[i][j] += minn;
            }
        }
        for(int i = 0; i < n; i++)
            res = min(res, a[0][i]);
        return res;
    }
    
    
    int minFallingPathSum(vector<vector<int>>& arr) {
    int fm = 0, sm = 0, pos = -1;
    for (auto i = 0; i < arr.size(); ++i) {
        auto fm2 = INT_MAX, sm2 = INT_MAX, pos2 = -1;
        for (auto j = 0; j < arr[i].size(); ++j) {
            auto mn = j != pos ? fm : sm; //位置相同才用sm
            if (arr[i][j] + mn < fm2) {
                sm2 = fm2;
                fm2 = arr[i][j] + mn;
                pos2 = j;
            } else sm2 = min(sm2, arr[i][j] + mn); //不断更新最小和次小
        }
        fm = fm2, sm = sm2, pos = pos2;
    }
    return fm;
}
};
