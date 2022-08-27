
//  Time: O(N^2) Space: O(2*N) using lis and count
int findNumberOfLIS(vector<int>& nums) {

  int n = nums.size();

  vector<int> dp(n, 1); //lis dp
  vector<int > count(n, 1); // lis count dp

  int lis = 1;
  int ans = 0;

  for (int i = 1; i < n; i++) {

    for (int j = 0; j < i; j++) {
      if (nums[i] > nums[j]) {

        if (dp[j] + 1 > dp[i]) {
          dp[i] = dp[j] + 1;
          count[i] = count[j];
        }
        // this means there are more subsequences of same length ending at length lis[i]
        else if (dp[j] + 1 == dp[i]) {
          count[i] += count[j];
        }
      }
    }

    if (dp[i] >= lis)
      lis = dp[i];
  }



  for (int i = 0; i < n; i++) {
    if (dp[i] == lis) ans += count[i];
  }

  return ans;
}