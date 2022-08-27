

int solve(vector<int>& coins, int i, int amount, vector<vector<int>>& dp) {

    int n = coins.size();

    if (i == n) return amount == 0 ? 0 : INT_MAX;
    if (dp[i][amount] != -1) return dp[i][amount];

    int includeMe = INT_MAX;

    if (amount >= coins[i])
        includeMe = solve(coins, i, amount - coins[i], dp);

    if (includeMe != INT_MAX) includeMe++;

    int excludeMe = solve(coins, i + 1, amount, dp);

    return dp[i][amount] = min(includeMe, excludeMe);
}


//  Time: O(N*amount) Space: O(N*amount) Memoized  2d Dp
int coinChange(vector<int>& coins, int amount) {

    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));

    int ans = solve(coins, 0, amount, dp);
    return ans == INT_MAX ? -1 : ans;

}

// ----------------------------------------------------------------------------------


//  Time: O(N*amount) Space: O(N*amount) Bottom Up  2d Dp
int coinChange(vector<int>& coins, int amount) {

    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

    // base case no combo found
    for (int i = 1; i <= amount; i++) dp[n][i] = INT_MAX;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= amount; j++) {

            int includeMe = INT_MAX;

            if (j >= coins[i])
                includeMe = dp[i][j - coins[i]];

            if (includeMe != INT_MAX) includeMe++;

            int excludeMe = dp[i + 1][j];

            dp[i][j] = min(includeMe, excludeMe);
        }
    }

    return dp[0][amount] == INT_MAX ? -1 : dp[0][amount];
}



// ----------------------------------------------------------------------------------


//  Time: O(N*amount) Space: O(amount) SPace Optimised 1d Dp
int coinChange(vector<int>& coins, int amount) {

    int n = coins.size();
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;


    for (int i = n - 1; i >= 0; i--) {

        // iterating from right to left
        for (int j = 0; j <= amount; j++) {

            int includeMe = INT_MAX;

            if (j >= coins[i])
                includeMe = dp[j - coins[i]];

            if (includeMe != INT_MAX) includeMe++;

            int excludeMe = dp[j];

            dpj] = min(includeMe, excludeMe);
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}



