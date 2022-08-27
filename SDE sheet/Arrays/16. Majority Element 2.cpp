
// Time: O(N) Space: O(N) using Map
vector<int> majorityElement(vector<int>& nums) {

  int n = nums.size();

  vector<int> ans;

  unordered_map<int, int> mp;

  for (int i = 0; i < n; i++) {
    mp[nums[i]]++;
  }

  for (auto x : mp) {
    if (x.second > n / 3)
      ans.push_back(x.first);

  }
  return ans;

}

// -------------------------------------------------------------------------------

// Time: O(N) Space: O(1) Moore voting algo
vector<int> majorityElement(vector<int>& nums) {

  vector<int> ans;
  int n = nums.size();

  if (n == 1) return nums;

  int me1 = INT_MAX, me2 = INT_MAX;
  int c1 = 0, c2 = 0;

  for (int i = 0; i < n; i++) {

    if (me1 == nums[i]) c1++;
    else if (me2 == nums[i])c2++;
    else if (c1 == 0) {
      me1 = nums[i];
      c1++;
    }
    else if (c2 == 0) {
      me2 = nums[i];
      c2++;
    }

    else {
      c1--;
      c2--;
    }

  }
  c1 = 0; c2 = 0;

  for (int i = 0; i < n; i++) {
    if (nums[i] == me1) c1++;
    if (nums[i] == me2) c2++;
  }

  if (c1 > n / 3)ans.push_back(me1);
  if (c2 > n / 3)ans.push_back(me2);

  return ans;

}