class Solution {
    /*
        The Plan: 
            use DP to keep track of unique paths INTO a node
            fill edges with 1 (only 1 path can make it into the edges)
            Original approach was flawed since I didn't consider the amount of possible ways to 
            reach the end
    */
    private int[][] traversed;
    
    public int uniquePaths(int m, int n) {
        this.traversed = new int[m][n];
        for(int i = 0; i < m; i++) traversed[i][0] = 1;
        for(int i = 0; i < n; i++) traversed[0][i] = 1;
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                traversed[i][j] = traversed[i - 1][j] + traversed[i][j - 1];
            }
        }
        return traversed[m - 1][n - 1]; 
    }
}