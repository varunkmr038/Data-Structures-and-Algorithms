// similar dp on subsequences -- either buy or not on cur day

int solve(vector<int>& prices, int i, bool buy, int totalTransactions, vector<vector<vector<int>>>& dp) {

    int n = prices.size();
    if (i == n) return 0;
    if (totalTransactions == 2) return 0; // i have done max transactions no more now

    if (dp[i][buy][totalTransactions] != -1) return dp[i][buy][totalTransactions];

    int ans = 0;
    // you cannot sell
    if (buy == 1) {
        // buy cur stock
        int buyCurStock = solve(prices, i + 1, 0, totalTransactions, dp) - prices[i]; // if you are buying then adding - prices
        ans = max(ans, buyCurStock);
    }

    // you cannot buy since  you have the stock
    else {
        int sellLastStock = prices[i] + solve(prices, i + 1, 1, totalTransactions + 1 , dp); // selling then adding  + prices
        ans = max(ans, sellLastStock);
    }

    // skip and do nothing
    ans = max(ans, solve(prices, i + 1, buy, totalTransactions, dp));

    return dp[i][buy][totalTransactions] = ans;
}

//  Time: O(N*2*3 = 6*N) Space: O(6*N) Memoized 3d dp
int maxProfit(vector<int>& prices) {

    int n = prices.size();

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int>(3, -1)));
    return solve(prices, 0, 1, 0, dp);
}
// ------------------------------------------------------------------------------------------------

//  Time: O(N*2*3 = 6*N) Space: O(6*N) Bottom Up 3d dp
int maxProfit(vector<int>& prices) {

    int n = prices.size();

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int>(3, 0)));

    for (int i = n - 1; i >= 0; i--) {

        for (int buy = 0; buy < 2; buy++) {
            for (int transaction = 0; transaction < 2; transaction++) {

                int ans = 0;
                // you cannot sell
                if (buy == 1) {
                    // buy cur stock
                    int buyCurStock = dp[i + 1][0][transaction] - prices[i]; // if you are buying then adding - prices
                    ans = max(ans, buyCurStock);
                }

                // you cannot buy since  you have the stock
                else {
                    int sellLastStock = prices[i] + dp[i + 1][1][transaction + 1]; // selling then adding  + prices
                    ans = max(ans, sellLastStock);
                }

                // skip and do nothing
                ans = max(ans, dp[i + 1][buy][transaction]);

                dp[i][buy][transaction] = ans;

            }

        }

    }

    return dp[0][1][0];
}
// ------------------------------------------------------------------------------------------------

//  Time: O(N*2*3 = 6*N) Space: O(2*3) Bottom Up 2d dp
int maxProfit(vector<int>& prices) {

    int n = prices.size();

    vector<vector<int>> prev(2, vector<int>(3, 0));
    vector<vector<int>> cur(2, vector<int>(3, 0));

    for (int i = n - 1; i >= 0; i--) {

        for (int buy = 0; buy < 2; buy++) {
            for (int transaction = 0; transaction < 2; transaction++) {

                int ans = 0;
                // you cannot sell
                if (buy == 1) {
                    // buy cur stock
                    int buyCurStock = prev[0][transaction] - prices[i]; // if you are buying then adding - prices
                    ans = max(ans, buyCurStock);
                }

                // you cannot buy since  you have the stock
                else {
                    int sellLastStock = prices[i] + prev[1][transaction + 1]; // selling then adding  + prices
                    ans = max(ans, sellLastStock);
                }

                // skip and do nothing
                ans = max(ans, prev[buy][transaction]);

                cur[buy][transaction] = ans;

            }

        }
        prev = cur;
    }

    return prev[1][0];
}


// GReedy wont work here
// test case - 1 2 4 2 5 7 2 4 2 9 0