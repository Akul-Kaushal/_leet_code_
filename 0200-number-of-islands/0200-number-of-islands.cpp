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