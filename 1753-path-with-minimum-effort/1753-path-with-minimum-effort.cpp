class Solution {
public:

    int bfs(vector<vector<int>>& heights,
    vector<vector<int>>& grid,
    priority_queue<vector<int>, vector<vector<int>> , greater<>>& q)
    {
        int pre_dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty())
        {
            auto popped = q.top();
            q.pop();

            int x = popped[0];
            int y = popped[1];
            int z = popped[2];

            if( grid.size()-1 == y && grid[0].size()-1 == z) { return x;}

            for(auto d:pre_dir)
            {
                int ny = y+d[0];
                int nz = z+d[1];
                
                if(0<=ny && 0<=nz && grid.size()>ny && grid[0].size()>nz )
                {
                    int abs_diff = max(x, abs(heights[y][z]-heights[ny][nz]));
                    if(abs_diff < grid[ny][nz])
                    {
                        grid[ny][nz] = abs_diff;
                        q.push({abs_diff,ny,nz});
                    }
                }
            }
        }
        return 0;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {

        vector<vector<int>> grid(heights.size(), vector<int>(heights[0].size(), INT_MAX));
        grid[0][0] = 0;

        priority_queue<vector<int> ,vector<vector<int>> , greater<>> q;
        q.push({0,0,0});

        return bfs(heights,grid,q);
    }
};