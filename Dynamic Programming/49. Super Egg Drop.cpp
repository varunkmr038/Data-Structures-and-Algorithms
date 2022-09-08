

int solve(int e, int f, vector<vector<int>>& dp) {
   if (e == 1 or f == 0 or f == 1) return f;
   if (dp[e][f] != -1) return dp[e][f];

   int ans = 1000000;
   //  I will choose floor from 1 to k with binary Search which will give me minimum attempts  because sub1 is inc func and sub2 is dec func
   // Im shrinking my range to get low value of all max
   int low = 1, high = f;
   while (low <= high) {
      int mid = (low + high) / 2;

      // If egg breaks then I have to go below floor to find critical floor for mid
      int down = solve(e - 1, mid - 1, dp);
      int up = solve(e, f - mid, dp); // If egg does not break go Upwards for mid

      int temp = 1 + max(down, up);
      if (down > up)  //since down is more than up and we need more in worst case
         high = mid - 1; // so go towards down

      else
         low = mid + 1;


      ans = min(ans, temp); // Minimum of all the worst
   }

   return dp[e][f] = ans;
}
// Time: O(E*F*LogF) space: O(E*F) MCM variation 2D Dp with Binary Search
int superEggDrop(int e, int f) {

   vector<vector<int>> dp(e + 1, vector<int>(f + 1, -1));
   return solve(e, f, dp);


}