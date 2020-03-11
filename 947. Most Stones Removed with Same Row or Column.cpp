class Solution {
public:
    map<int, int> f;
    int island = 0;
    
    int find(int x){
        if(!f.count(x)){
            f[x] = x;
            island++;
        }
        return x == f[x]? x : f[x] = find(f[x]);
    }
    
    int removeStones(vector<vector<int>>& stones) {
        for(auto s:stones){
            int a = find(s[0]);
            int b = find(s[1] + 10000);
            if(a!=b) f[a] = b, island--;
        }
        return stones.size() - island;
    }
};
