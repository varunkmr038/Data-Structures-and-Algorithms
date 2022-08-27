
//  Time: O(N^2)  Space: O(1) Brute force
int Solution::solve(vector<int> &a, int targetXor) {

  int n = a.size();
  int ans = 0;

  for (int i = 0; i < n; i++) {
    int xo = 0;

    for (int j = i; j < n; j++) {
      xo ^= a[j];

      if (xo == targetXor) ans++;
    }
  }
  return ans;
}

// --------------------------------------------------------------------


//  Time: O(N)  Space: O(N) Using prefix xor
int Solution::solve(vector<int> &a, int targetXor) {

  // if a ^ b = c  this  implies ==>    c ^ a = (a ^ b) ^ a = b
  // making use of this property

  int n = a.size();
  int ans = 0;
  unordered_map<int, int> xorMap;

  int prefixXor = 0;
  xorMap[0]++;

  for (int i = 0; i < n; i++) {
    prefixXor ^ = a[i];

    ans + = (xorMap[prefixXor ^ targetXor]);
    xorMap[prefixXor]++;
  }
  return ans;
}
