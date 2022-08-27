// similar dp on subsequences -- either buy or not on cur day

int solve(vector<int>& prices, int i, bool buy, int totalTransactions, int& k, vector<vector<vector<int>>>& dp) {

    int n = prices.size();
    if (i == n) return 0;
    if (totalTransactions == k) return 0; // i have done max transactions no more now

    if (dp[i][buy][totalTransactions] != -1) return dp[i][buy][totalTransactions];

    int ans = 0;
    // you cannot sell
    if (buy == 1) {
        // buy cur stock
        int buyCurStock = solve(prices, i + 1, 0,  totalTransactions, k, dp) - prices[i]; // if you are buying then adding - prices
        ans = max(ans, buyCurStock);
    }

    // you cannot buy since  you have the stock
    else {
        int sellLastStock = prices[i] + solve(prices, i + 1, 1, totalTransactions + 1 , k, dp); // selling then adding  + prices
        ans = max(ans, sellLastStock);
    }

    // skip and do nothing
    ans = max(ans, solve(prices, i + 1, buy, totalTransactions, k, dp));

    return dp[i][buy][totalTransactions] = ans;
}

//  Time: O(N*k*3) Space: O(3*k*N) Memoized 3d dp
int maxProfit(int k, vector<int>& prices) {

    int n = prices.size();

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (k + 1, vector<int>(3, -1)));
    return solve(prices, 0, 1, 0, k, dp);
}
// ------------------------------------------------------------------------------------------------
