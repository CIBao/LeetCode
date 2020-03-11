class Solution {
public:
    int findRoot(int x, vector<int>& p){ return x==p[x]? x: p[x] = findRoot(p[x] ,p);}
    int findCircleNum(vector<vector<int>>& M) {
        vector<int> p(M.size(), 0);
        for(int i = 0; i < p.size(); i++)
            p[i] = i;
        for(int i = 0; i < M.size(); i++)
        for(int j = 0; j < M[0].size(); j++){
            if(M[i][j]){
                int a = findRoot(i, p);
                int b = findRoot(j, p);
                if(a!=b) p[a] = b;
            }
        }
        int res = 0;
        for(int i = 0; i < p.size(); i++)
            if(i==p[i])res++;
        return res;
    }
};
