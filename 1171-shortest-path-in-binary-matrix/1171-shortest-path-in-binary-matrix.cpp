class Solution {
public:
    int logic(vector<vector<int>>&grid, int i, int j)
    {
        if (grid[0][0] != 0 || grid[grid.size()-1][grid[0].size()-1] != 0) return -1;

        queue<pair<int,int>> q;  
        q.push({i,j});

        grid[i][j] = 1;

        int pre_dir[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

        while(!q.empty())
        {
            auto [x,y] = q.front();
            q.pop();

            int dist = grid[x][y];

            if(grid.size()-1 == x && grid[0].size()-1 == y ) { return dist;}

            for(auto &d:pre_dir)
            {
                int nx = x+d[0];
                int ny= y+d[1];
                if (nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size() && grid[nx][ny]==0) {
                    grid[nx][ny] = dist + 1;
                    q.push({nx,ny});
                }

            }
        }
        return -1;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        return logic(grid,0,0);

    }
};