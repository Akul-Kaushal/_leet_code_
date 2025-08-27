class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int color, int cur_color)
    {
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size() || cur_color != image[i][j])
        {
            return ;
        }
        image[i][j] = color;

        dfs(image,i+1,j,color,cur_color);
        dfs(image,i-1,j,color,cur_color);
        dfs(image,i,j+1,color,cur_color);
        dfs(image,i,j-1,color,cur_color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int cur_color = image[sr][sc];
        if (cur_color != color)
        {
            dfs(image,sr,sc,color, cur_color);
        }
        
        return image;
    }
};