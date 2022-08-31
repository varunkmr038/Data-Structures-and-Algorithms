


//  Time: O(N*Logn) Space: O(N) Using min heap
int findKthLargest(vector<int>& nums, int k) {

  int n = nums.size();

  priority_queue<int, vector<int>, greater<int>> pq;

  for (int i = 0; i < k; i++)pq.push(nums[i]);

  for (int i = k; i < n; i++) {
    pq.push(nums[i]);
    pq.pop();
  }


  return pq.top();
}


// -------------------------------------------------------------------------------


int findKthLargest(vector<int>& nums, int k) {

  int n = nums.size();

  shuffle(nums, n);

  return quicksort(nums, k, 0, n - 1, n);

}

int partition(vector<int>& nums, int s, int e) {

  int i = s - 1, pivot = nums[e];


  for (int j = s; j < e; j++) {

    if (nums[j] <= pivot) {
      i++;
      swap(nums[i], nums[j]);
    }

  }

  swap(nums[e], nums[i + 1]);
  return i + 1;

}


int quicksort(vector<int>& nums, int k, int s, int e, int n) {

  if (s >= e) return nums[s];

  int pivotidx = partition(nums, s, e);

  if (pivotidx == n - k) return nums[pivotidx];

  if (pivotidx > n - k) return quicksort(nums, k, s, pivotidx - 1, n);
  else  return quicksort(nums, k, pivotidx + 1, e, n);

}

void shuffle(vector<int>& nums, int n) {

  srand(time(NULL));

  for (int i = n - 1; i >= 0; i--) {
    int idx = rand() % n;
    swap(nums[i], nums[idx]);
  }

}
