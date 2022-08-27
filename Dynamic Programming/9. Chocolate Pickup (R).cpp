// explore all paths by Alice  +  Bob simultaneously

int solve(vector<vector<int>>& grid, int i, int j1, int j2, vector<vector<vector<int>>>& dp) {

    int m = grid.size(), n = grid[0].size();

    if (j1<0 or j1 >= n or j2<0 or j2 >= n) return 0;

    if (i == m - 1) return j1 == j2 ? grid[i][j1] : grid[i][j1] + grid[i][j2]; // combined chocolates

    if (dp[i][j1][j2] != -1) return dp[i][j1][j2];

    int dirn[3] = { -1, 0, 1};

    int ans = 0;

    // O(9) 9 combos of paths
    for (int k = 0; k < 3; k++) {
        // try every possible combination of directions
        for (int l = 0; l < 3; l++) {
            ans = max(ans, solve(grid, i + 1, j1 + dirn[k], j2 + dirn[l], dp));
        }
    }

    if (j1 == j2) ans += grid[i][j1]; // common cell
    else ans += grid[i][j1] + grid[i][j2];

    return dp[i][j1][j2] = ans;
}

//  Time: O(9*N^3) Space: O(N^3) Memoized 3D Dp
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {

    // since both are in same row so common i can be used
    // both will move together downwards
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return solve(grid, 0, 0, c - 1, dp);
}
// -------------------------------------------------------------------------------



//  Time: O(9*N^3) Space: O(N^3) Bottom up 3D Dp
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {

    // since both are in same row so common i can be used
    // both will move together downwards
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));

    for (int i = 0; i < c; i++) {
        for (int j = 0; j < c; j++) {
            if (i == j) dp[r - 1][i][j] = grid[r - 1][j];
            else dp[r - 1][i][j] = grid[r - 1][i] + grid[r - 1][j];
        }
    }

    for (int i = r - 2; i >= 0; i--) {

        for (int j1 = c - 1; j1 >= 0; j1--) {

            for (int j2 = c - 1; j2 >= 0; j2--) {

                int dirn[3] = { -1, 0, 1};
                int ans = 0;

                // O(9) 9 combos of paths
                for (int k = 0; k < 3; k++) {
                    // try every possible combination of directions
                    for (int l = 0; l < 3; l++) {

                        int nextj1 = j1 + dirn[k], nextj2 = j2 + dirn[l];
                        if (nextj1 < c and nextj1 >= 0 and nextj2<c and nextj2 >= 0 )
                            ans = max(ans, dp[i + 1][nextj1][nextj2]);
                    }
                }

                if (j1 == j2) ans += grid[i][j1]; // common cell
                else ans += grid[i][j1] + grid[i][j2];

                dp[i][j1][j2] = ans;
            }
        }
    }

    return dp[0][0][c - 1];
}