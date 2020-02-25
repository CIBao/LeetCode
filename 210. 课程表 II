//拓扑排序
class Solution {
public:
    int v[110000]; int cycle = 0;
    vector<int> maze[110000];
    int vis[110000];
    vector<int> order;
    
    void DFS(int s){
        if(vis[s]==1){cycle = 1; return;}
        if(vis[s]==2){return;}
        
        vis[s]=1;
        for(int i = 0; i < maze[s].size(); i++)
            DFS(maze[s][i]);
        vis[s]=2;

        order.insert(order.begin(), s);
    }

    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {

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
        
        if(cycle){
            vector<int> res;
            return res;
        }
        return order;
    }
};
