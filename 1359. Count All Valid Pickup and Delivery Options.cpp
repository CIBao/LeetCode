/*
  https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/submissions/
  看了大神的解析才懂
  n-1对已排好，插入第n对
  第一个元素有 2n-1 个位置插入
  第二个元素有 2n   个位置插入
  因为顺序固定，所以要 /2
  所以插入第n对有 n*(2n-1)种方法
*/

class Solution {
public:
    int countOrders(int n) {
        const int mod = 1000000007;
        long long res = 1;
        for(int i = 2; i<= n;i++ )
            res = res *(2*i-1)*i % mod;
        return res;
    }
};
