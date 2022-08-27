


//  Time: O(N) Space: O(1) Greedy
int maxProfit(vector<int>& prices) {

  int n = prices.size();

  int ans = 0;
  if (n == 0) return 0;
  int minSoFar = prices[0];

  for (int i = 1; i < n; i++) {

    ans = max(ans, prices[i] - minSoFar);
    minSoFar = min(minSoFar, prices[i]); // Now i can be the minimum for rest of days
  }


  return ans;

}