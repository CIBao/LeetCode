class Solution {
public:
    vector<int> p;
    int n, count;
    int find(int x){ return x==p[x]?x:p[x]=find(p[x]);}
    
    void merge(int a, int b){
        int x = find(a);
        int y = find(b);
        if(x!=y){
            p[x] = y;
            count--;
        }
    }
    
    int g(int i, int j, int k){
        return (i*n + j) * 4 + k;
    }
    
    int regionsBySlashes(vector<string>& grid) {
        n = grid.size();
        count = 4*n*n;
        for(int i = 0; i < 4*n*n; i++)
           p.push_back(i);
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            if(i>0) merge(g(i-1, j, 2), g(i, j, 0));
            if(j>0) merge(g(i, j-1, 1), g(i, j, 3));
            if(grid[i][j] != '/') {
                merge(g(i, j, 1), g(i, j, 0));
                merge(g(i, j, 2), g(i, j, 3));
            }
            if(grid[i][j] != '\\') {
                merge(g(i, j, 3), g(i, j, 0));
                merge(g(i, j, 1), g(i, j, 2));
            }
        }
        return count;
    }
};
