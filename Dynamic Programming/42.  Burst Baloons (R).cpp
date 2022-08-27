
//  b1 b2  b3  b4 b5 b6
//         X              --->   b1 b2 b4 b5 b6
// now bursting b2 will depend on b4 so subrpoblem are not independent
// similary bursting b4 will require b2
// so we cannot directly apply mcm here
// kyuki hume nhi pta jb aage jaake hum burst krenge tb humare right me konsa baloon hoga

int solve(vector<int>& nums, int i, int j, vector<vector<int>>& dp) {

    int n = nums.size();

    if (i > j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int ans = 0;

    for (int k = i; k <= j; k++) {

        int coinsCollect = nums[i - 1] * nums[k] * nums[j + 1];

        int subProblem = solve(nums, i, k - 1, dp) + solve(nums, k + 1, j, dp);
        ans = max(ans, subProblem + coinsCollect);
    }
    return dp[i][j] = ans;
}


//  Time: O(N^3)  Space: O(N^2) Memoized 2d Dp
int maxCoins(vector<int>& nums) {

    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    return solve(nums, 1, n, dp);

}

