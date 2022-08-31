//  Time: O(N*Logn) Space: O(N) Using ordered set and two pointers
int longestConsecutive(vector<int>& nums) {


  set<int> st;
  for (int i = 0; i < nums.size(); i++) st.insert(nums[i]);

  nums.clear();
  for (auto x : st) nums.push_back(x);

  int ans = 1;

  int i = 0, n = nums.size();
  if (n <= 1) return n;

  while (i < n) {
    int j = i + 1;
    while (j < n and nums[j] == nums[j - 1] + 1) {
      j++;
    }
    ans = max(ans, j - i);
    i = j;
  }

  return ans;
}

// --------------------------------------------------------------------------------

//  Time: O(N) Space: O(N) Using map
int longestConsecutive(vector<int>& nums) {

  int n = nums.size();
  if (n <= 1) return n;

  unordered_map<int, int> mp;
  int ans = 1;
  for (int i = 0; i < n; i++) mp[nums[i]]++;

  for (int i = 0; i < n; i++) {
    if (mp.count(nums[i] - 1)) continue; // mere se chota exist krta hai to wo mujhe count kr lega

    // iam the smallest now count the streak
    int cnt = 0, val = nums[i];
    while (mp.count(val)) {
      cnt++;
      val++;
    }

    ans = max(ans, cnt);
  }


  return ans;
}