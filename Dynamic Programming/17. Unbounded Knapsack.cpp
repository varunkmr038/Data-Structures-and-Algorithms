
int solve(vector<int>& profit, vector<int>& weight, int maxWeight, int i, vector<vector<int>>& dp) {
    int n = profit.size();

    if (i == n) return 0;
    if (dp[i][maxWeight] != -1) return dp[i][maxWeight];

    int includeMe = 0;

    if (maxWeight >= weight[i])
        includeMe = profit[i] + solve(profit, weight, maxWeight - weight[i], i, dp);

    int excludeMe = solve(profit, weight, maxWeight, i + 1, dp);

    return dp[i][maxWeight] = max(includeMe, excludeMe);

}


//  Time: O(N*w) Space: O(N*w) Memoized 2d Dp
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));
    return solve(profit, weight, w, 0, dp);
}

/// ----------------------------------------------------------------------------------------------------------------


//  Time: O(N*w) Space: O(w) Bottom Up 1d Dp
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<int> dp(w + 1, 0);

    for (int i = n - 1; i >= 0; i--) {

        for (int j = 0; j <= w; j++) {
            int includeMe = 0;

            if (j >= weight[i])
                includeMe = profit[i] + dp[j - weight[i]];

            int excludeMe = dp[j];

            dp[j] = max(includeMe, excludeMe);

        }
    }
    return dp[w];
}