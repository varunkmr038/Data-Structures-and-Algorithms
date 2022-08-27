
int solve(vector<int>& nums, int i, int prevIdx,  vector<vector<int>>& dp) {

    int n = nums.size();

    if (i == n) return 0;
    if (dp[i][prevIdx + 1] != -1) return dp[i][prevIdx + 1];

    int notTake = solve(nums, i + 1, prevIdx, dp);

    int take = 0;
    if (prevIdx == -1 or nums[i] > nums[prevIdx]) take = 1 + solve(nums, i + 1, i, dp);

    return dp[i][prevIdx + 1] = max(take, notTake);
}


//  Time: O(N^2) Space: O(N^2) Memoized 2d dp
int lengthOfLIS(vector<int>& nums) {

    int n = nums.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return solve(nums, 0, -1, dp);
}
// ------------------------------------------------------------------------------------------------


//  Time: O(N*Logn) Space: O(N) Binary Search
int lengthOfLIS(vector<int>& nums) {

    int n = nums.size();

    vector<int> lis;

    for (int i = 0; i < n; i++) {
        if (lis.size() == 0 or  nums[i] > lis.back()) lis.push_back(nums[i]);
        else {
            // choose the pos to replace by binary search
            int idxReplace = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
            lis[idxReplace] = nums[i];
        }
    }

    // we are just generating the len of lis and not the whole lis
    return lis.size();
}
//---------------------------------------------------------------------------------------------------------------------

// Print LIS


//  Time: O(N^2) Space: O(N) Bottom Up 1d dp
void printLIS(vector<int>& nums) {

    int n = nums.size();

    vector<int> dp(n, 0);

    int lenLis = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
        lenLis = max(lenLis, dp[i]);
    }

    vector<int> ans;
    for (int i = n - 1; i >= 0; i--) {

        if (dp[i] == lenLis) {

            ans.push_back(nums[i]);
            int prev = nums[i];
            i--;
            lenLis--;

            while (i >= 0) {
                if (dp[i] == lenLis and nums[i] < prev) {
                    ans.push_back(nums[i]);
                    lenLis--;
                    prev = nums[i];
                }
                i--;
            }
            break;
        }
    }

    for (auto x : nums) cout << x << " ";

}