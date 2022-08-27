
bool solve(vector<int>& arr, int i, int target, vector<vector<int>>& dp) {

    int n = arr.size();

    if (target == 0) return true;
    if (i == n) return false;
    if (dp[i][target] != -1) return dp[i][target];

    int includeMe = 0, excludeMe = 0;

    if (target >= arr[i])
        includeMe = solve(arr, i + 1, target - arr[i], dp);

    excludeMe = solve(arr, i + 1, target, dp);

    return dp[i][target] = includeMe or excludeMe;
}

//  Time: O(N*Target) Space: O(N*target) Memoized 2D Dp
bool subsetSumToK(int n, int k, vector<int> &arr) {

    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    return solve(arr, 0, k, dp);

}

// -------------------------------------------------------------------------------


//  Time: O(N*Target) Space: O(N*target) Bottom Up 2D Dp
bool subsetSumToK(int n, int k, vector<int> &arr) {

    vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, 0));

    // base case when taregt is 0
    for (int i = 0; i <= n; i++) dp[i][0] = 1;

    for (int i = n - 1; i >= 0; i--) {

        for (int target = 1; target <= k; target++) {
            int includeMe = 0, excludeMe = 0;

            if (target >= arr[i])
                includeMe = dp[i + 1][target - arr[i]];

            excludeMe = dp[i + 1][target];

            dp[i][target] = includeMe or excludeMe;
        }

    }

    return dp[0][k];
}


// -------------------------------------------------------------------------------


//  Time: O(N*Target) Space: O(target) Space Optimised 1D Dp
bool subsetSumToK(int n, int k, vector<int> &arr) {

    vector<bool> dp(k + 1, 0);
    dp[0] = 1;

    for (int i = n - 1; i >= 0; i--) {

        vector<int> temp(k + 1, 0);
        for (int target = 1; target <= k; target++) {
            int includeMe = 0, excludeMe = 0;

            if (target >= arr[i])
                includeMe = dp[target - arr[i]];

            excludeMe = dp[target];

            temp[target] = includeMe or excludeMe;
        }

        for (int i = 0; i <= k; i++) dp[i] = temp[i];
        dp[0] = 1;
    }

    return dp[k];
}
