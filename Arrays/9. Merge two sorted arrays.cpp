
//  Time: O(M+N) Space: O(M+N) Simple MErging using extra space
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

  vector<int> temp(m + n);
  int i = 0, j = 0, k = 0;

  while (i < m and j < n) {
    if (nums1[i] < nums2[j]) {
      temp[k++] = nums1[i++];
    }

    else temp[k++] = nums2[j++];
  }

  while (i < m) temp[k++] = nums1[i++];
  while (j < n) temp[k++] = nums2[j++];

  for (int i = 0; i < (m + n); i++) {
    nums1[i] = temp[i];
  }

}

// ------------------------------------------------------------------------

// 1 2 3 0 0 0
//  Time: O(M+N) Space: O(1) Simple MErging using 2 pointers
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

  int i = m - 1, j = n - 1, k = m + n - 1;

  while (i >= 0 and j >= 0) {

    if (nums1[i] > nums2[j]) {
      nums1[k--] = nums1[i--];
    }

    else nums1[k--] = nums2[j--];
  }

  while (i >= 0) nums1[k--] = nums1[i--];
  while (j >= 0) nums1[k--] = nums2[j--];


}

// -----------------------------------------------------------------------------

// gfg ques  - merge inplace

//  Time: O(N*Logn + M*Logn) Space: O(1) using 2 pointers
void merge(long long arr1[], long long arr2[], int n, int m)
{

// Last element of arr1 and first element of arr2
  int idx1 = n - 1, idx2 = 0;

  while (idx1 >= 0 and idx2 < m) {

//  If arr2 starting elements can go inside arr1
    if (arr1[idx1] > arr2[idx2]) {
      swap(arr1[idx1], arr2[idx2]);
      idx1--; idx2++;
    }
    else break;

  }

  sort(arr1, arr1 + n);
  sort(arr2, arr2 + m);
}

// ----------------------------------------------------------------------------------

//  Time: O((M+N)(log(m+n))) Space: O(1) Inplace merging using shell sort gap method
void merge(long long arr1[], long long arr2[], int n, int m)
{
  int k = n + m;

  for (int gap = k / 2; gap >= 1; gap /= 2) {

    int i = 0;
    while ((i + gap) < n) {
      if (arr1[i] > arr1[i + gap]) swap(arr1[i], arr1[i + gap]);
      i += gap;
    }

    if ((i + gap) >= k) continue;

    int j = (i + gap) % n;
    if (j<m and  arr1[i] > arr2[j]) swap(arr1[i], arr2[j]);

    while ((j + gap) < m) {
      if (arr2[j] > arr2[j + gap]) swap(arr2[j], arr2[j + gap]);
      j += gap;
    }

  }
}