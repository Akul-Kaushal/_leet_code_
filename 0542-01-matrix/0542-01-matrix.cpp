class Solution {
public:
    vector<vector<int>> bfs(vector<vector<int>> &grid, queue<pair<int,int>> &q)
    {
        int pre_dir[4][2]= {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty())
        {
            auto [x,y] = q.front();
            q.pop();

            for(auto d: pre_dir)
            {
                int nx = x+d[0];
                int ny = y+d[1];

                if( 0<= nx && 0<=ny && nx<grid.size() && ny<grid[0].size() && grid[nx][ny] > grid[x][y]+1)
                {
                        grid[nx][ny] = grid[x][y] +1;
                        q.push({nx,ny});
                    
                }
            }
        }
        return grid;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        vector<vector<int>> grid (mat.size(), vector<int>(mat[0].size(),INT_MAX));
        queue<pair<int,int>> q;

        for(int i=0; i<mat.size(); i++)
        {
            for(int j=0; j<mat[0].size(); j++)
            {
                if(0== mat[i][j])
                {
                    grid[i][j] = 0;
                    q.push({i,j});
                }
            }        
        }

        return bfs(grid,q);
    }
};