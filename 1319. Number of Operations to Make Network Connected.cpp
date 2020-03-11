class Solution {
public:
    int find(int x, vector<int>& p){return x==p[x]?x:p[x] = find(p[x], p);}
    int makeConnected(int n, vector<vector<int>>& con) {
        if(con.size() < n - 1) return -1;
        vector<int> p(n, 0);
        for(int i = 0; i < n; i++)
            p[i] = i;
        for(auto v: con){
            int a = find(v[0], p);
            int b = find(v[1], p);
            if(a!=b) {p[a] = b; n--;} 
        }
        return n-1;
    }
};
