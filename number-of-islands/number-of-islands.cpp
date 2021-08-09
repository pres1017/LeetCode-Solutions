class Solution {
public:
    void islands(vector<vector<char>>& origGrid, int x, int y){
        if(x < 0 || x >= origGrid.size() || y < 0 || y >= origGrid[x].size() || origGrid[x][y] == '0') return;
        origGrid[x][y] = '0';
        islands(origGrid, x - 1, y);
        islands(origGrid, x + 1, y);
        islands(origGrid, x, y + 1);
        islands(origGrid, x, y - 1);
    }
    
    int numIslands(vector<vector<char>>& grid){
        int numberOfIslands = 0;
        for(int x = 0; x < grid.size(); x++){
            for(int y = 0; y < grid[x].size(); y++){
                if(grid[x][y] == '1'){
                    numberOfIslands++;
                    islands(grid, x, y);
                }
            }
        }
        return numberOfIslands;
    }
};