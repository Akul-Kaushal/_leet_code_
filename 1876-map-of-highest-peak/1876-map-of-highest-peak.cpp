class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        
        vector<vector<int>> grid(isWater.size(), vector<int> (isWater[0].size(),INT_MAX));
        queue<pair<int,int>> q;
        
        for( int i=0; i<isWater.size(); i++)
        {
            for( int j=0; j<isWater[0].size(); j++)
            {
                if(1==isWater[i][j]) { 
                    grid[i][j] = 0;
                    q.push({i,j});
                    }
            }
        }

        int pre_dir[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};

        while(!q.empty())
        {
            auto [x,y] = q.front();
            q.pop();

            for( auto d:pre_dir)
            {
                int nx = x+d[0];
                int ny = y+d[1];

                if(0<=nx && 0<=ny && grid.size()>nx && grid[0].size()>ny && grid[nx][ny] > grid[x][y]+1)
                {
                    grid[nx][ny] = grid[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }

        return grid;
    }
};