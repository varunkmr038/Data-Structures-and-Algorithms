

//  Time: O(N) Space: O(1) using extra freq vector
void sortColors(vector<int>& nums) {

  vector<int> freq(3, 0);
  int n = nums.size();

  for (int i = 0; i < n; i++)freq[nums[i]]++;

  int idx = 0;
  for (int i = 0; i < 3; i++) {

    while (freq[i]) {
      nums[idx++] = i;
      freq[i]--;
    }
  }

}


// -----------------------------------------------------------------------


//  Time: O(N) Space: O(1) Using low high method
void sortColors(vector<int>& nums) {

  int n = nums.size();

  int low = 0, mid = 0, high = n - 1;

  while (mid <= high) {

    if (nums[mid] == 0) {
      swap(nums[low], nums[mid]);
      low++;
      mid++;
    }

    else if (nums[mid] == 1) mid++;
    else {
      swap(nums[mid], nums[high]);
      high--;
    }


  }

}