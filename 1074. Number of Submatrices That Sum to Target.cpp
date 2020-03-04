/*
  https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/
  先计算每一行前缀和
  对每一对列，计算子矩阵的和
  用map存放子矩阵的个数
*/


class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& A, int target) {
        int res = 0;
        int m = A.size(), n = A[0].size();
        for(int i = 0; i < m; i++)
        for(int j = 1; j < n; j++)
            A[i][j] += A[i][j-1];
        
        for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++){ //每一对列
            unordered_map<int,int> counter;   //子矩阵的个数
            counter[0] = 1;
            int cur = 0;
            for(int k = 0; k < m; k++){
                cur += A[k][j] - ( i>0 ? A[k][i-1] : 0); //等价与[0, i, k, j]的和
                res += counter[cur - target];         //现在map里存放了[0, i, 1-k, j]这么多个矩阵
                counter[cur]++;                       //与前缀和的思想一致， 如果map里有和x的矩阵，如果x+target == cur;
                                                     //反过来表示map里面就有[cur-target]
            }
        }
        
        return res;
    }
};
