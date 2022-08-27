
int solve(vector<int>& nums, int i, vector<int>& dp) {
    int n = nums.size();

    if (i >= n) return 0;
    if (dp[i] != -1) return dp[i];

    int include = nums[i] +  solve(nums, i + 2, dp);
    int exclude = solve(nums, i + 1, dp);

    return dp[i] = max(include, exclude);
}

//  Time: O(N) Space: O(N) Memoization 1D Dp
int rob(vector<int>& nums) {

    int n = nums.size();

    vector<int> dp(n, -1);
    return solve(nums, 0, dp);
}

// ------------------------------------------------------------------------

//  Time: O(N) Space: O(N) Bottom Up 1D Dp
int rob(vector<int>& nums) {
    int n = nums.size();

    vector<int> dp(n + 2, 0);

    for (int i = n - 1; i >= 0; i--) {

        int include = nums[i] +  dp[i + 2];
        int exclude = dp[i + 1];

        dp[i] = max(include, exclude);
    }

    return dp[0];
}