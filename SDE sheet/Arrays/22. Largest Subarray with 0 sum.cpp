
//  Time: O(N^2)  Space: O(N) Using cumulative sum
int maxLen(vector<int>&a, int n)
{
  vector<int> csum(n, 0);
  csum[0] = a[0];

  for (int i = 1; i < n; i++) csum[i] = csum[i - 1] + a[i];
  int ans = 0;

  // check for every subarray
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {

      int curSum = csum[j] - (i == 0 ? 0 : csum[i]);

      if (curSum == 0) ans = max(ans, j - i + 1);
    }

  }
  return ans;
}


// --------------------------------------------------------------------------------


//  Time: O(N)  Space: O(N) Using prefix sum and map
int maxLen(vector<int>&a, int n)
{
  unordered_map<int, int> mp;
  mp[0] = 0;

  int sum = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];

    // check that sum exists or not
    if (mp.count(sum)) {
      ans = max(ans, i + 1 - mp[sum]);
    }

    else mp[sum] = i + 1;
  }
  return ans;
}