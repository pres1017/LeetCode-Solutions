class Solution {
        /*
        Brute Force:
            Recurively iterate through literally every possible path (monstrously slow)
            Ideas to optimize:
                - each node saves path length data from both the top and the side until the lower right node is reached
                -* greedy algorithm: only choose to traverse the least intensive path at any given time
    */
    public int minPathSum(int[][] grid) {
        int height = grid.length;
        int width = grid[0].length;
        int[][] effort = new int[height][width];
        effort[0][0] = grid[0][0];
        for(int i = 1; i < width; i++){
            effort[0][i] = grid[0][i] + effort[0][i - 1];
        }
        for(int j = 1; j < height; j++){
            effort[j][0] = grid[j][0] + effort[j - 1][0];
        }
        for(int j = 1; j < height; j++){
            for(int i = 1; i < width; i++){
                effort[j][i] = Math.min(effort[j - 1][i], effort[j][i - 1]) + grid[j][i];
            }
        }
        
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                System.out.print(effort[i][j]);
            }
            System.out.println();
        }
        return effort[height - 1][width - 1];
    }
}