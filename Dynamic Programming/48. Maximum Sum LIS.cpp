

//  Time: O(N^2) Space: O(N) Bottom up 1D DP
int maxSumIS(int arr[], int n) {
   int ans = 0;

   vector<int> dp(n);

   for (int i = 0; i < n; i++) {

      for (int j = 0; j < i; j++) {
         if (arr[i] > arr[j]) {  // I have to consider lis
            dp[i] = max(dp[i], dp[j]);
         }
      }
      dp[i] += arr[i];  // include me also
      ans = max(ans, dp[i]);
   }

   return ans;

}