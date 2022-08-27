int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {

    int m = grid.size(), n = grid[0].size();
    if (i == m - 1 and j == n - 1) return grid[i][j];

    if (i<0 or j<0 or i >= m or j >= n) return INT_MAX;

    if (dp[i][j] != -1) return dp[i][j];

    int goRight =  solve(grid, i, j + 1, dp);
    int goDown = solve(grid, i + 1, j, dp);

    if (goRight == INT_MAX and goDown == INT_MAX) return INT_MAX;

    return dp[i][j] = min(goRight, goDown) + grid[i][j];
}


// Time: O(N^2) Space: O(N^2) Memoized 2D Dp
int minPathSum(vector<vector<int>>& grid) {

    int m = grid.size(), n = grid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, -1));

    return solve(grid, 0, 0, dp);

}
