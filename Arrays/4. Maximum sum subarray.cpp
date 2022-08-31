

//Time:O(N)  Space:O(1) Kadane algo
int maxSubArray(vector<int>& nums) {

  int n = nums.size();
  int maxsum = nums[0], cursum = nums[0];

  for (int i = 1; i < n; i++) {

    cursum = max(nums[i] ,  cursum + nums[i]  );
    maxsum = max(cursum, maxsum);

  }

  return maxsum;
}