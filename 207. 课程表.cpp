//利用DFS判断是否有无环
class Solution {
public:
    int v[110000]; int cycle = 0;
    vector<int> maze[110000];
    int vis[110000];
    void DFS(int s){
        if(vis[s]==1){cycle = 1; return;}
        if(vis[s]==2){return;}
        
        vis[s]=1;
        for(int i = 0; i < maze[s].size(); i++)
            DFS(maze[s][i]);
        vis[s]=2;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
       
        for(int i = 0; i < prerequisites.size(); i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            maze[b].push_back(a);
        }
        
        for(int i = 0; i < n; i++)
            vis[i] = 0;
            
        for(int i = 0; i< n; i++)
            if(!vis[i])
                DFS(i);
        
        if(cycle)return false;
        return true;
    }
};
