// dp on rectangles

//  Time: O(N^2) Space: O(N^2) Bottom up 2d dp
int countSquares(vector<vector<int >>& matrix) {

   int m = matrix.size(), n = matrix[0].size();
   int ans = 0;

   vector<vector<int>> dp(m, vector<int>(n, 0));

   // fill the first row and col as it is
   for (int i = 0; i < n; i++) {
      dp[0][i] = matrix[0][i];
      ans += dp[0][i];
   }

   for (int i = 1; i < m; i++) {
      dp[i][0] = matrix[i][0];
      ans += dp[i][0];
   }

   for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
         if (matrix[i][j] == 0) continue; // 02 -1 -1 0


         dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
         ans += dp[i][j];
      }
   }


   return ans;
}