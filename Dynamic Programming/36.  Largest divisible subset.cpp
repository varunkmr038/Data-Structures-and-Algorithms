
//  if a/b and b/c then a/c also true
// a/b=k  -- a=bk
// b/c= l -- b=cl  put in above
// a=c(kl) = a/c=kl

//  Time: O(N^2) Space: O(N) LIS 1d dp
vector<int> largestDivisibleSubset(vector<int>& nums) {
    // similar to print lis

    int n = nums.size();
    // order doesnt matter in subset
    sort(nums.begin(), nums.end(), greater<int>());

    vector<int> ans;
    vector<int> dp(n, 0);
    int lenLis = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {

            if (nums[j] % nums[i] == 0) dp[i] = max(dp[i], dp[j] + 1);
        }
        lenLis = max(lenLis, dp[i]);
    }

    // nnow tracing the lis

    for (int i = 0; i < n; i++) {
        if (dp[i] == lenLis) {

            ans.push_back(nums[i]);
            i--;
            lenLis--;

            while (i >= 0) {
                if (dp[i] == lenLis and nums[i] % ans.back() == 0) {
                    ans.push_back(nums[i]);
                    lenLis--;
                }
                i--;
            }
            break;
        }
    }

    return ans;
}