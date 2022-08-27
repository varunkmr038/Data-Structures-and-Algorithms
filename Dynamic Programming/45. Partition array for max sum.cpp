
int solve(vector<int>& arr, int i, int k, vector<int>& dp) {

   int n = arr.size();
   if (i == n) return 0;
   if (dp[i] != -1) return dp[i];

   int end = min(n, i + k);
   int ans = 0, maxTillNow = 0;

   for (int j = i; j < end; j++) {
      maxTillNow = max(maxTillNow, arr[j]);

      // partition here
      int lenTillNow = j - i + 1;
      ans = max(ans, maxTillNow * lenTillNow + solve(arr, j + 1, k, dp));
   }

   return dp[i] = ans;
}


//  Time: O(N^2) Space: O(N) Memoized 1d dp
int maxSumAfterPartitioning(vector<int>& arr, int k) {

   int n = arr.size();

   vector<int> dp(n + 1, -1);
   return solve(arr, 0, k, dp);
}
