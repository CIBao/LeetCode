/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mark[129]={0};
        int len = 0, maxx=0;
        int l = 0;
        for(int r = 0; r < s.size(); r++)
        {
            int k = s[r];
            if(mark[k]==0)
            {
                mark[k] = 1;
                maxx = max(maxx, r-l+1);
            }
            else 
            {
                while(s[l]!=s[r]) 
                {
                    mark[s[l]] = 0;
                    l++;
                }                
                mark[s[l]] = 0;
                l++;
                mark[k] = 1;
                maxx = max(maxx, r-l+1);
            }
        }
        return maxx;
    }
};
