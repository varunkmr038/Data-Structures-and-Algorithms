// Time: O(N^3) Space: O(N^2)

vector<vector<int>> fourSum(vector<int>& nums, int target) {

  int n = nums.size();

  vector<vector<int>> ans;

  if (n < 4) return ans;

  sort(nums.begin(), nums.end());

  for (int i = 0; i <= n - 4; i++) {

    int sum = nums[i];
    vector<int> cur(4);

    cur[0] = nums[i];

    for (int j = i + 1; j <= n - 3; j++) {

      sum += nums[j];

      cur[1] = nums[j];

      int left = j + 1, right = n - 1;

      while (left < right) {

        int quadsum = sum + nums[left] + nums[right];

        if (quadsum == target) {

          cur[2] = nums[left];
          cur[3] = nums[right];


          ans.push_back(cur);

          left++; right--;

          while (left < right and nums[left] == nums[left - 1])left++;
          while (left < right and nums[right] == nums[right + 1])right--;


        }

        else if (quadsum > target) right--;
        else left++;

      }
      sum -= nums[j];

      while (j < n - 3 and nums[j] == nums[j + 1]) j++;

    }

    while (i < n - 4 and nums[i] == nums[i + 1]) i++;

  }
  return ans;
}