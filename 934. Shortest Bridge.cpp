class Solution {
public:
    int vis[110][110];
    
    
    void DFS(vector<vector<int>>& A, int x, int y, int cnt){
        if(x<0||x>=A.size()||y<0||y>=A[0].size())return;
        if(A[x][y]==0 || A[x][y] == cnt) return;
        A[x][y] = cnt;
        DFS(A, x+1, y, cnt);
        DFS(A, x-1, y, cnt);
        DFS(A, x, y+1, cnt);
        DFS(A, x, y-1, cnt);
    }
    
    int shortestBridge(vector<vector<int>>& A) {
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        int cnt = 2;
        queue<pair<int, int>> Q;
        for(int i = 0; i < A.size(); i++)
        for(int j = 0; j < A[0].size(); j++)
            if(A[i][j]==1)
                DFS(A, i, j, cnt++); 
        
        
        for(int i = 0; i < A.size(); i++)
        for(int j = 0; j < A[0].size(); j++)
            if(A[i][j]==2)
                Q.push({i, j});
            
        int res = 0;
        memset(vis, 0, sizeof(vis));
        while(!Q.empty()){
            int m = Q.size();
            res++;
            for(int i = 0; i < m; i++){
                auto x = Q.front(); Q.pop();
                int a = x.first; int b = x.second;
                if(vis[a][b])continue;
                vis[a][b] = 1;
                for(int i = 0; i < 4; i++){
                    int nx = a+dx[i];
                    int ny = b+dy[i];
                    if(nx>=0&&ny>=0&&nx<A.size()&&ny<A[0].size()){
                        if(A[nx][ny]==3)return res-1;
                        if(A[nx][ny]==0)
                            Q.push({nx, ny});
                    }
                }
            }
        }
        return res;
    }
};
