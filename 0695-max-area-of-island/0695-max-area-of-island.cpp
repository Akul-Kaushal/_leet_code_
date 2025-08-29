class Solution {
public:
    int logic(vector<vector<int>>& grid, int i, int j)
    {
        if (i<0||j<0 || i>=grid.size()||j>=grid[0].size()|| 0==grid[i][j]){ return 0;}
        
        grid[i][j] = 0;
        int area=1;

        area += logic(grid,i+1,j);
        area += logic(grid,i-1,j);
        area += logic(grid,i,j+1);
        area += logic(grid,i,j-1);

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int max_area = 0;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                int area = logic(grid,i,j);
                max_area = max(area, max_area);
            }
        }
        
        return max_area;
    }
};