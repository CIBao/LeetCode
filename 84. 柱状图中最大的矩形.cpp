//维持单调栈，出栈时计算面积

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        stack<int> s;
        int res = 0;
        for(int i = 0; i < heights.size(); i++){
            while(!s.empty() && heights[i] < heights[s.top()]){
               int m = s.top(); 
               s.pop();
                res = max(res, (i - s.top()-1) * heights[m]);
            }
            s.push(i);
        }
        return res;
    }
};
