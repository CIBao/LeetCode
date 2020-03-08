class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int res = 0;
        vector<int> stack={INT_MAX}; //维持一个严格单调递减的队列
        for(auto n: arr){
            while(stack.back() <= n){ //产生了低谷
                int mid = stack.back();
                stack.pop_back();
                res += mid * min(stack.back(), n);
            }
            stack.push_back(n);
        }
        for (int i = 2; i < stack.size(); ++i) {
            res += stack[i-1] * stack[i];
        }
        return res;

        
    }
};
