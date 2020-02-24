class Solution {
public:
    
    int expand(string s, int i, int j)
    {
        while(i>=0&&j<s.length()&&s[i]==s[j]){
            i--;
            j++;
        }
        return j-i-1;
    }
     
    string longestPalindrome(string s) {
        if(s == ""|| s.length() < 0)return "";
        int start = 0, end = 0;
        for(int i = 0; i < s.length(); i++){
            int len1 = expand(s, i, i);
            int len2 = expand(s, i, i+1);
            int len = max(len1, len2);
            if(len > end - start){
                start = i - (len-1)/2;
                end = i + len/2;
            }
            
        }
        return s.substr(start, end-start+1);
    }
};
