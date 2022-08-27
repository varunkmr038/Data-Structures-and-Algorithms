// similar dp on subsequences -- either buy or not on cur day

int solve(vector<int>& prices, int i, bool buy, vector<vector<int>>& dp) {

    int n = prices.size();
    if (i == n) return 0;

    if (dp[i][buy] != -1) return dp[i][buy];

    int ans = 0;
    // you cannot sell
    if (buy == 1) {
        // buy cur stock
        int buyCurStock = solve(prices, i + 1, 0, dp) - prices[i]; // if you are buying then adding - prices
        ans = max(ans, buyCurStock);
    }

    // you cannot buy since  you have the stock
    else {
        int sellLastStock = prices[i] + solve(prices, i + 1, 1, dp); // selling then adding  + prices
        ans = max(ans, sellLastStock);
    }

    // skip and do nothing
    ans = max(ans, solve(prices, i + 1, buy, dp));

    return dp[i][buy] = ans;
}

//  Time: O(N) Space: O(N) Memoized 1d dp
int maxProfit(vector<int>& prices) {

    int n = prices.size();

    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    return solve(prices, 0, 1, dp);
}

// ------------------------------------------------------------------------------------------------

// similar dp on subsequences -- either buy or not on cur day

int solve(vector<int>& prices, int i, bool buy, vector<vector<int>>& dp) {

    int n = prices.size();
    if (i == n) return 0;

    if (dp[i][buy] != -1) return dp[i][buy];

    int ans = 0;
    // you cannot sell
    if (buy == 1) {
        // buy cur stock
        int buyCurStock = solve(prices, i + 1, 0, dp) - prices[i]; // if you are buying then adding - prices
        ans = max(ans, buyCurStock);
    }

    // you cannot buy since  you have the stock
    else {
        int sellLastStock = prices[i] + solve(prices, i + 1, 1, dp); // selling then adding  + prices
        ans = max(ans, sellLastStock);
    }

    // skip and do nothing
    ans = max(ans, solve(prices, i + 1, buy, dp));

    return dp[i][buy] = ans;
}

//  Time: O(N) Space: O(1) Space Optimised dp
int maxProfit(vector<int>& prices) {

    int n = prices.size();

    vector<int> prev(2, 0), cur(2, 0);

    for (int i = n - 1; i >= 0; i--) {

        for (int buy = 0; buy < 2; buy++) {

            int ans = 0;
            // you cannot sell
            if (buy == 1) {
                // buy cur stock
                int buyCurStock = prev[0] - prices[i]; // if you are buying then adding - prices
                ans = max(ans, buyCurStock);
            }

            // you cannot buy since  you have the stock
            else {
                int sellLastStock = prices[i] + prev[1]; // selling then adding  + prices
                ans = max(ans, sellLastStock);
            }

            // skip and do nothing
            ans = max(ans, prev[buy]);

            cur[buy] = ans;
        }
        prev = cur;

    }

    return prev[1];
}