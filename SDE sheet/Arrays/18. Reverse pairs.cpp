

//  Time: O(N^2) Space: O(1) BRute force
int reversePairs(vector<int>& nums) {

  int n = nums.size();
  int ans = 0;

  for (int i = 0; i < n; i++) {

    for (int j = i + 1; j < n; j++) {
      long long int val = 2LL * nums[j];
      if (nums[i] > val) ans++;
    }
  }

  return ans;

}

// ---------------------------------------------------------------------------------

void mergeArray(vector<int>& nums, int s, int e, int& ans) {

  int mid = s + (e - s) / 2;
  int k = 0;
  vector<int> c(e - s + 1);

  int i = s, j = mid + 1;

  while (i <= mid and j <= e) {
    if (nums[i] < nums[j]) c[k++] = nums[i++];
    else c[k++] = nums[j++];
  }

  while (i <= mid) c[k++] = nums[i++];
  while (j <= e) c[k++] = nums[j++];

  k = s;
  for (auto &x : c) {
    nums[k++] = x;
  }

}

void mergeSort(vector<int>& nums, int s, int e, int& ans) {

  if (s >= e) return;

  int mid = s + (e - s) / 2;

  mergeSort(nums, s, mid, ans);
  mergeSort(nums, mid + 1, e, ans);


  int i = s, j = mid + 1;
  int numsLessThan = 0;

  while (i <= mid and j <= e) {
    long long int val = 2LL * nums[j];

    if (nums[i] > val) {
      j++;
      numsLessThan++;
    }

    // mere se pehle numbers ko ans me add kro
    else {
      i++;
      ans += numsLessThan;
    }
  }

  while (i <= mid) {
    ans += numsLessThan;
    i++;
  }

  // array ko merge krke sorted state me upar bhejo
  mergeArray(nums, s, e, ans);
}

//  Time: O(N*Logn) Space: O(N) MErge Sort based soln
int reversePairs(vector<int>& nums) {

  int n = nums.size(), ans = 0;

  mergeSort(nums, 0, n - 1, ans);

  return ans;
}