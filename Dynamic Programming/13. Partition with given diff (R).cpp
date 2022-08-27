
int mod = 1e9 + 7;

int solve(vector<int>& num, int target, int i, vector<vector<int>>& dp) {

    int n = num.size();

    if (target < 0) return 0;
    if (i == n) return target == 0;
    if (dp[i][target] != -1) return dp[i][target];

    int includeMe = solve(num, target - num[i], i + 1, dp);
    int excludeMe = solve(num, target, i + 1, dp);

    return dp[i][target] = (includeMe + excludeMe) % mod;
}



//  Time: O(N*sum) Space: O(N*sum) Bottom Up 2d Dp
int countPartitions(int n, int d, vector<int> &arr) {

    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];

    // s1 - s2 = D --> (Total Sum - s2) - s2=d
    // total sum - 2*s2 = d  -->   s2 = (total sum - d)/2  this is the condition
    if ((sum - d) < 0 or (sum - d) % 2 != 0) return 0;

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));

    return  solve(arr, (sum - d) / 2 , 0, dp);
}

// --------------------------------------------------------------------------------------


int mod = 1e9 + 7;

int solve(vector<int>& num, int target) {

    int n = num.size();

    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    dp[n][0] = 1;

    for (int i = n - 1; i >= 0; i--) {

        for (int j = 0; j <= target; j++) {

            int includeMe = 0;

            if (j >= num[i])
                includeMe = dp[i + 1][j - num[i]];

            int excludeMe = dp[i + 1][j];

            dp[i][j] = (includeMe + excludeMe) % mod;
        }

    }
    return dp[0][target];
}



//  Time: O(N*sum) Space: O(N*sum) Bottom Up 2d Dp
int countPartitions(int n, int d, vector<int> &arr) {

    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];

    // s1 - s2 = D --> (Total Sum - s2) - s2=d
    // total sum - 2*s2 = d  -->   s2 = (total sum - d)/2  this is the condition
    if ((sum - d) < 0 or (sum - d) % 2 != 0) return 0;

    return  solve(arr, (sum - d) / 2);
}