
int solve(vector<int>& nums, int i, int lastIdx, vector<int>& dp) {

    if (i > lastIdx) return 0;
    if (dp[i] != -1) return dp[i];

    int include = nums[i] +  solve(nums, i + 2, lastIdx, dp);
    int exclude = solve(nums, i + 1, lastIdx, dp);

    return dp[i] = max(include, exclude);
}

//  Time: O(N) Space: O(N) Memoization 1D Dp
int rob(vector<int>& nums) {

    int n = nums.size();
    if (n == 1) return nums[0];

    vector<int> dp(n, -1);

    int includeFirst = solve(nums, 0, n - 2, dp);

    fill(dp.begin(), dp.end(), -1);
    int includeLast = solve(nums, 1, n - 1, dp);

    return max(includeFirst, includeLast);
}
// ------------------------------------------------------------------------

int solve(vector<int>& nums, int start, int end) {

    int next = 0;
    int next2 = 0;

    for (int i = end; i >= start; i--) {

        int include = nums[i] + next2;
        int exclude = next;

        int curAns = max(include, exclude);

        next2 = next;
        next = curAns;

    }
    return next;
}

//  Time: O(N) Space: O(1) Space OPtimised Dp
int rob(vector<int>& nums) {
    int n = nums.size();

    if (n == 1) return nums[0];

    int includeFirst = solve(nums, 0, n - 2);
    int includeLast = solve(nums, 1, n - 1);

    return  max(includeFirst, includeLast);
}