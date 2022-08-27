

void  subsetSum(int n, vector<int> &arr, vector<vector<bool>>& dp, int sum) {


    // base case when taregt is 0
    for (int i = 0; i <= n; i++) dp[i][0] = 1;

    for (int i = n - 1; i >= 0; i--) {

        for (int target = 1; target <= sum; target++) {
            int includeMe = 0, excludeMe = 0;

            if (target >= arr[i])
                includeMe = dp[i + 1][target - arr[i]];

            excludeMe = dp[i + 1][target];

            dp[i][target] = includeMe or excludeMe;
        }

    }
}

//  Time: O(N*Target) Space: O(N*target) Bottom Up 2D Dp Using subset sum
int minSubsetSumDifference(vector<int>& arr, int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)sum += arr[i];

    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, 0));

    subsetSum(n, arr, dp, sum);

    int ans = sum;

    for (int i = 0; i <= sum / 2; i++) {
        // if  cur sum exists
        if (dp[0][i] == true)
            ans = min(ans, abs(2 * i - sum));
    }

    return ans;
}
