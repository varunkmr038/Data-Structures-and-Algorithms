//  Time: O(N^2) Space: O(N) Brute Force Loop
int lengthOfLongestSubstring(string s) {

  int n = s.size();
  int ans = 0;

  for (int i = 0; i < n ; i++) {

    unordered_map<char, int> mp;

    mp[s[i]]++;
    int len = 1;

    for (int j = i + 1; j < n; j++) {
      if (mp.count(s[j])) break;

      len++;
      mp[s[j]]++;
    }

    ans = max(ans, len);
  }

  return ans;

}
// ----------------------------------------------------------------------------

//  Time: O(N) Space: O(N) Sliding window with hashing
int lengthOfLongestSubstring(string s) {

  int n = s.size();
  int ans = 1;

  if (n == 0) return 0;

  unordered_map<char, int> mp;

  int i = 0;
  for (int j = 0; j < n ; j++) {

    //  Im gonna shrink window from left to discard the repeating element
    while (i < j and mp[s[j]] != 0) {
      mp[s[i]]--;
      i++;
    }

    mp[s[j]]++;

    int curLen = j - i + 1;
    ans = max(ans, curLen);
  }

  return ans;

}