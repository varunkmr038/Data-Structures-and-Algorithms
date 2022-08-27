int solve(vector<int>& heights, int n, vector<int>& dp) {

  if (n == 0) return 0;
  if (dp[n] != -1) return dp[n];

  int oneStep = solve(heights, n - 1, dp) + abs(heights[n - 1] - heights[n]);

  int twoSteps = -1;
  if (n > 1)
    twoSteps = solve(heights,  n - 2, dp) + abs(heights[n - 2] - heights[n]);

  int ans = twoSteps == -1 ? oneStep : min(oneStep, twoSteps);
  return dp[n] = ans;
}

//  TIme: O(N) Space: O(N) Memoized 1D Dp
int frogJump(int n, vector<int> &heights)
{
  vector<int> dp(n, -1);

  // reach n-1 -> 0
  return solve(heights, n - 1, dp);
}

//-------------------------------------------------------------------

//  TIme: O(N) Space: O(N) Bottom 1D Dp
int frogJump(int n, vector<int> &heights)
{
  vector<int> dp(n, 0);
  dp[0] = 0;

  for (int i = 1; i < n; i++) {

    int oneStep = dp[i - 1] + abs(heights[i - 1] - heights[i]);
    int twoSteps = -1;
    if (i > 1)
      twoSteps = dp[i - 2] + abs(heights[i - 2] - heights[i]);

    int ans = twoSteps == -1 ? oneStep : min(oneStep, twoSteps);
    dp[i] = ans;
  }

  return dp[n - 1];
}

//---------------------------------------------------------------

//  TIme: O(N) Space: O(1) Space Optimised  Dp
int frogJump(int n, vector<int> &heights)
{
  vector<int> dp(n, 0);

  int prevStair = 0;
  int prevPrevStair = -1;

  for (int i = 1; i < n; i++) {

    int oneStep = prevStair + abs(heights[i - 1] - heights[i]);
    int twoSteps = -1;

    if (i > 1)
      twoSteps = prevPrevStair + abs(heights[i - 2] - heights[i]);

    int ans = twoSteps == -1 ? oneStep : min(oneStep, twoSteps);
    prevPrevStair = prevStair;
    prevStair   = ans;
  }

  return prevStair;
}
