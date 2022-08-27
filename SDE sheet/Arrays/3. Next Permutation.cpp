

//  Time: O(N) Space: O(1) Simple reverse method
void nextPermutation(vector<int>& nums) {

  int n = nums.size();

  int idx = -1;

  for (int i = n - 1; i > 0; i--) { // check from last
    if (nums[i - 1] < nums[i]) {
      idx = i - 1; // Index where value will increment
      break;
    }
  }
//       idx
// 1 2 3  4   5 3 2 1

  if (idx == -1) {
    reverse(nums.begin(), nums.end()); //Array is sorted in desc just reverse the array
    return ;
  }

  reverse(nums.begin() + idx + 1, nums.end());

  for (int i = idx + 1; i < n; i++) {
    if (nums[i] > nums[idx]) {
      swap(nums[i], nums[idx]);
      break;
    }
  }

}