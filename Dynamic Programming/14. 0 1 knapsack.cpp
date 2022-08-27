
//  Time: O(N*maxWeight) Space: O(N*maxWeight) Bottom Up 2d Dp
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{

    vector<vector<int>> dp(n + 1, vector<int>(maxWeight + 1, 0));

    for (int i = n - 1; i >= 0; i--) {

        for (int w = 0; w <= maxWeight; w++) {
            int includeMe = 0, excludeMe = 0;

            if (w >= weight[i])
                includeMe = value[i] +  dp[i + 1][w - weight[i]];

            excludeMe = dp[i + 1][w];

            dp[i][w] = max(includeMe, excludeMe);
        }

    }
    return dp[0][maxWeight];
}
// --------------------------------------------------------------------------



//  Time: O(N*maxWeight) Space: O(MaxWeight) Space Optimised 1d Dp
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{

    vector<int> dp(maxWeight + 1, 0);


    for (int i = n - 1; i >= 0; i--) {

// if we start from left then our old values will be overwritten which will be required for next states
// So In this we start from right bcoz we are computing values based upon left
        for (int w = maxWeight; w >= 0 ; w--) {
            int includeMe = 0, excludeMe = 0;

            if (w >= weight[i])
                includeMe = value[i] +  dp[w - weight[i]];

            excludeMe = dp[w];

            dp[w] = max(includeMe, excludeMe); // values overwritten are of no use for left next states
        }

    }
    return dp[maxWeight];
}