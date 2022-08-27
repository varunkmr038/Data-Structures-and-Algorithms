

//  Time: O(N) Space: O(1)
int removeDuplicates(vector<int>& nums) {

  if (n == 1) return 1;

  int idx = 1, i = 1;
  while (i < nums.size()) {

    while (i < nums.size() and nums[i] == nums[i - 1]) i++;
    nums[idx++] = nums[i];
    i++;
  }

  return idx;
}