
int solve(vector<int>& price, int cutLen, int rodLen, vector<vector<int>>& dp) {
    int n = price.size();

    if (cutLen == n + 1) return 0; //  or if(cutLen > rodLen) return 0;
    if (dp[cutLen][rodLen] != -1) return dp[cutLen][rodLen];

    int includeThisCut = 0;

    if (rodLen >= cutLen)
        includeThisCut = price[cutLen - 1] + solve(price, cutLen, rodLen - cutLen, dp);

    int excludeThisCut = solve(price, cutLen + 1, rodLen, dp);

    return dp[cutLen][rodLen] = max(includeThisCut, excludeThisCut);

}

// problem is similar to unbounded knapsack
// weight[n]= {1,2,3,4,5}
// profit[n] = price[n]
// capacity = N
//  Time: O(N*N) Space: O(N*N) Memoized 2d Dp
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    return solve(price, 1, n, dp);
}

