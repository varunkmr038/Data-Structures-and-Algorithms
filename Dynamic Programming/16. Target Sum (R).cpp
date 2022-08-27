
// this problem is similar to count partitions with given diff
// 3 2 2 1
//S1 -> 3 2  S2->2  1
// S1 - S2 = target ==> +3 +2 -2 -1 = 2 = target


int solve(vector<int>& num, int target, int i, vector<vector<int>>& dp) {

    int n = num.size();

    if (target < 0) return 0;
    if (i == n) return target == 0;
    if (dp[i][target] != -1) return dp[i][target];

    int includeMe = solve(num, target - num[i], i + 1, dp);
    int excludeMe = solve(num, target, i + 1, dp);

    return dp[i][target] = (includeMe + excludeMe);
}



int countPartitions(int n, int d, vector<int> &arr) {

    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];

    // s1 - s2 = D --> (Total Sum - s2) - s2=d
    // total sum - 2*s2 = d  -->   s2 = (total sum - d)/2  this is the condition
    if ((sum - d) < 0 or (sum - d) % 2 != 0) return 0;

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));

    return  solve(arr, (sum - d) / 2 , 0, dp);
}


//  Time: O(N*sum) Space: O(N*sum) Memoized 2d Dp
int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    return countPartitions(n, target, nums);
}
