class Solution {
public:
    string decodeString(string s) {
        stack<string> chars;
        stack<int> nums;
        string res = "";
        int n = 0;
        for(auto c: s){
            if(isdigit(c))
                n = n*10 + (c-'0');
            else if(isalpha(c))
                res += c;
            else if(c == '['){
                nums.push(n);
                chars.push(res);
                n = 0;
                res = "";
            }
            else if(c == ']'){
                string tmp = res;
                for (int i = 0; i < nums.top()-1; ++i) {
                    res += tmp;
                }
                res = chars.top() + res; chars.pop();
                nums.pop();
            }
        }
        return res;
    }
};
