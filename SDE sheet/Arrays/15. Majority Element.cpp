

// Time: O(N*Logn) Space: O(1)
int majorityElement(vector<int>& nums) {

  sort(nums.begin(), nums.end());
  int n = nums.size();
  if (n == 1) return nums[0];

  return nums[n / 2];
}

// -------------------------------------------------------------------------


// Time: O(N) Space: O(N) Using map
int majorityElement(vector<int>& nums) {

  int n = nums.size();

  if (n == 1) return nums[0];

  unordered_map<int, int> mp;

  for (int i = 0; i < n; i++) {
    mp[nums[i]]++;

    if (mp[nums[i]] > n / 2) return nums[i];

  }

  return -1;
}


// -------------------------------------------------------

// Time: O(N) Space: O(1) Moore Voting algo
int majorityElement(vector<int>& nums) {

  int n = nums.size();

  int cur = nums[0], freq = 0;

  for (int i = 0; i < n; i++) {
    if (freq == 0) {
      cur = nums[i];   //This can be the majority ele
      freq = 1;
    }
    else   if (cur == nums[i])
      freq++;
    else freq--; // on minority
  }
  return  cur;
}