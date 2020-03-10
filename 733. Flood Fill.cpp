class Solution {
public:
    int oldcolor = -1;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(oldcolor==-1) oldcolor = image[sr][sc];
        if(image[sr][sc] == newColor) return image;
        image[sr][sc] = newColor;
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        for(int i = 0; i < 4; i++){
            int nx = sr + dx[i];
            int ny = sc + dy[i];
            if(nx>=0&&nx<image.size()&&ny>=0&&ny<image[0].size())
                if(image[nx][ny]==oldcolor)
                    floodFill(image, nx, ny, newColor);
        }
        return image;
    }
};
