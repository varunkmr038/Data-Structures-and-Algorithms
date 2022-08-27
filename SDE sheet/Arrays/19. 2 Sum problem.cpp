//Time: O(N) Space: O(N)
vector<int> twoSum(vector<int>& nums, int target) {

  vector<int> ans(2);
  int n = nums.size();
  unordered_map<int, int> mp;

  for (int i = 0; i < n; i++) {

    if (mp.count(target - nums[i]) != 0) {
      ans[0] = mp[target - nums[i]];
      ans[1] = i;
      break;

    }
    mp[nums[i]] = i;

  }
  return ans;
}

// -----------------------------------------------------------------------------------------


