
//  Time: O(N^2) Space: O(3*N) Using lis concept
int longestBitonicSequence(vector<int>& nums, int n) {

// calculate lis from start
    vector<int> dp1(n, 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j])
                dp1[i] = max(dp1[i], dp1[j] + 1);
        }
    }
    // calculating lis from end
    vector<int> dp2(n, 1);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (nums[i] > nums[j])
                dp2[i] = max(dp2[i], dp2[j] + 1);
        }
    }

    // now for bitonic
    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans = max(ans, dp1[i] + dp2[i] - 1);
    }

    return ans;
}
