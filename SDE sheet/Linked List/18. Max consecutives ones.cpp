
//  Time: O(N) Space: O(1) Two pointers
int findMaxConsecutiveOnes(vector<int>& nums) {
  int n = nums.size();

  int cnt = 0;

  int ans = 0;
  for (int i = 0; i < n; i++) {

    if (nums[i] == 0) cnt = 0;
    else cnt++;
    ans = max(ans, cnt);
  }

  return ans;
}