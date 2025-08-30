class Solution {
public:
    int logic_bfs(vector<vector<int>>& grid, queue<pair<int,int>>& q, int fresh)
    {
        int death_clock = -1;

        int pre_dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

        while(!q.empty())
        {
            int size = q.size();
            death_clock++;

            while(size--)
            {
                auto [x,y] = q.front();
                q.pop();

                for(auto d:pre_dir)
                {
                    int nx = x + d[0];
                    int ny = y + d[1];
                    if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size() && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2; 
                        fresh--;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return 0==fresh ? max(0,death_clock) : -1;
    }

    int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<int,int>> q;
        int fresh=0;

        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(2==grid[i][j]) { q.push({i,j}); }
                else if(1==grid[i][j]) { fresh++; }
            }
        }

        if(fresh == 0) { return 0; }
        return logic_bfs(grid,q,fresh);        
    }
};