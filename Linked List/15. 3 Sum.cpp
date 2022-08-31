//  Time: O(N^2) Space: O(1) Two Pointer Sortings
vector<vector<int>> threeSum(vector<int>& nums) {

  //a+b+c=0
  int n = nums.size();
  vector<vector<int>> ans;

  sort(nums.begin(), nums.end());

  //  Fix the first ele and find the other two by 2 pointers
  for (int i = 0; i <= n - 3; i++) {

    vector<int> cur(3);
    cur[0] = nums[i];

    int left = i + 1, right = n - 1, sumToFind = -nums[i];

    while (left < right) {

      if (nums[left] + nums[right] == sumToFind) {
        cur[1] = nums[left];
        cur[2] = nums[right];
        ans.push_back(cur);

        while (left < right and nums[left] == nums[left + 1])left++;
        left++;
        while (left < right and nums[right] == nums[right - 1])right--;
        right--;
      }

      else if (nums[left] + nums[right] > sumToFind) {
        while (left < right and nums[right] == nums[right - 1])right--;
        right--;
      }

      else {
        while (left < right and nums[left] == nums[left + 1])left++;
        left++;
      }
    }

    while (i <= n - 3 and nums[i] == nums[i + 1]) i++;

  }

  return ans;
}