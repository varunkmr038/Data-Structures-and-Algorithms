

//Time:O(N)  Space:O(N) using map
int findDuplicate(vector<int>& nums) {

  int n = nums.size();
  vector<bool> vis(n + 1, 0);

  for (int i = 0; i < n; i++) {

    if (vis[nums[i]] == 0) vis[nums[i]] = 1;

    else return nums[i];

  }


  return 0;
}

// --------------------------------------------------------------------------

//Time:O(N)  Space:O(1) with modifying the array
int findDuplicate(vector<int>& nums) {

  int n = nums.size();

  for (int i = 0; i < n; i++) {

    if (nums[abs(nums[i]) - 1] > 0)
      nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];

    else return abs(nums[i]);

  }

  return 0;
}