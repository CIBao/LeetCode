//基础BFS
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {                
        int r = matrix.size(), c = matrix[0].size();
        vector<vector<int>> dist(r, vector<int>(c, INT_MAX));
        queue<pair<int, int>> que;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;
                    que.push({i, j});
                }                
            }
        }        
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!que.empty()) {
            pair<int, int> cur = que.front(); 
            que.pop();
            for (auto d : dir) {
                int x = cur.first + d[0];
                int y = cur.second + d[1];
                if (x >= 0 && x < r && y >= 0 && y < c) {
                    if (dist[x][y] > dist[cur.first][cur.second] + 1) {
                        dist[x][y] = dist[cur.first][cur.second] + 1;
                        que.push({x, y});
                    }
                }
            }
        }
        return dist;
    }
};
