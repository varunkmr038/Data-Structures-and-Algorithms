
int solve(vector<int>& num, int target, int i, vector<vector<int>>& dp) {

    int n = num.size();

    if (target < 0) return 0;
    if (i == n) return target == 0;

    if (dp[i][target] != -1) return dp[i][target];

    int includeMe = solve(num, target - num[i], i + 1, dp);
    int excludeMe = solve(num, target, i + 1, dp);

    return dp[i][target] = includeMe + excludeMe;
}


//  Time: O(N*Target) Space: O(N*target) Memoized 2d Dp
int findWays(vector<int> &num, int target)
{
    int n = num.size();
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

    return solve(num, target, 0, dp);
}