/*
  参考并理解大神的思路
  贪心思路：只要左端与右端一部分相等就分割
*/

class Solution {
public:
    int longestDecomposition(string s) {
        int res = 0;
        int len = s.size();
        string l = "", r = "";
        for(int i = 0; i < len; i++){
            l += s[i]; r = s[len-1-i]+r;
            if(l==r){
                l = r ="";
                res++;
            }
        }
        return res;
    }
};
