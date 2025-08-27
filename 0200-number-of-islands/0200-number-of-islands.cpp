class Solution {
public:
    void logic(vector<vector<char>>&grid, int i, int j)
    {
        if( i<0 || j<0 || i>= grid.size() || j>=grid[0].size() ||  '0'==grid[i][j])
        {
            return ;
        }

        grid[i][j] = '0';

        logic(grid, i+1, j);
        logic(grid, i-1, j);
        logic(grid, i, j+1);
        logic(grid, i, j-1);
    }

    void logic_bfs(vector<vector<char>>&grid, int i, int j)
    {
        queue<pair<int,int>> q;
        q.push({i,j});

        grid[i][j] = '0';

        int pre_dir[4][2] = {{1,0},{-1,0}, {0,1}, {0,-1}};

        while(!q.empty())
        {
            auto [x,y] = q.front();
            q.pop();

            for(auto& d:pre_dir)
            {
                int nx = x+d[0];
                int ny = y+d[1];

                if ( nx>=0 && j>=0 && nx< grid.size() &&  ny < grid[0].size() && '1' == grid[nx][ny])
                {
                    grid[nx][ny] = '0';
                    q.push({nx,ny});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if('1' ==  grid[i][j])
                {
                    count ++;
                    logic(grid, i, j);
                }
            }
        }
        return count;
    }
};